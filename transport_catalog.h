#pragma once

#include "descriptions.h"
#include "json.h"
#include "transport_router.h"
#include "utils.h"
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include "svg.h"
#include "map"
#include "transport_renderer.h"
#include "transport_catalog.pb.h"
#include "companies_database.h"

namespace Responses {
    struct Stop {
        std::set<std::string> bus_names;
    };

    struct Bus {
        size_t stop_count = 0;
        size_t unique_stop_count = 0;
        int road_route_length = 0;
        double geo_route_length = 0.0;
    };
}

class TransportCatalog {
public:
    using Bus = Responses::Bus;
    using Stop = Responses::Stop;

public:
    static TransportCatalog Deserialize(const std::string &data);

    [[nodiscard]] std::string Serialize() const;

    TransportCatalog(
            std::vector<Descriptions::InputQuery> data,
            const Json::Dict &routing_settings_json,
            const Json::Dict &render_settings_json,
            const Json::Dict &yellow_pages_json
    );

    const Stop *GetStop(const std::string &name) const;

    const Bus *GetBus(const std::string &name) const;

    std::optional<TransportRouter::RouteInfo> FindRoute(const std::string &stop_from, const std::string &stop_to) const;

    std::string RenderMap() const;

    std::string RenderBusRoute(const TransportRouter::RouteInfo &routeInfo) const;

    std::vector<DB::CompanyResponse> FindCompanies(const DB::CompanyQuery &query) const;

    std::optional<TransportRouter::RouteInfo> FindRouteToCompany(
            const std::string &stopFrom,
            const DB::CompanyQuery &companyQuery
    ) const;

    std::string RenderRouteToCompany(const TransportRouter::RouteInfo &routeInfo) const;

private:
    TransportCatalog() = default;

    static int ComputeRoadRouteLength(
            const std::vector<std::string> &stops,
            const Descriptions::StopsDict &stops_dict
    );

    static double ComputeGeoRouteDistance(
            const std::vector<std::string> &stops,
            const Descriptions::StopsDict &stops_dict
    );

    Svg::Document svg_map;
    std::unordered_map<std::string, Stop> stops_;
    std::unordered_map<std::string, Bus> buses_;
    std::unique_ptr<TransportRouter> router_;
    Renderer::TransportRenderer renderer_;
    std::unique_ptr<DB::CompaniesDatabase> companiesDatabase;
};
