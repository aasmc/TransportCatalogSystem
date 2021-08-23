#include "transport_renderer.h"

#include <utility>
#include "algorithm"
#include "compression.h"
#include "string"
#include "sstream"

using namespace std;

namespace Renderer {

    Svg::Color ReadColorFromJson(const Json::Node &node) {
        if (holds_alternative<string>(node.GetBase())) {
            return node.AsString();
        } else {
            const auto &color_arr = node.AsArray();
            if (color_arr.size() == 3) {
                return Svg::Color{
                        Svg::Rgb{
                                .red = static_cast<uint8_t>(color_arr[0].AsInt()),
                                .green = static_cast<uint8_t>(color_arr[1].AsInt()),
                                .blue = static_cast<uint8_t>(color_arr[2].AsInt())
                        }
                };
            } else {
                return Svg::Color{
                        Svg::Rgba{
                                static_cast<uint8_t>(color_arr[0].AsInt()),
                                static_cast<uint8_t>(color_arr[1].AsInt()),
                                static_cast<uint8_t>(color_arr[2].AsInt()),
                                color_arr[3].AsDouble(),
                        }
                };
            }
        }
    }

    Renderer::RenderProps ReadSvgProps(const Json::Dict &attrs) {
        RenderProps render_props;
        render_props.width = attrs.at("width").AsDouble();
        render_props.height = attrs.at("height").AsDouble();
        render_props.padding = attrs.at("padding").AsDouble();
        render_props.stop_radius = attrs.at("stop_radius").AsDouble();
        render_props.line_width = attrs.at("line_width").AsDouble();
        render_props.outer_margin = attrs.at("outer_margin").AsDouble();
        render_props.company_radius = attrs.at("company_radius").AsDouble();
        render_props.company_line_width = attrs.at("company_line_width").AsDouble();
        render_props.stop_label_font_size = attrs.at("stop_label_font_size").AsInt();
        render_props.stop_label_offset = Svg::Point{
                .x = attrs.at("stop_label_offset").AsArray()[0].AsDouble(),
                .y = attrs.at("stop_label_offset").AsArray()[1].AsDouble()
        };
        render_props.bus_label_font_size = attrs.at("bus_label_font_size").AsInt();
        render_props.bus_label_offset = Svg::Point{
                .x = attrs.at("bus_label_offset").AsArray()[0].AsDouble(),
                .y = attrs.at("bus_label_offset").AsArray()[1].AsDouble(),
        };

        render_props.underlayer_color = ReadColorFromJson(attrs.at("underlayer_color"));
        render_props.underlayer_width = attrs.at("underlayer_width").AsDouble();
        render_props.color_palette.reserve(100);
        for (const auto &node : attrs.at("color_palette").AsArray()) {
            render_props.color_palette.push_back(ReadColorFromJson(node));
        }
        for (const auto &node : attrs.at("layers").AsArray()) {
            render_props.layers.push_back(node.AsString());
        }
        return render_props;
    }

    void TransportRenderer::BuildStopsCompaniesCoordinates(const Descriptions::StopsDict &stops_dict,
                                                           const RenderProps &render_props,
                                                           const Descriptions::BusesDict &buses_dict,
                                                           const DB::CompaniesDict &companiesDict) {

        const auto stopsCoords = Compression::computeInterpolatedStopsGeoCoordinates(stops_dict, buses_dict);

        const auto[neighbourLats, neighbourLons] = Compression::computeNeighboursForCoord(stopsCoords, buses_dict,
                                                                                          companiesDict);

        Compression::CoordsCompressor compressor{stopsCoords, companiesDict};
        compressor.fillIndices(neighbourLats, neighbourLons);
        compressor.fillTargets(render_props.width, render_props.height, render_props.padding);


        for (const auto&[stopName, coord] : stopsCoords) {
            stop_to_point[stopName] = {
                    compressor.mapLon(coord.longitude),
                    compressor.mapLat(coord.latitude)
            };
        }

        for (const auto&[companyName, company] : companiesDict) {
            company_to_point[companyName] = {
                    compressor.mapLon(company.coords.longitude),
                    compressor.mapLat(company.coords.latitude)
            };
        }
    }


    static unordered_map<string, Svg::Color> SelectBusColor(
            const Descriptions::BusesDict &buses_dict,
            const RenderProps &render_props
    ) {
        const auto &palette = render_props.color_palette;
        unordered_map<string, Svg::Color> bus_colors;
        int idx = 0;
        for (const auto&[bus_name, bus_ptr] : buses_dict) {
            bus_colors[bus_name] = palette[idx++ % palette.size()];
        }
        return bus_colors;
    }

    TransportRenderer::TransportRenderer(const Descriptions::StopsDict &stops_dict_,
                                         Descriptions::BusesDict buses_dict_,
                                         const DB::CompaniesDict &companiesDict_,
                                         const Json::Dict &attrs
    ) :
            render_props(ReadSvgProps(attrs)),
            buses_dict(move(buses_dict_)),
            companiesDict(std::make_unique<DB::CompaniesDict>(companiesDict_)),
            bus_name_to_color(SelectBusColor(buses_dict, render_props)) {

        BuildStopsCompaniesCoordinates(
                stops_dict_, render_props, buses_dict, companiesDict_
        );

    }

    void TransportRenderer::RenderStops(Svg::Document &svg) const {
        for (const auto&[stop_name, stop_point] : stop_to_point) {
            svg.Add(Svg::Circle{}
                            .SetCenter(stop_point)
                            .SetRadius(render_props.stop_radius)
                            .SetFillColor("white"));

        }
    }

    void TransportRenderer::RenderStopsNames(Svg::Document &svg) const {
        for (const auto&[stop_name, stop_point] : stop_to_point) {
            Svg::Text text{};
            text.SetPoint(stop_point)
                    .SetFontFamily("Verdana")
                    .SetOffset(render_props.stop_label_offset)
                    .SetFontSize(render_props.stop_label_font_size)
                    .SetData(stop_name);

            Svg::Text underlay = text;
            underlay.SetFillColor(render_props.underlayer_color)
                    .SetStrokeColor(render_props.underlayer_color)
                    .SetStrokeWidth(render_props.underlayer_width)
                    .SetStrokeLineCap("round")
                    .SetStrokeLineJoin("round");

            text.SetFillColor("black");

            svg.Add(underlay);
            svg.Add(text);

        }
    }

    void TransportRenderer::RenderBusRoutes(Svg::Document &svg) const {
        for (const auto &[bus_name, bus] : buses_dict) {
            const auto &stops = bus->stops;
            if (stops.empty()) {
                continue;
            }
            Svg::Polyline polyline;
            polyline.SetStrokeColor(bus_name_to_color.at(bus_name))
                    .SetStrokeLineCap("round")
                    .SetStrokeLineJoin("round")
                    .SetStrokeWidth(render_props.line_width);

            for (const auto &stop_name : stops) {
                polyline.AddPoint(stop_to_point.at(stop_name));
            }
            svg.Add(polyline);
        }
    }

    void TransportRenderer::RenderBusNames(Svg::Document &svg) const {
        for (const auto&[bus_name, bus_ptr] : buses_dict) {
            const auto &stops = bus_ptr->stops;
            if (!stops.empty()) {
                const auto &color = bus_name_to_color.at(bus_name);
                for (const auto &end_stop : bus_ptr->end_stops) {
                    const auto point = stop_to_point.at(end_stop);

                    Svg::Text bus_number;
                    bus_number.SetPoint(point)
                            .SetOffset(render_props.bus_label_offset)
                            .SetFontSize(render_props.bus_label_font_size)
                            .SetFontFamily("Verdana")
                            .SetFontWeight("bold")
                            .SetData(bus_name);

                    Svg::Text underlay = bus_number;
                    underlay.SetFillColor(render_props.underlayer_color)
                            .SetStrokeColor(render_props.underlayer_color)
                            .SetStrokeWidth(render_props.underlayer_width)
                            .SetStrokeLineCap("round")
                            .SetStrokeLineJoin("round");

                    bus_number.SetFillColor(bus_name_to_color.at(bus_name));
                    svg.Add(underlay);
                    svg.Add(bus_number);
                }
            }
        }
    }

    Svg::Document TransportRenderer::RenderSvgMap() const {
        Svg::Document doc;
        for (const auto &layer : render_props.layers) {
            RenderLayer(FromString(layer), doc);
        }
        return doc;
    }

    void TransportRenderer::RenderLayer(LayerType type, Svg::Document &svg) const {
        switch (type) {
            case LayerType::BUS_LINES:
                RenderBusRoutes(svg);
                break;
            case LayerType::BUS_LABELS:
                RenderBusNames(svg);
                break;
            case LayerType::STOP_POINTS:
                RenderStops(svg);
                break;
            case LayerType::STOP_LABELS:
                RenderStopsNames(svg);
                break;
            case LayerType::COMPANY_LINES:
                break;
            case LayerType::COMPANY_POINTS:
                break;
            case LayerType::COMPANY_LABELS:
                break;
        }
    }

    void TransportRenderer::RenderBusRouteLayer(LayerType type, Svg::Document &svg,
                                                const TransportRouter::RouteInfo &routeInfo) const {
        switch (type) {
            case LayerType::BUS_LINES:
                RenderRouteBusLines(svg, routeInfo);
                break;
            case LayerType::BUS_LABELS:
                RenderRouteBusNames(svg, routeInfo);
                break;
            case LayerType::STOP_POINTS:
                RenderRouteStops(svg, routeInfo);
                break;
            case LayerType::STOP_LABELS:
                RenderRouteStopsNames(svg, routeInfo);
                break;
            case LayerType::COMPANY_LINES:
                break;
            case LayerType::COMPANY_POINTS:
                break;
            case LayerType::COMPANY_LABELS:
                break;
        }
    }

    LayerType TransportRenderer::FromString(const std::string &layer) const {
        if (layer_types.count(layer) == 0) {
            throw invalid_argument("Wrong layer type : " + layer);
        }
        return layer_types.at(layer);
    }

    std::string TransportRenderer::RenderRoute(
            const TransportRouter::RouteInfo &routeInfo,
            Svg::Document initial_map
    ) const {
        RenderTransparentRect(initial_map);
        for (const auto &layer : render_props.layers) {
            RenderBusRouteLayer(FromString(layer), initial_map, routeInfo);
        }
        ostringstream out;
        initial_map.Render(out);
        return out.str();
    }

    void TransportRenderer::RenderTransparentRect(Svg::Document &svg) const {
        Svg::Rect rect;
        rect.SetTopLeft(Svg::Point{
                        .x = -render_props.outer_margin,
                        .y = -render_props.outer_margin
                })
                .SetBottomRight(Svg::Point{
                        .x = render_props.width + render_props.outer_margin,
                        .y = render_props.height + render_props.outer_margin
                })
                .SetFillColor(render_props.underlayer_color)
                .SetStrokeWidth(1.0)
                .SetStrokeColor(Svg::NoneColor);
        svg.Add(rect);
    }

/**
 * При отрисовке маршрута рисуются те участки автобусных линий, через которые проходит этот маршрут.
 *
 * Для каждого элемента маршрута типа Bus в порядке их упоминания в маршруте необходимо вывести
 * отрезок ломаной, соответствующей нужному отрезку автобусной линии. Обратите внимание,
 * что одна остановка может встречаться на одном маршруте несколько раз — этот случай нужно
 * обработать корректно и отобразить нужный отрезок.
 *
 * Способ вывода каждой ломаной аналогичен таковому в обычной карте.
 *
 * @param svg
 * @param routeInfo
 */
    void TransportRenderer::RenderRouteBusLines(
            Svg::Document &svg,
            const TransportRouter::RouteInfo &routeInfo
    ) const {

        using BBusItem = TransportRouter::RouteInfo::RideBusItem;

        for (const auto &item: routeInfo.items) {
            if (holds_alternative<BBusItem>(item)) {
                const auto &b_item = std::get<BBusItem>(item);
                const string &bus_name = b_item.bus_name;
                const auto &stops = buses_dict.at(bus_name)->stops;
                if (stops.empty()) {
                    continue;
                }
                Svg::Polyline polyline;
                polyline.SetStrokeColor(bus_name_to_color.at(b_item.bus_name))
                        .SetStrokeLineCap("round")
                        .SetStrokeLineJoin("round")
                        .SetStrokeWidth(render_props.line_width);

                for (size_t idx = b_item.start_stop_index; idx <= b_item.end_stop_index; ++idx) {
                    const string &stop_name = stops[idx];
                    polyline.AddPoint(stop_to_point.at(stop_name));
                }
                svg.Add(polyline);
            }
        }
    }

    void TransportRenderer::RenderBusName(Svg::Document &svg, const std::string &bus_name,
                                          const std::string &stop_name) const {
        const auto &color = bus_name_to_color.at(bus_name);
        const auto point = stop_to_point.at(stop_name);
        const auto base_text =
                Svg::Text{}
                        .SetPoint(point)
                        .SetOffset(render_props.bus_label_offset)
                        .SetFontSize(render_props.bus_label_font_size)
                        .SetFontFamily("Verdana")
                        .SetFontWeight("bold")
                        .SetData(bus_name);
        svg.Add(
                Svg::Text(base_text)
                        .SetFillColor(render_props.underlayer_color)
                        .SetStrokeColor(render_props.underlayer_color)
                        .SetStrokeWidth(render_props.underlayer_width)
                        .SetStrokeLineCap("round").SetStrokeLineJoin("round")
        );
        svg.Add(
                Svg::Text(base_text)
                        .SetFillColor(color)
        );
    }

/**
 * При отрисовке маршрута рисуются номера автобусов, соответствующие тем конечным,
 * через которые проходит этот маршрут.
 *
 * Для каждого элемента маршрута типа Bus в порядке их упоминания в маршруте необходимо
 * проверить, являются ли начало или конец этого отрезка конечными остановками
 * (с точки зрения слоя bus_labels). Если начало отрезка маршрута является конечной
 * этого маршрута, необходимо вывести название автобуса у соответствующей остановки.
 * Далее, если конец этого отрезка является конечной, необходимо вывести название автобуса
 * у соответствующей остановки. Обратите внимание, что в случае, когда отрезок маршрута
 * пролегает от конечной до конечной, названия автобуса выводятся в следующем порядке:
 * сначала для остановки, где начинается отрезок конкретного маршрута, затем для остановки,
 * где он заканчивается.
 *
 * @param svg
 * @param routeInfo
 */
    void TransportRenderer::RenderRouteBusNames(
            Svg::Document &svg,
            const TransportRouter::RouteInfo &routeInfo
    ) const {
        using BBusItem = TransportRouter::RouteInfo::RideBusItem;
        for (const auto &item : routeInfo.items) {
            if (!holds_alternative<BBusItem>(item)) {
                continue;
            }
            const auto &b_item = get<BBusItem>(item);
            const string &bus_name = b_item.bus_name;
            const auto bus = buses_dict.at(bus_name);
            const auto &stops = bus->stops;
            if (stops.empty()) {
                continue;
            }
            for (const size_t idx : {b_item.start_stop_index, b_item.end_stop_index}) {
                const auto &stop_name = stops[idx];
                if (idx == 0
                    || idx == stops.size() - 1
                    || find(begin(bus->end_stops), end(bus->end_stops), stop_name) != end(bus->end_stops)) {
                    RenderBusName(svg, bus_name, stop_name);
                }
            }
        }
    }

/**
 * При отрисовке маршрута рисуются круги остановок для тех участов автобусных линий,
 * через которые проходит этот маршрут.
 *
 * Для каждого элемента маршрута типа Bus в порядке их упоминания в маршруте необходимо
 * вывести круги всех остановок, соответствующих нужному отрезку автобусной линии.
 * Остановки должны выводится в порядке прохода через них текущего построенного маршрута.
 *
 * Обратите внимание, что согласно описанному алгоритму пересадочные остановки будут
 * выведены дважды: сначала для того автобуса, с которого делается пересадка, а
 * затем для автобуса, на который осуществляется пересадка.
 *
 * @param svg
 * @param routeInfo
 */
    void TransportRenderer::RenderRouteStops(
            Svg::Document &svg,
            const TransportRouter::RouteInfo &routeInfo
    ) const {
        using BBusItem = TransportRouter::RouteInfo::RideBusItem;
        for (const auto &item: routeInfo.items) {
            if (holds_alternative<BBusItem>(item)) {
                const auto &b_item = std::get<BBusItem>(item);
                const string &bus_name = b_item.bus_name;
                const auto &stops = buses_dict.at(bus_name)->stops;
                if (stops.empty()) {
                    continue;
                }
                for (size_t idx = b_item.start_stop_index; idx <= b_item.end_stop_index; ++idx) {
                    const string &stop_name = stops[idx];
                    svg.Add(Svg::Circle{}
                                    .SetCenter(stop_to_point.at(stop_name))
                                    .SetRadius(render_props.stop_radius)
                                    .SetFillColor("white"));
                }
            }
        }
    }

    void AddStopNameToMap(
            Svg::Document &svg,
            const std::string &stop_name,
            const RenderProps &render_props,
            const map<std::string, Svg::Point> &stop_to_point
    ) {
        Svg::Text text{};
        text.SetPoint(stop_to_point.at(stop_name))
                .SetFontFamily("Verdana")
                .SetOffset(render_props.stop_label_offset)
                .SetFontSize(render_props.stop_label_font_size)
                .SetData(stop_name);

        Svg::Text underlay = text;
        underlay.SetFillColor(render_props.underlayer_color)
                .SetStrokeColor(render_props.underlayer_color)
                .SetStrokeWidth(render_props.underlayer_width)
                .SetStrokeLineCap("round")
                .SetStrokeLineJoin("round");

        text.SetFillColor("black");

        svg.Add(underlay);
        svg.Add(text);
    }

    void AddStopNameToMap(
            Svg::Document &svg,
            const std::string &companyName,
            const std::string &companyDisplayName,
            const RenderProps &render_props,
            const unordered_map<std::string, Svg::Point> &company_to_point
    ) {
        Svg::Text text{};
        text.SetPoint(company_to_point.at(companyName))
                .SetFontFamily("Verdana")
                .SetOffset(render_props.stop_label_offset)
                .SetFontSize(render_props.stop_label_font_size)
                .SetData(companyDisplayName);

        Svg::Text underlay = text;
        underlay.SetFillColor(render_props.underlayer_color)
                .SetStrokeColor(render_props.underlayer_color)
                .SetStrokeWidth(render_props.underlayer_width)
                .SetStrokeLineCap("round")
                .SetStrokeLineJoin("round");

        text.SetFillColor("black");

        svg.Add(underlay);
        svg.Add(text);
    }

/**
 * При отрисовке маршрута названия рисуются только для пересадочных остановок конкретного маршрута.
 *
 * Для каждого элемента маршрута типа Wait в порядке их упоминания в маршруте необходимо
 * вывести название соответствующей остановки. Поскольку последней остановке маршрута не
 * соответствует элемент Wait, её название нужно дополнительно вывести в конце, после
 * вывода остальных названий.
 *
 * @param svg
 * @param routeInfo
 */
    void TransportRenderer::RenderRouteStopsNames(
            Svg::Document &svg,
            const TransportRouter::RouteInfo &routeInfo
    ) const {

        if (routeInfo.items.empty()) {
            return;
        }
        using Wait = TransportRouter::RouteInfo::WaitBusItem;
        using RideBus = TransportRouter::RouteInfo::RideBusItem;
        using WalkItem = TransportRouter::RouteInfo::WalkToCompanyItem;
        using WaitCompany = TransportRouter::RouteInfo::WaitCompanyItem;

        for (const auto &item: routeInfo.items) {
            if (holds_alternative<Wait>(item)) {
                const auto &w_item = std::get<Wait>(item);
                AddStopNameToMap(svg, w_item.stop_name, render_props, stop_to_point);
            }
        }

        if (holds_alternative<RideBus>(routeInfo.items.back())) {
            const auto &b_item = std::get<RideBus>(routeInfo.items.back());
            const string &last_stop_name = buses_dict.at(b_item.bus_name)->stops[b_item.end_stop_index];
            AddStopNameToMap(svg, last_stop_name, render_props, stop_to_point);
        }
        if (holds_alternative<WalkItem>(routeInfo.items.back())) {
            const auto &w_item = std::get<WalkItem>(routeInfo.items.back());
            AddStopNameToMap(svg, w_item.stop_name, render_props, stop_to_point);
        }

        if (holds_alternative<WaitCompany>(routeInfo.items.back())) {
            const auto& w_item = get<WalkItem>(routeInfo.items.at(routeInfo.items.size() - 2));
            AddStopNameToMap(svg, w_item.stop_name, render_props, stop_to_point);
        }

    }

    void RenderProps::Serialize(Serialization::RenderProps &serializedProps) const {
        serializedProps.set_width(width);
        serializedProps.set_height(height);
        serializedProps.set_padding(padding);
        serializedProps.set_stopradius(stop_radius);
        serializedProps.set_linewidth(line_width);
        serializedProps.set_outermargin(outer_margin);
        serializedProps.set_companyradius(company_radius);
        serializedProps.set_companylinewidth(company_line_width);
        serializedProps.set_stoplabelfontsize(stop_label_font_size);
        serializedProps.set_buslabelfontsize(bus_label_font_size);
        Svg::SerializePoint(stop_label_offset, *serializedProps.mutable_stoplabeloffset());
        Svg::SerializePoint(bus_label_offset, *serializedProps.mutable_buslabeloffset());
        Svg::SerializeColor(underlayer_color, *serializedProps.mutable_underlayercolor());
        serializedProps.set_underlayerwidth(underlayer_width);
        for (const auto &c : color_palette) {
            Svg::SerializeColor(c, *serializedProps.add_colorpalette());
        }
        for (const auto &layer : layers) {
            serializedProps.add_layers(layer);
        }
    }

    RenderProps RenderProps::Deserialize(const Serialization::RenderProps &serializedProps) {
        RenderProps props;
        props.width = serializedProps.width();
        props.height = serializedProps.height();
        props.padding = serializedProps.padding();
        props.stop_radius = serializedProps.stopradius();
        props.line_width = serializedProps.linewidth();
        props.outer_margin = serializedProps.outermargin();
        props.stop_label_font_size = serializedProps.stoplabelfontsize();
        props.bus_label_font_size = serializedProps.buslabelfontsize();
        props.stop_label_offset = Svg::DeserializePoint(serializedProps.stoplabeloffset());
        props.bus_label_offset = Svg::DeserializePoint(serializedProps.buslabeloffset());
        props.underlayer_color = Svg::DeserializeColor(serializedProps.underlayercolor());
        props.underlayer_width = serializedProps.underlayerwidth();
        props.layers.reserve(serializedProps.layers_size());

        props.color_palette.reserve(serializedProps.colorpalette_size());
        for (const auto &c : serializedProps.colorpalette()) {
            props.color_palette.push_back(Svg::DeserializeColor(c));
        }

        for (const auto &layer : serializedProps.layers()) {
            props.layers.push_back(layer);
        }
        props.company_line_width = serializedProps.companylinewidth();
        props.company_radius = serializedProps.companyradius();

        return props;
    }

    void TransportRenderer::Serialize(Serialization::TransportRenderer &serializedRenderer) const {
        // properties
        render_props.Serialize(*serializedRenderer.mutable_renderprops());
        // buses dict
        for (const auto&[_, bus] : buses_dict) {
            bus->Serialize(*serializedRenderer.add_busesdict());
        }

        // companies dict
        for (const auto&[_, comp] : *companiesDict) {
            comp.Serialize(*serializedRenderer.add_companiesdescription());
        }

        // vertex to point map
        for (const auto&[stopName, point] : stop_to_point) {
            auto &stopPosition = *serializedRenderer.add_stoppositions();
            stopPosition.set_stopname(stopName);
            Svg::SerializePoint(point, *stopPosition.mutable_stopposition());
        }

        // company to point
        for (const auto&[companyName, point] : company_to_point) {
            auto &companyPos = *serializedRenderer.add_companiespositions();
            companyPos.set_companyname(companyName);
            Svg::SerializePoint(point, *companyPos.mutable_companyposition());
        }

        // bus to color map
        for (const auto&[busName, color] : bus_name_to_color) {
            auto &busToColor = *serializedRenderer.add_buscolors();
            busToColor.set_busname(busName);
            Svg::SerializeColor(color, *busToColor.mutable_buscolor());
        }
    }

    TransportRenderer TransportRenderer::Deserialize(const Serialization::TransportRenderer &serializedRenderer) {
        TransportRenderer renderer;
        // render properties
        renderer.render_props = RenderProps::Deserialize(serializedRenderer.renderprops());
        // buses dict
        for (const auto &busDescr : serializedRenderer.busesdict()) {
            renderer.buses_dict[busDescr.name()] = std::make_shared<Descriptions::Bus>(
                    Descriptions::Bus::Deserialize(busDescr));
        }
        // comp dict
        renderer.companiesDict = std::make_unique<DB::CompaniesDict>();
        for (const auto &compDescr : serializedRenderer.companiesdescription()) {
            DB::CompaniesDict &dict = *renderer.companiesDict;
            dict[compDescr.mainname()] = DB::DisplayCompany::Deserialize(compDescr);
        }
        // bus_name_to_color map
        for (const auto &data : serializedRenderer.buscolors()) {
            renderer.bus_name_to_color[data.busname()] = Svg::DeserializeColor(data.buscolor());
        }
        // stop to point
        for (const auto &data : serializedRenderer.stoppositions()) {
            renderer.stop_to_point[data.stopname()] = {
                    Svg::DeserializePoint(data.stopposition())
            };
        }

        // company to point
        for (const auto &data : serializedRenderer.companiespositions()) {
            renderer.company_to_point[data.companyname()] = {
                    Svg::DeserializePoint(data.companyposition())
            };
        }
        return renderer;
    }

    const std::unordered_map<std::string,
            void (TransportRenderer::*)(Svg::Document &, const TransportRouter::RouteInfo &) const
    > TransportRenderer::ROUTE_TO_COMPANY_LAYER_ACTIONS = {
            {"bus_lines",      &TransportRenderer::RenderRouteBusLines},
            {"bus_labels",     &TransportRenderer::RenderRouteBusNames},
            {"stop_points",    &TransportRenderer::RenderRouteStops},
            {"stop_labels",    &TransportRenderer::RenderRouteStopsNames},
            {"company_lines",  &TransportRenderer::RenderCompanyLines},
            {"company_points", &TransportRenderer::RenderCompanyPoints},
            {"company_labels", &TransportRenderer::RenderCompanyLabels}
    };

    std::string TransportRenderer::RenderRouteToCompany(const TransportRouter::RouteInfo &routeInfo,
                                                        Svg::Document initial_map) const {

        RenderTransparentRect(initial_map);

        for (const auto &layer : render_props.layers) {
            (this->*ROUTE_TO_COMPANY_LAYER_ACTIONS.at(layer))(initial_map, routeInfo);
        }

        ostringstream out;
        initial_map.Render(out);
        return out.str();
    }

    void TransportRenderer::RenderRouteToCompanyLayer(LayerType type, Svg::Document &svg,
                                                      const TransportRouter::RouteInfo &routeInfo) const {
        switch (type) {
            case LayerType::BUS_LINES:
                RenderRouteBusLines(svg, routeInfo);
                break;
            case LayerType::BUS_LABELS:
                RenderRouteBusNames(svg, routeInfo);
                break;
            case LayerType::STOP_POINTS:
                RenderRouteStops(svg, routeInfo);
                break;
            case LayerType::STOP_LABELS:
                RenderRouteStopsNames(svg, routeInfo);
                break;
            case LayerType::COMPANY_LINES:
                RenderCompanyLines(svg, routeInfo);
                break;
            case LayerType::COMPANY_POINTS:
                RenderCompanyPoints(svg, routeInfo);
                break;
            case LayerType::COMPANY_LABELS:
                RenderCompanyLabels(svg, routeInfo);
                break;
        }
    }

    void TransportRenderer::RenderCompanyLines(Svg::Document &svg, const TransportRouter::RouteInfo &routeInfo) const {
        using CompanyItem = TransportRouter::RouteInfo::WalkToCompanyItem;
        // check from rear because a company is the destination, so it must be at the end ot the route
        for (const auto &item : routeInfo.items) {
            if (holds_alternative<CompanyItem>(item)) {
                const auto &c_item = std::get<CompanyItem>(item);

                Svg::Polyline polyline;
                polyline.SetStrokeColor("black")
                        .SetStrokeLineCap("round")
                        .SetStrokeLineJoin("round")
                        .SetStrokeWidth(render_props.company_line_width);
                polyline.AddPoint(stop_to_point.at(c_item.stop_name));
                polyline.AddPoint(company_to_point.at(c_item.company));

                svg.Add(polyline);
            }
        }
    }

    void TransportRenderer::RenderCompanyLabels(Svg::Document &svg, const TransportRouter::RouteInfo &routeInfo) const {

        if (routeInfo.items.empty()) {
            return;
        }

        using CompanyItem = TransportRouter::RouteInfo::WalkToCompanyItem;
        // items must contain only one company item
        for (const auto &item : routeInfo.items) {
            if (holds_alternative<CompanyItem>(item)) {
                const auto &c_item = std::get<CompanyItem>(item);
                const auto &displayName = companiesDict->at(c_item.company).displayName;
                AddStopNameToMap(svg, companiesDict->at(c_item.company).mainName, displayName, render_props,
                                 company_to_point);
            }
        }

    }

    void TransportRenderer::RenderCompanyPoints(Svg::Document &svg, const TransportRouter::RouteInfo &routeInfo) const {
        using CompanyItem = TransportRouter::RouteInfo::WalkToCompanyItem;
        // items must contain only one company item
        for (const auto &item : routeInfo.items) {
            if (holds_alternative<CompanyItem>(item)) {
                const auto &c_item = std::get<CompanyItem>(item);

                svg.Add(Svg::Circle{}
                                .SetCenter(company_to_point.at(c_item.company))
                                .SetRadius(render_props.company_radius)
                                .SetFillColor("black"));
            }
        }
    }

}























