#pragma once

#include "descriptions.h"
#include "graph.h"
#include "json.h"
#include "router.h"

#include <memory>
#include <unordered_map>
#include <vector>
#include "transport_router.pb.h"
#include "companies_components.h"

class TransportRouter {
public:
    using BusGraph = Graph::DirectedWeightedGraph<double>;
    using Router = Graph::Router<double>;

public:
    TransportRouter(const Descriptions::StopsDict &stops_dict,
                    const Descriptions::BusesDict &buses_dict,
                    const Json::Dict &routing_settings_json,
                    const DB::CompaniesDict &companiesDict);


    TransportRouter(const Descriptions::StopsDict &stops_dict,
                    const Descriptions::BusesDict &buses_dict,
                    const DB::CompaniesDict &companiesDict,
                    int wait_time, double velocity, double pedestrianVelocity);

    void Serialize(Serialization::TransportRouter &serializedTransportRouter) const;

    static std::unique_ptr<TransportRouter>
    Deserialize(const Serialization::TransportRouter &serializedTransportRouter);


    struct RouteInfo {
        double total_time;

        struct RideBusItem {
            std::string bus_name;
            double time;
            size_t span_count;
            size_t start_stop_index;
            size_t end_stop_index;
        };
        struct WaitBusItem {
            std::string stop_name;
            double time;
        };

        struct WalkToCompanyItem {
            std::string company;
            std::string stop_name;
            double time;
        };

        struct WaitCompanyItem {
            double time;
            std::string company;
        };

        using Item = std::variant<RideBusItem, WaitBusItem, WalkToCompanyItem, WaitCompanyItem>;
        std::vector<Item> items;
    };

    std::optional<RouteInfo> FindRoute(const std::string &stop_from, const std::string &stop_to) const;

    std::optional<RouteInfo> FindRouteToCompany(
            const std::string &stop_from,
            const DB::CompanyResponse &displayCompany
    ) const;


public:
    struct RoutingSettings {
        int bus_wait_time;  // in minutes
        double bus_velocity;  // km/h
        double pedestrian_velocity;
    };

private:

    TransportRouter() = default;

    static RoutingSettings MakeRoutingSettings(const Json::Dict &json);

    void FillGraphWithStopsAndCompanies(
            const Descriptions::StopsDict &stops_dict,
            const DB::CompaniesDict &companiesDict
    );

    void FillGraphWithBuses(const Descriptions::StopsDict &stops_dict,
                            const Descriptions::BusesDict &buses_dict);


public:
    struct StopVertexIds {
        Graph::VertexId in;
        Graph::VertexId out;
    };

    using StopToVertexIdMap = std::unordered_map<std::string, StopVertexIds>;

    struct VertexInfo {
        std::string vertexName;
    };

    struct BusEdgeInfo {
        std::string bus_name;
        size_t span_count;
        size_t start_stop_index;
        size_t end_stop_index;
    };
    struct WaitEdgeInfo {
    };

    struct WalkEdgeInfo {
        std::string company_name;
        std::string company_display_name;
        std::string stop_name;
    };
    using EdgeInfo = std::variant<BusEdgeInfo, WaitEdgeInfo, WalkEdgeInfo>;

private:
    RoutingSettings routing_settings_;
    BusGraph graph_;
    std::unique_ptr<Router> router_;
    StopToVertexIdMap stops_vertex_ids_;
    std::vector<VertexInfo> vertices_info_;
    std::vector<EdgeInfo> edges_info_;
    std::unordered_map<std::string, Graph::VertexId> companies_vertices_;
};
