#pragma once

#include "map"
#include "optional"
#include "svg.h"
#include "descriptions.h"
#include "json.h"
#include "set"
#include "transport_router.h"
#include "memory"
#include "transport_renderer.pb.h"

namespace Renderer {

    struct RenderProps {
        double width{};
        double height{};
        double padding{};
        double stop_radius{};
        double line_width{};
        double outer_margin{};
        double underlayer_width{};
        double company_radius{};
        double company_line_width{};

        int stop_label_font_size{};
        int bus_label_font_size{};

        Svg::Point stop_label_offset{};
        Svg::Point bus_label_offset{};

        Svg::Color underlayer_color{};

        std::vector<Svg::Color> color_palette;

        std::vector<std::string> layers;

        void Serialize(Serialization::RenderProps &serializedProps) const;

        static RenderProps Deserialize(const Serialization::RenderProps &serializedProps);
    };

    enum class LayerType {
        BUS_LINES,
        BUS_LABELS,
        STOP_POINTS,
        STOP_LABELS,
        COMPANY_LINES,
        COMPANY_POINTS,
        COMPANY_LABELS
    };

    static const std::unordered_map<std::string, LayerType> layer_types = {
            {"bus_lines",      LayerType::BUS_LINES},
            {"bus_labels",     LayerType::BUS_LABELS},
            {"stop_points",    LayerType::STOP_POINTS},
            {"stop_labels",    LayerType::STOP_LABELS},
            {"company_lines",  LayerType::COMPANY_LINES},
            {"company_points", LayerType::COMPANY_POINTS},
            {"company_labels", LayerType::COMPANY_LABELS},
    };

    class TransportRenderer {
    private:
        /**
         * Properties of the Svg map
         */
        RenderProps render_props;
        /**
         * Bus name to bus std::map
         */
        Descriptions::BusesDict buses_dict;

        std::unique_ptr<DB::CompaniesDict> companiesDict;
        /**
         * Maps bus name to the color of the bus label and bus line
         */
        std::unordered_map<std::string, Svg::Color> bus_name_to_color;
        /**
         * Maps stop name to its position on the map, need std::map instead of
         * std::unordered_map because stops need to be rendered in alphabetical order
         */
        std::map<std::string, Svg::Point> stop_to_point;
        std::unordered_map<std::string, Svg::Point> company_to_point;

        void BuildStopsCompaniesCoordinates(
                const Descriptions::StopsDict &stops_dict,
                const RenderProps &render_props,
                const Descriptions::BusesDict &buses_dict,
                const DB::CompaniesDict &companiesDict
                );

    public:

        static TransportRenderer Deserialize(const Serialization::TransportRenderer &serializedRenderer);

        void Serialize(Serialization::TransportRenderer &serializedRenderer) const;

        TransportRenderer() = default;

        TransportRenderer(
                const Descriptions::StopsDict &stops_dict,
                Descriptions::BusesDict buses_dict,
                const DB::CompaniesDict &companiesDict_,
                const Json::Dict &attrs
        );

        [[nodiscard]] Svg::Document RenderSvgMap() const;

        std::string RenderRoute(
                const TransportRouter::RouteInfo &routeInfo,
                Svg::Document initial_map
        ) const;

        std::string RenderRouteToCompany(
                const TransportRouter::RouteInfo &routeInfo,
                Svg::Document initial_map
        ) const;

    private:

        void RenderBusName(Svg::Document &svg, const std::string &bus_name, const std::string &stop_name) const;

        [[nodiscard]] LayerType FromString(const std::string &layer) const;

        void RenderLayer(LayerType type, Svg::Document &svg) const;

        void RenderBusRouteLayer(
                LayerType type,
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderTransparentRect(Svg::Document &svg) const;

        void RenderRouteBusLines(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderRouteBusNames(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderRouteStops(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderRouteStopsNames(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        // В случае, когда маршрут не содержит элементов RideBus и WaitBus,
        // слой stop_labels должен содержать название одной остановки — той,
        // от которой проложен маршрут.
        void RenderRouteToCompanyLayer(
                LayerType type,
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderCompanyLines(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderCompanyPoints(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderCompanyLabels(
                Svg::Document &svg,
                const TransportRouter::RouteInfo &routeInfo
        ) const;

        void RenderStops(Svg::Document &svg) const;

        void RenderStopsNames(Svg::Document &svg) const;

        void RenderBusRoutes(Svg::Document &svg) const;

        void RenderBusNames(Svg::Document &svg) const;

        static const std::unordered_map<std::string,
                void (TransportRenderer::*)(Svg::Document &, const TransportRouter::RouteInfo &) const
        > ROUTE_TO_COMPANY_LAYER_ACTIONS;
    };

}























