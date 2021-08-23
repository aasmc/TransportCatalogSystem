#pragma once

#include "database.pb.h"
#include "vector"
#include "sphere.h"
#include "string"
#include "json.h"
#include "transport_renderer.pb.h"

namespace DB {
    struct Address {
        std::string formatted;
        std::vector<std::string> addressComponents;
        Sphere::Point coords;
        std::string comment;

        void Serialize(YellowPages::Address &proto) const;

        static Address Deserialize(const YellowPages::Address &proto);
    };

    struct Name {
        std::string value;
        std::string type;

        void Serialize(YellowPages::Name &proto) const;

        static Name Deserialize(const YellowPages::Name &proto);
    };

    struct Phone {
        std::string formatted;
        std::string type;
        std::string country_code;
        std::string local_code;
        std::string number;
        std::string extension;
        std::string description;

        void Serialize(YellowPages::Phone &proto) const;

        static Phone Deserialize(const YellowPages::Phone &proto);
    };

    struct Url {
        std::string value;

        void Serialize(YellowPages::Url &proto) const;

        static Url Deserialize(const YellowPages::Url &proto);
    };

    struct WorkingTimeInterval {
        std::string day{};
        int minutes_from{};
        int minutes_to{};

        const std::unordered_map<std::string, YellowPages::WorkingTimeInterval::Day> dayStringToEnum{
                {"EVERYDAY",  YellowPages::WorkingTimeInterval::EVERYDAY},
                {"MONDAY",    YellowPages::WorkingTimeInterval::MONDAY},
                {"TUESDAY",   YellowPages::WorkingTimeInterval::TUESDAY},
                {"WEDNESDAY", YellowPages::WorkingTimeInterval::WEDNESDAY},
                {"THURSDAY",  YellowPages::WorkingTimeInterval::THURSDAY},
                {"FRIDAY",    YellowPages::WorkingTimeInterval::FRIDAY},
                {"SATURDAY",  YellowPages::WorkingTimeInterval::SATURDAY},
                {"SUNDAY",    YellowPages::WorkingTimeInterval::SUNDAY}
        };

        void Serialize(YellowPages::WorkingTimeInterval &proto) const;

        static WorkingTimeInterval Deserialize(const YellowPages::WorkingTimeInterval &proto);
    };

    struct WorkingTime {
        std::string formatted{};
        std::vector<WorkingTimeInterval> intervals{};

        void Serialize(YellowPages::WorkingTime &proto) const;

        static WorkingTime Deserialize(const YellowPages::WorkingTime &proto);
    };

    struct NearbyStop {
        std::string name{};
        std::size_t meters{};

        void Serialize(YellowPages::NearbyStop &proto) const;

        static NearbyStop Deserialize(const YellowPages::NearbyStop &proto);
    };

    struct DateTime {
        int day{};
        int hours{};
        int minutes{};

        static DateTime ParseFromJson(const Json::Dict &input);
    };

    struct Company {
        Address address{};
        std::vector<Name> names{};
        std::vector<Phone> phones{};
        std::vector<Url> urls{};
        std::vector<uint64_t> rubrics{};
        WorkingTime working_time{};
        std::vector<NearbyStop> nearby_stops{};

        std::string GetMainName() const;

        bool IsOpenRoundTheClock() const;

        void Serialize(YellowPages::Company &proto) const;

        static Company Deserialize(const YellowPages::Company &proto);

    };

    struct Rubric {
        std::string name;
        std::vector<std::string> keywords;

        void Serialize(YellowPages::Rubric &proto) const;

        static Rubric Deserialize(const YellowPages::Rubric &proto);
    };


    struct CompanyResponse {
        std::string companyDescription;
        int idx;
    };

    struct PhoneQuery {
        std::string type;
        std::string countryCode;
        std::string localCode;
        std::string number;
        std::string extension;

        bool DoesPhoneMatch(const DB::Phone &object) const;

    };

    struct CompanyQuery {

        std::unordered_set<std::string> names;
        std::unordered_set<std::string> urls;
        std::unordered_set<std::string> rubrics;
        std::vector<PhoneQuery> phones;
        // array of 3 ints (0-6) - days of week, (0-23) hours, (0-59) minutes
        DateTime datetime;

        static CompanyQuery ParseFromJson(const Json::Dict &input);
    };

    struct DisplayCompany {
        std::string mainName;
        std::string displayName;
        std::vector<NearbyStop> nearbyStops;
        Sphere::Point coords;

        static DisplayCompany Deserialize(const Serialization::CompaniesDescription &serializedComp);

        void Serialize(Serialization::CompaniesDescription &serializedComp) const;
    };

    template<typename Object>
    using Dict = std::map<std::string, Object>;

    using CompaniesDict = Dict<DisplayCompany>;

}
