#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <variant>
#include <vector>
#include <memory>
#include "svg.pb.h"

namespace Svg {

    struct Point {
        double x = 0;
        double y = 0;
    };

    void SerializePoint(Point p, Serialization::Point &serializedPoint);

    Point DeserializePoint(const Serialization::Point &serializedPoint);

    struct Rgb {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };

    struct Rgba : Rgb {
        double alpha;
    };

    // monostate - is an empty alternative for variant aka - optional
    using Color = std::variant<std::monostate, std::string, Rgb, Rgba>;
    const Color NoneColor{};

    void SerializeColor(const Color &c, Serialization::Color &serializedColor);

    Color DeserializeColor(const Serialization::Color &serializedColor);

    void RenderColor(std::ostream &out, std::monostate);

    void RenderColor(std::ostream &out, Rgba rgba);

    void RenderColor(std::ostream &out, const std::string &value);

    void RenderColor(std::ostream &out, Rgb rgb);

    void RenderColor(std::ostream &out, const Color &color);

    /**
     * Base class for XML nodes
     */
    class Object {
    public:
        virtual void Render(std::ostream &out) const = 0;

        virtual ~Object() = default;
    };

    /**
     * Template class for storing base XML node properties.
     * Serves as a base class for XML nodes.
     * Don't inherit from Object because if we ever want to create some other kind of
     * properties for SVG path (e.g. AnimationProps) and make that AnimationProps inherit from Object
     * then class Object will two times be the base class of our SVG nodes (Circle, Text and Polyline),
     * so we leave it as it is - multiple inheritance.
     *
     * @tparam Owner type of the Derived class
     */
    template<typename Owner>
    class PathProps {
    public:
        Owner &SetFillColor(const Color &color);

        Owner &SetStrokeColor(const Color &color);

        Owner &SetStrokeWidth(double value);

        Owner &SetStrokeLineCap(const std::string &value);

        Owner &SetStrokeLineJoin(const std::string &value);

        void RenderAttrs(std::ostream &out) const;

    private:
        Color fill_color_;
        Color stroke_color_;
        double stroke_width_ = 1.0;
        std::optional<std::string> stroke_line_cap_;
        std::optional<std::string> stroke_line_join_;

        Owner &AsOwner();
    };

    class Circle : public Object, public PathProps<Circle> {
    public:
        Circle &SetCenter(Point point);

        Circle &SetRadius(double radius);

        void Render(std::ostream &out) const override;

        Point GetCenter() const;

    private:
        Point center_;
        double radius_ = 1;
    };

    class Polyline : public Object, public PathProps<Polyline> {
    public:
        Polyline &AddPoint(Point point);

        void Render(std::ostream &out) const override;

    private:
        std::vector<Point> points_;
    };

    class Text : public Object, public PathProps<Text> {
    public:
        Text &SetPoint(Point point);

        Text &SetOffset(Point point);

        Text &SetFontSize(uint32_t size);

        Text &SetFontFamily(const std::string &value);

        Text &SetData(const std::string &data);

        Text &SetFontWeight(const std::string &weight);

        void Render(std::ostream &out) const override;

    private:
        Point point_;
        Point offset_;
        uint32_t font_size_ = 1;
        std::optional<std::string> font_family_;
        std::string data_;
        std::optional<std::string> font_weight;
    };

    class Rect : public Object, public PathProps<Rect> {
    public:
        Rect &SetTopLeft(Point point);

        Rect &SetBottomRight(Point point);

        void Render(std::ostream &out) const override;

    private:
        Point topLeft;
        Point bottomRight;
    };

    class Document : public Object {
    public:
        template<typename ObjectType>
        void Add(ObjectType object);

        void Render(std::ostream &out) const override;

    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };

    template<typename Owner>
    Owner &PathProps<Owner>::AsOwner() {
        return static_cast<Owner &>(*this);
    }

    template<typename Owner>
    Owner &PathProps<Owner>::SetFillColor(const Color &color) {
        fill_color_ = color;
        return AsOwner();
    }

    template<typename Owner>
    Owner &PathProps<Owner>::SetStrokeColor(const Color &color) {
        stroke_color_ = color;
        return AsOwner();
    }

    template<typename Owner>
    Owner &PathProps<Owner>::SetStrokeWidth(double value) {
        stroke_width_ = value;
        return AsOwner();
    }

    template<typename Owner>
    Owner &PathProps<Owner>::SetStrokeLineCap(const std::string &value) {
        stroke_line_cap_ = value;
        return AsOwner();
    }

    template<typename Owner>
    Owner &PathProps<Owner>::SetStrokeLineJoin(const std::string &value) {
        stroke_line_join_ = value;
        return AsOwner();
    }

    template<typename Owner>
    void PathProps<Owner>::RenderAttrs(std::ostream &out) const {
        out << R"(fill=\")";
        RenderColor(out, fill_color_);
        out << R"(\" )";
        out << R"(stroke=\")";
        RenderColor(out, stroke_color_);
        out << R"(\" )";
        out << R"(stroke-width=\")" << stroke_width_ << R"(\" )";
        if (stroke_line_cap_) {
            out << R"(stroke-linecap=\")" << *stroke_line_cap_ << R"(\" )";
        }
        if (stroke_line_join_) {
            out << R"(stroke-linejoin=\")" << *stroke_line_join_ << R"(\" )";
        }
    }

    template<typename ObjectType>
    void Document::Add(ObjectType object) {
        objects_.push_back(std::make_shared<ObjectType>(std::move(object)));
    }

}

