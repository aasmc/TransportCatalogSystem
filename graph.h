#pragma once

#include "utils.h"

#include <cstdlib>
#include <deque>
#include <vector>
#include "directed_graph.pb.h"

namespace Graph {

    using VertexId = size_t;
    using EdgeId = size_t;

    template<typename Weight>
    struct Edge {
        VertexId from;
        VertexId to;
        Weight weight;
    };

    template<typename Weight>
    class DirectedWeightedGraph {
    public:
        using IncidenceList = std::vector<EdgeId>;
        using IncidentEdgesRange = Range<typename IncidenceList::const_iterator>;

    public:

        DirectedWeightedGraph(size_t vertex_count = 0);

        EdgeId AddEdge(const Edge<Weight> &edge);

        size_t GetVertexCount() const;

        size_t GetEdgeCount() const;

        const Edge<Weight> &GetEdge(EdgeId edge_id) const;

        IncidentEdgesRange GetIncidentEdges(VertexId vertex) const;

        void Serialize(Serialization::DirectedWeightedGraph &serializedGraph) const;

        static DirectedWeightedGraph Deserialize(const Serialization::DirectedWeightedGraph &serializedGraph);

    private:
        std::vector<Edge<Weight>> edges_;
        std::vector<IncidenceList> incidence_lists_;
    };


    template<typename Weight>
    DirectedWeightedGraph<Weight>::DirectedWeightedGraph(size_t vertex_count) : incidence_lists_(vertex_count) {}

    template<typename Weight>
    EdgeId DirectedWeightedGraph<Weight>::AddEdge(const Edge<Weight> &edge) {
        edges_.push_back(edge);
        const EdgeId id = edges_.size() - 1;
        incidence_lists_[edge.from].push_back(id);
        return id;
    }

    template<typename Weight>
    size_t DirectedWeightedGraph<Weight>::GetVertexCount() const {
        return incidence_lists_.size();
    }

    template<typename Weight>
    size_t DirectedWeightedGraph<Weight>::GetEdgeCount() const {
        return edges_.size();
    }

    template<typename Weight>
    const Edge<Weight> &DirectedWeightedGraph<Weight>::GetEdge(EdgeId edge_id) const {
        return edges_[edge_id];
    }

    template<typename Weight>
    typename DirectedWeightedGraph<Weight>::IncidentEdgesRange
    DirectedWeightedGraph<Weight>::GetIncidentEdges(VertexId vertex) const {
        const auto &edges = incidence_lists_[vertex];
        return {std::begin(edges), std::end(edges)};
    }

    template<typename Weight>
    void DirectedWeightedGraph<Weight>::Serialize(Serialization::DirectedWeightedGraph &serializedGraph) const {
        static_assert(std::is_same_v<double, Weight>, "Serialization not supported for values other than double");
        // vector<<size_t - from, size_t = to, double - weight>> edges
        for (const auto &edge: edges_) {
            auto &serializedEdge = *serializedGraph.add_edges();
            serializedEdge.set_vertexfrom(edge.from);
            serializedEdge.set_vertexto(edge.to);
            serializedEdge.set_weight(edge.weight);
        }

        //vector<vector<size_t>> - incidenceList
        for (const auto &list : incidence_lists_) {
            auto &serializedList = *serializedGraph.add_incidencelists();
            for (const auto id : list) {
                serializedList.add_edgeid(id);
            }
        }
    }

    template<typename Weight>
    DirectedWeightedGraph<Weight>
    DirectedWeightedGraph<Weight>::Deserialize(const Serialization::DirectedWeightedGraph &serializedGraph) {
        DirectedWeightedGraph<Weight> graph;
        graph.incidence_lists_.reserve(serializedGraph.incidencelists_size());
        for (const auto &serializedId : serializedGraph.incidencelists()) {
            auto &list = graph.incidence_lists_.emplace_back();
            list.reserve(serializedId.edgeid_size());
            for (const auto id : serializedId.edgeid()) {
                list.push_back(id);
            }
        }

        graph.edges_.reserve(serializedGraph.edges_size());
        for (const auto &serializedEdge: serializedGraph.edges()) {
            auto &edge = graph.edges_.emplace_back();
            edge.from = serializedEdge.vertexfrom();
            edge.to = serializedEdge.vertexto();
            edge.weight = serializedEdge.weight();
        }
        return graph;
    }
}
