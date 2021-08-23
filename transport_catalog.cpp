#include "transport_catalog.h"

#include <sstream>
#include "algorithm"
#include "utility"

using namespace std;

TransportCatalog::TransportCatalog(
        vector<Descriptions::InputQuery> data,
        const Json::Dict &routing_settings_json,
        const Json::Dict &render_settings_json,
        const Json::Dict &yellow_pages_json
) : companiesDatabase(std::make_unique<DB::CompaniesDatabase>(yellow_pages_json)) {

    auto stops_end = partition(begin(data), end(data), [](const auto &item) {
        return holds_alternative<Descriptions::Stop>(item);
    });

    Descriptions::StopsDict stops_dict;
    for (const auto &item : Range{begin(data), stops_end}) {
        const auto &stop = get<Descriptions::Stop>(item);
        stops_dict.insert({stop.name, make_shared<Descriptions::Stop>(stop)});
        stops_.insert({stop.name, {}});
    }

    Descriptions::BusesDict buses_dict;
    for (const auto &item : Range{stops_end, end(data)}) {
        const auto &bus = get<Descriptions::Bus>(item);
        // add bus_name to the set to be able to retrieve it in sorted order
        buses_dict.insert({bus.name, make_shared<Descriptions::Bus>(bus)});
        buses_[bus.name] = Bus{
                bus.stops.size(),
                ComputeUniqueItemsCount(AsRange(bus.stops)),
                ComputeRoadRouteLength(bus.stops, stops_dict),
                ComputeGeoRouteDistance(bus.stops, stops_dict)
        };
        for (const string &stop_name : bus.stops) {
            stops_.at(stop_name).bus_names.insert(bus.name);
        }
    }

    router_ = make_unique<TransportRouter>(
            stops_dict,
            buses_dict,
            routing_settings_json,
            companiesDatabase->GetCompaniesDict());

    renderer_ = Renderer::TransportRenderer(stops_dict, move(buses_dict), companiesDatabase->GetCompaniesDict(),
                                            render_settings_json);
    svg_map = renderer_.RenderSvgMap();

}


const TransportCatalog::Stop *TransportCatalog::GetStop(const string &name) const {
    return GetValuePointer(stops_, name);
}

const TransportCatalog::Bus *TransportCatalog::GetBus(const string &name) const {
    return GetValuePointer(buses_, name);
}

optional<TransportRouter::RouteInfo> TransportCatalog::FindRoute(const string &stop_from, const string &stop_to) const {
    return router_->FindRoute(stop_from, stop_to);
}

int TransportCatalog::ComputeRoadRouteLength(
        const vector<string> &stops,
        const Descriptions::StopsDict &stops_dict
) {
    int result = 0;
    for (size_t i = 1; i < stops.size(); ++i) {
        result += Descriptions::ComputeStopsDistance(*stops_dict.at(stops[i - 1]), *stops_dict.at(stops[i]));
    }
    return result;
}

double TransportCatalog::ComputeGeoRouteDistance(
        const vector<string> &stops,
        const Descriptions::StopsDict &stops_dict
) {
    double result = 0;
    for (size_t i = 1; i < stops.size(); ++i) {
        result += Sphere::Distance(
                stops_dict.at(stops[i - 1])->position, stops_dict.at(stops[i])->position
        );
    }
    return result;
}

std::string TransportCatalog::RenderBusRoute(const TransportRouter::RouteInfo &routeInfo) const {
    return renderer_.RenderRoute(routeInfo, svg_map);
}

std::string TransportCatalog::RenderMap() const {
    ostringstream out;
    svg_map.Render(out);
    return out.str();
}

std::string TransportCatalog::Serialize() const {
    Serialization::TransportCatalog db_proto;
    for (const auto&[name, stop] : stops_) {
        Serialization::SerializedStops &serializedStop = *db_proto.add_stops();
        serializedStop.set_stopname(name);
        for (const string &bus_name : stop.bus_names) {
            serializedStop.add_busnames(bus_name);
        }
    }

    for (const auto&[name, bus] : buses_) {
        Serialization::SerializedBuses &serializedBus = *db_proto.add_buses();
        serializedBus.set_busname(name);
        serializedBus.set_stopcount(bus.stop_count);
        serializedBus.set_uniquestopcount(bus.unique_stop_count);
        serializedBus.set_roadroutelength(bus.road_route_length);
        serializedBus.set_georoutelength(bus.geo_route_length);
    }
    router_->Serialize(*db_proto.mutable_router());
    renderer_.Serialize(*db_proto.mutable_renderer());
    companiesDatabase->Serialize(*db_proto.mutable_database());
    return db_proto.SerializeAsString();
}

TransportCatalog TransportCatalog::Deserialize(const std::string &data) {
    Serialization::TransportCatalog serializedCat;

    assert(serializedCat.ParseFromString(data));

    TransportCatalog catalog;

    for (const Serialization::SerializedStops &serializedStop : serializedCat.stops()) {

        TransportCatalog::Stop &stop = catalog.stops_[serializedStop.stopname()];
        for (const std::string &bus_name : serializedStop.busnames()) {
            stop.bus_names.insert(bus_name);
        }
    }

    for (const Serialization::SerializedBuses &serializedBus : serializedCat.buses()) {
        TransportCatalog::Bus &bus = catalog.buses_[serializedBus.busname()];
        bus.stop_count = serializedBus.stopcount();
        bus.unique_stop_count = serializedBus.uniquestopcount();
        bus.road_route_length = serializedBus.roadroutelength();
        bus.geo_route_length = serializedBus.georoutelength();
    }

    catalog.router_ = TransportRouter::Deserialize(serializedCat.router());
    catalog.renderer_ = Renderer::TransportRenderer::Deserialize(serializedCat.renderer());
    catalog.companiesDatabase = std::make_unique<DB::CompaniesDatabase>(std::move(*serializedCat.mutable_database()));
    catalog.companiesDatabase->BuildWorkingTimeIndices();
    catalog.svg_map = catalog.renderer_.RenderSvgMap();
    return catalog;
}

std::vector<DB::CompanyResponse> TransportCatalog::FindCompanies(const DB::CompanyQuery &query) const {
    return companiesDatabase->FindCompanies(query);
}

std::string TransportCatalog::RenderRouteToCompany(const TransportRouter::RouteInfo &routeInfo) const {
    return renderer_.RenderRouteToCompany(routeInfo, svg_map);
}

std::optional<TransportRouter::RouteInfo>
TransportCatalog::FindRouteToCompany(const std::string &stopFrom, const DB::CompanyQuery &companyQuery) const {
    const auto &candidateCompanies = companiesDatabase->FindCompanies(companyQuery);
    if (candidateCompanies.empty()) {
        return std::nullopt;
    }

    std::optional<TransportRouter::RouteInfo> result;
    auto minTime = std::numeric_limits<double>::max();
    for (const auto &comp : candidateCompanies) {
        auto route = router_->FindRouteToCompany(stopFrom, comp);
        if (!route) {
            continue;
        }
        // skip route with too large total time
        if (route->total_time > minTime) {
            continue;
        }
        // compute wait time for the company
        double waitTime = companiesDatabase->GetWaitTime(comp, companyQuery.datetime, route->total_time);
        if (waitTime > 0) {
            route->total_time += waitTime;
            route->items.emplace_back(TransportRouter::RouteInfo::WaitCompanyItem{
                    .time = waitTime, .company = comp.companyDescription
            });
        }

        if (route->total_time < minTime) {
            result = std::move(route);
            minTime = result->total_time;
        }
    }
    return result;
}










