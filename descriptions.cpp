#include "descriptions.h"
#include "cmath"
#include "algorithm"

using namespace std;

namespace Descriptions {

    Stop Stop::ParseFrom(const Json::Dict &attrs) {
        Stop stop = {
                .name = attrs.at("name").AsString(),
                .position = {
                        .latitude = attrs.at("latitude").AsDouble(),
                        .longitude = attrs.at("longitude").AsDouble(),
                }
        };
        if (attrs.count("road_distances") > 0) {
            for (const auto&[neighbour_stop, distance_node] : attrs.at("road_distances").AsMap()) {
                stop.distances[neighbour_stop] = distance_node.AsInt();
            }
        }
        return stop;
    }

    vector<string> ParseStops(const vector<Json::Node> &stop_nodes, bool is_roundtrip) {
        vector<string> stops;
        stops.reserve(stop_nodes.size());
        for (const Json::Node &stop_node : stop_nodes) {
            stops.push_back(stop_node.AsString());
        }
        if (is_roundtrip || stops.size() <= 1) {
            return stops;
        }
        stops.reserve(stops.size() * 2 - 1);  // end stop is not repeated
        for (size_t stop_idx = stops.size() - 1; stop_idx > 0; --stop_idx) {
            stops.push_back(stops[stop_idx - 1]);
        }
        return stops;
    }

    int ComputeStopsDistance(const Stop &lhs, const Stop &rhs) {
        if (auto it = lhs.distances.find(rhs.name); it != lhs.distances.end()) {
            return it->second;
        } else {
            return rhs.distances.at(lhs.name);
        }
    }

    std::vector<std::string> ParseEndStops(const std::vector<Json::Node> &stop_nodes, bool is_roundtrip) {
        if (stop_nodes.empty()) {
            return {};
        }
        if (is_roundtrip) {
            return {stop_nodes.front().AsString()};
        } else {
            if (stop_nodes.front().AsString() == stop_nodes.back().AsString()) {
                return {stop_nodes.front().AsString()};
            }
            return {stop_nodes.front().AsString(), stop_nodes.back().AsString()};
        }
    }

    Bus Bus::ParseFrom(const Json::Dict &attrs) {
        return Bus{
                .name = attrs.at("name").AsString(),
                .stops = ParseStops(attrs.at("stops").AsArray(), attrs.at("is_roundtrip").AsBool()),
                .end_stops = ParseEndStops(attrs.at("stops").AsArray(), attrs.at("is_roundtrip").AsBool()),
        };
    }

    void Bus::Serialize(Serialization::BusDescription &serializedBus) const {
        serializedBus.set_name(name);
        for (const auto &stop : stops) {
            serializedBus.add_stops(stop);
        }
        for (const auto &endStop : end_stops) {
            serializedBus.add_endstops(endStop);
        }
    }

    Bus Bus::Deserialize(const Serialization::BusDescription &serializedBus) {
        Bus b;
        b.name = serializedBus.name();
        b.stops.reserve(serializedBus.stops_size());
        for (const auto &stopName : serializedBus.stops()) {
            b.stops.push_back(stopName);
        }

        b.end_stops.reserve(serializedBus.endstops_size());
        for (const auto &stopName : serializedBus.endstops()) {
            b.end_stops.push_back(stopName);
        }
        return b;
    }

    vector<InputQuery> ReadDescriptions(const vector<Json::Node> &nodes) {
        vector<InputQuery> result;
        result.reserve(nodes.size());

        for (const Json::Node &node : nodes) {
            const auto &node_dict = node.AsMap();
            if (node_dict.at("type").AsString() == "Bus") {
                result.push_back(Bus::ParseFrom(node_dict));
            } else {
                result.push_back(Stop::ParseFrom(node_dict));
            }
        }
        return result;
    }
}
