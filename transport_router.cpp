#include "transport_router.h"

using namespace std;


TransportRouter::TransportRouter(const Descriptions::StopsDict &stops_dict,
                                 const Descriptions::BusesDict &buses_dict,
                                 const Json::Dict &routing_settings_json,
                                 const DB::CompaniesDict &companiesDict
)
        : routing_settings_(MakeRoutingSettings(routing_settings_json)) {
    const size_t vertex_count = stops_dict.size() * 2 + companiesDict.size();
    vertices_info_.resize(vertex_count);
    graph_ = BusGraph(vertex_count);

    FillGraphWithStopsAndCompanies(stops_dict, companiesDict);
    FillGraphWithBuses(stops_dict, buses_dict);

    router_ = std::make_unique<Router>(graph_);
}

TransportRouter::TransportRouter(const Descriptions::StopsDict &stops_dict,
                                 const Descriptions::BusesDict &buses_dict,
                                 const DB::CompaniesDict &companiesDict,
                                 int wait_time, double velocity, double pedestrianVelocity)
        : routing_settings_({wait_time, velocity, pedestrianVelocity}) {
    const size_t vertex_count = stops_dict.size() * 2 + companiesDict.size();
    vertices_info_.resize(vertex_count);
    graph_ = BusGraph(vertex_count);

    FillGraphWithStopsAndCompanies(stops_dict, companiesDict);
    FillGraphWithBuses(stops_dict, buses_dict);

    router_ = std::make_unique<Router>(graph_);
}


TransportRouter::RoutingSettings TransportRouter::MakeRoutingSettings(const Json::Dict &json) {
    return {
            json.at("bus_wait_time").AsInt(),
            json.at("bus_velocity").AsDouble(),
            json.at("pedestrian_velocity").AsDouble()
    };
}

void TransportRouter::FillGraphWithStopsAndCompanies(
        const Descriptions::StopsDict &stops_dict,
        const DB::CompaniesDict &companiesDict
) {
    Graph::VertexId vertex_id = 0;

    for (const auto&[stop_name, _] : stops_dict) {
        auto &vertex_ids = stops_vertex_ids_[stop_name];
        vertex_ids.in = vertex_id++;
        vertex_ids.out = vertex_id++;
        vertices_info_[vertex_ids.in] = {stop_name};
        vertices_info_[vertex_ids.out] = {stop_name};

        edges_info_.push_back(WaitEdgeInfo{});
        graph_.AddEdge({
                               vertex_ids.out,
                               vertex_ids.in,
                               static_cast<double>(routing_settings_.bus_wait_time)
                       });
    }
    for (const auto&[companyName, companyPtr] : companiesDict) {
        // save info about company name and vertexId
        companies_vertices_[companyName] = vertex_id;
        vertices_info_[vertex_id] = {companyName};
        // add edges (all routes from company to nearby stops)
        for (const auto &nearbyStop : companyPtr.nearbyStops) {
            const auto stopVertexId = stops_vertex_ids_[nearbyStop.name].out;
            edges_info_.push_back(WalkEdgeInfo{
                    .company_name = companyPtr.mainName,
                    .company_display_name = companyPtr.displayName,
                    .stop_name = nearbyStop.name
            });
            graph_.AddEdge(
                    {
                            stopVertexId,
                            vertex_id,
                            nearbyStop.meters * 1.0 / (routing_settings_.pedestrian_velocity * 1000.0 / 60)
                    }
            );
        }
        ++vertex_id;
    }
    assert(vertex_id == graph_.GetVertexCount());
}

void TransportRouter::FillGraphWithBuses(const Descriptions::StopsDict &stops_dict,
                                         const Descriptions::BusesDict &buses_dict) {
    for (const auto&[_, bus_item] : buses_dict) {
        const auto &bus = *bus_item;
        const size_t stop_count = bus.stops.size();
        if (stop_count <= 1) {
            continue;
        }
        auto compute_distance_from = [&stops_dict, &bus](size_t lhs_idx) {
            return Descriptions::ComputeStopsDistance(*stops_dict.at(bus.stops[lhs_idx]),
                                                      *stops_dict.at(bus.stops[lhs_idx + 1]));
        };
        for (size_t start_stop_idx = 0; start_stop_idx + 1 < stop_count; ++start_stop_idx) {
            const Graph::VertexId start_vertex = stops_vertex_ids_[bus.stops[start_stop_idx]].in;
            int total_distance = 0;
            for (size_t finish_stop_idx = start_stop_idx + 1; finish_stop_idx < stop_count; ++finish_stop_idx) {
                total_distance += compute_distance_from(finish_stop_idx - 1);
                // add all stops on the route to the BusEdgeInfo structure
                edges_info_.push_back(BusEdgeInfo{
                        .bus_name = bus.name,
                        .span_count = finish_stop_idx - start_stop_idx,
                        .start_stop_index = start_stop_idx,
                        .end_stop_index = finish_stop_idx
                });

                graph_.AddEdge({
                                       start_vertex,
                                       stops_vertex_ids_[bus.stops[finish_stop_idx]].out,
                                       total_distance * 1.0 /
                                       (routing_settings_.bus_velocity * 1000.0 / 60)  // m / (km/h * 1000 / 60) = min
                               });
            }
        }
    }
}

optional<TransportRouter::RouteInfo> TransportRouter::FindRoute(const string &stop_from, const string &stop_to) const {
    const Graph::VertexId vertex_from = stops_vertex_ids_.at(stop_from).out;
    const Graph::VertexId vertex_to = stops_vertex_ids_.at(stop_to).out;
    const auto route = router_->BuildRoute(vertex_from, vertex_to);
    if (!route) {
        return nullopt;
    }

    RouteInfo route_info = {.total_time = route->weight};
    route_info.items.reserve(route->edge_count);
    for (size_t edge_idx = 0; edge_idx < route->edge_count; ++edge_idx) {
        const Graph::EdgeId edge_id = router_->GetRouteEdge(route->id, edge_idx);
        const auto &edge = graph_.GetEdge(edge_id);
        const auto &edge_info = edges_info_[edge_id];
        if (holds_alternative<BusEdgeInfo>(edge_info)) {
            const BusEdgeInfo &bus_edge_info = get<BusEdgeInfo>(edge_info);
            route_info.items.emplace_back(RouteInfo::RideBusItem{
                    .bus_name = bus_edge_info.bus_name,
                    .time = edge.weight,
                    .span_count = bus_edge_info.span_count,
                    .start_stop_index = bus_edge_info.start_stop_index,
                    .end_stop_index = bus_edge_info.end_stop_index
            });
        } else {
            const Graph::VertexId vertex_id = edge.from;
            route_info.items.emplace_back(RouteInfo::WaitBusItem{
                    .stop_name = vertices_info_[vertex_id].vertexName,
                    .time = edge.weight,
            });
        }
    }

    // Releasing in destructor of some proxy object would be better,
    // but we do not expect exceptions in normal workflow
    router_->ReleaseRoute(route->id);
    return route_info;
}

std::optional<TransportRouter::RouteInfo>
TransportRouter::FindRouteToCompany(const std::string &stop_from, const DB::CompanyResponse &companyResponse) const {
    const Graph::VertexId vertex_from = stops_vertex_ids_.at(stop_from).out;
    const Graph::VertexId vertex_to = companies_vertices_.at(companyResponse.companyDescription);
    const auto route = router_->BuildRoute(vertex_from, vertex_to);
    if (!route) {
        return nullopt;
    }

    RouteInfo route_info = {.total_time = route->weight};
    route_info.items.reserve(route->edge_count);
    for (size_t edge_idx = 0; edge_idx < route->edge_count; ++edge_idx) {
        const Graph::EdgeId edge_id = router_->GetRouteEdge(route->id, edge_idx);
        const auto &edge = graph_.GetEdge(edge_id);
        const auto &edge_info = edges_info_[edge_id];
        if (holds_alternative<BusEdgeInfo>(edge_info)) {
            const BusEdgeInfo &bus_edge_info = get<BusEdgeInfo>(edge_info);
            route_info.items.emplace_back(RouteInfo::RideBusItem{
                    .bus_name = bus_edge_info.bus_name,
                    .time = edge.weight,
                    .span_count = bus_edge_info.span_count,
                    .start_stop_index = bus_edge_info.start_stop_index,
                    .end_stop_index = bus_edge_info.end_stop_index
            });
        } else if (holds_alternative<WalkEdgeInfo>(edge_info)) {
            const WalkEdgeInfo &walkEdgeInfo = get<WalkEdgeInfo>(edge_info);
            route_info.items.emplace_back(RouteInfo::WalkToCompanyItem{
                    .company = walkEdgeInfo.company_name,
                    .stop_name = walkEdgeInfo.stop_name,
                    .time = edge.weight
            });
        } else {
            const Graph::VertexId vertex_id = edge.from;
            route_info.items.emplace_back(RouteInfo::WaitBusItem{
                    .stop_name = vertices_info_[vertex_id].vertexName,
                    .time = edge.weight,
            });
        }
    }
    // Releasing in destructor of some proxy object would be better,
    // but we do not expect exceptions in normal workflow
    router_->ReleaseRoute(route->id);
    return route_info;
}

void SerializeRoutingSettings(Serialization::SerializedRoutingSettings &serializedSettings,
                              const TransportRouter::RoutingSettings &settings) {
    serializedSettings.set_buswaittime(settings.bus_wait_time);
    serializedSettings.set_busvelocity(settings.bus_velocity);
    serializedSettings.set_pedestrianvelocity(settings.pedestrian_velocity);
}

void SerializeEdgesInfo(Serialization::TransportRouter &serializedTransportRouter,
                        const std::vector<TransportRouter::EdgeInfo> &edgesInfo) {

    for (const auto &edge : edgesInfo) {
        auto &serializedEdge = *serializedTransportRouter.add_edgesinfo();
        if (holds_alternative<TransportRouter::BusEdgeInfo>(edge)) {
            const auto &busEdge = get<TransportRouter::BusEdgeInfo>(edge);
            auto &serializedBusEdge = *serializedEdge.mutable_busedgeinfo();
            serializedBusEdge.set_name(busEdge.bus_name);
            serializedBusEdge.set_spancount(busEdge.span_count);
            serializedBusEdge.set_startstopindex(busEdge.start_stop_index);
            serializedBusEdge.set_endstopindex(busEdge.end_stop_index);
        } else if (holds_alternative<TransportRouter::WalkEdgeInfo>(edge)) {
            const auto &walkEdge = get<TransportRouter::WalkEdgeInfo>(edge);
            auto &serializedWalkEdge = *serializedEdge.mutable_walkedgeinfo();
            serializedWalkEdge.set_stopname(walkEdge.stop_name);
            serializedWalkEdge.set_companyname(walkEdge.company_name);
            serializedWalkEdge.set_companydisplayname(walkEdge.company_display_name);
        } else {
            serializedEdge.mutable_waitedgeinfo();
        }
    }
}

void SerializeVerticesInfo(Serialization::TransportRouter &serializedTransportRouter,
                           const std::vector<TransportRouter::VertexInfo> &verticesInfo) {

    for (const auto &vInfo : verticesInfo) {
        auto &value = *serializedTransportRouter.add_verticesinfo();
        value.set_stopname(vInfo.vertexName);
    }

}

void SerializeStopVertexIds(Serialization::TransportRouter &serializedTransportRouter,
                            const TransportRouter::StopToVertexIdMap &stopToVertexIdMap) {
    // unordered_map<string, <size_t - in, size_t - out>>;
    for (const auto&[stop_name, vertexId] : stopToVertexIdMap) {
        auto &serializedId = *serializedTransportRouter.add_stopvertexids();
        serializedId.set_name(stop_name);
        serializedId.set_in(vertexId.in);
        serializedId.set_out(vertexId.out);
    }
}

void SerializeCompaniesVertices(Serialization::TransportRouter &serializedTransportRouter,
                                const std::unordered_map<std::string, Graph::VertexId> &companies_vertices) {
    for (const auto&[companyName, vertexId] : companies_vertices) {
        auto &serializedCompanyVertex = *serializedTransportRouter.add_companiesvertices();
        serializedCompanyVertex.set_companyname(companyName);
        serializedCompanyVertex.set_vertexid(vertexId);
    }
}

void TransportRouter::Serialize(Serialization::TransportRouter &serializedTransportRouter) const {
    // settings
    SerializeRoutingSettings(*serializedTransportRouter.mutable_routingsettings(),
                             routing_settings_
    );
    // graph
    graph_.Serialize(*serializedTransportRouter.mutable_graph());
    // router
    router_->Serialize(*serializedTransportRouter.mutable_router());
    // stopVertexIds
    SerializeStopVertexIds(serializedTransportRouter, stops_vertex_ids_);
    // vertices info
    SerializeVerticesInfo(serializedTransportRouter, vertices_info_);
    // edges info
    SerializeEdgesInfo(serializedTransportRouter, edges_info_);
    // companies vertices
    SerializeCompaniesVertices(serializedTransportRouter, companies_vertices_);
}


std::unique_ptr<TransportRouter>
TransportRouter::Deserialize(const Serialization::TransportRouter &serializedTransportRouter) {
    // must use new instead of make_unique because of private default constructor
    std::unique_ptr<TransportRouter> routerPtr(new TransportRouter);
    TransportRouter &router = *routerPtr;

    auto &settings = router.routing_settings_;
    settings.bus_wait_time = serializedTransportRouter.routingsettings().buswaittime();
    settings.bus_velocity = serializedTransportRouter.routingsettings().busvelocity();
    settings.pedestrian_velocity = serializedTransportRouter.routingsettings().pedestrianvelocity();

    router.graph_ = BusGraph::Deserialize(serializedTransportRouter.graph());
    router.router_ = Router::Deserialize(serializedTransportRouter.router(), router.graph_);

    router.stops_vertex_ids_.reserve(serializedTransportRouter.stopvertexids_size());
    for (const auto &serializedStopVertex: serializedTransportRouter.stopvertexids()) {
        router.stops_vertex_ids_[serializedStopVertex.name()] =
                TransportRouter::StopVertexIds{
                        .in = serializedStopVertex.in(),
                        .out = serializedStopVertex.out()
                };
    }

    router.vertices_info_.reserve(serializedTransportRouter.verticesinfo_size());
    for (const auto &serializedVertex : serializedTransportRouter.verticesinfo()) {
        router.vertices_info_.emplace_back(TransportRouter::VertexInfo{
                serializedVertex.stopname()
        });
    }

    router.edges_info_.reserve(serializedTransportRouter.edgesinfo_size());
    for (const auto &serializedEdge : serializedTransportRouter.edgesinfo()) {
        if (serializedEdge.has_busedgeinfo()) {
            const auto &busInfo = serializedEdge.busedgeinfo();
            router.edges_info_.emplace_back(
                    TransportRouter::BusEdgeInfo{
                            busInfo.name(),
                            busInfo.spancount(),
                            busInfo.startstopindex(),
                            busInfo.endstopindex()
                    }
            );
        } else if (serializedEdge.has_walkedgeinfo()) {
            const auto &walkInfo = serializedEdge.walkedgeinfo();
            router.edges_info_.emplace_back(TransportRouter::WalkEdgeInfo{
                    walkInfo.companyname(),
                    walkInfo.companydisplayname(),
                    walkInfo.stopname()
            });
        } else {
            router.edges_info_.emplace_back(
                    TransportRouter::WaitEdgeInfo{}
            );
        }
    }
    router.companies_vertices_.reserve(serializedTransportRouter.companiesvertices_size());
    for (const auto &serializedCompanyVertex : serializedTransportRouter.companiesvertices()) {
        router.companies_vertices_[serializedCompanyVertex.companyname()] = serializedCompanyVertex.vertexid();
    }

    return routerPtr;
}
