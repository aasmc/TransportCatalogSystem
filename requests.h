#pragma once

#include "json.h"
#include "transport_catalog.h"

#include <string>
#include <variant>
#include "descriptions.h"
#include "companies_database.h"


namespace Requests {
    struct Stop {
        std::string name;

        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };

    struct Bus {
        std::string name;

        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };

    struct Route {
        std::string stop_from;
        std::string stop_to;

        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };

    struct Map {
        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };


    struct Company {
        DB::CompanyQuery companyQuery;

        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };

    struct RouteToCompany {
        std::string stopFrom{};
        DB::CompanyQuery companyQuery{};

        [[nodiscard]] Json::Dict Process(const TransportCatalog &db) const;
    };

    std::variant<Stop, Bus, Route, Map, Company, RouteToCompany> Read(const Json::Dict &attrs);

    std::vector<Json::Node> ProcessAll(const TransportCatalog &db, const std::vector<Json::Node> &requests);
}
