#include "companies_components.h"
#include "algorithm"

namespace DB {

    void Address::Serialize(YellowPages::Address &proto) const {
        if (!formatted.empty()) {
            proto.set_formatted(formatted);
        }

        for (const auto &addressComponent : addressComponents) {
            auto &protoAddrComponent = *proto.add_components();
            protoAddrComponent.set_value(addressComponent);
        }
        auto &protoCoords = *proto.mutable_coords();
        protoCoords.set_lat(coords.latitude);
        protoCoords.set_lon(coords.longitude);
        if (!comment.empty()) {
            proto.set_comment(comment);
        }
    }

    Address Address::Deserialize(const YellowPages::Address &proto) {
        Address res;
        res.formatted = proto.formatted();
        res.addressComponents.reserve(proto.components_size());
        for (const auto &cmp : proto.components()) {
            res.addressComponents.push_back(cmp.value());
        }
        res.coords = Sphere::Point{.latitude = proto.coords().lat(), .longitude = proto.coords().lon()};
        res.comment = proto.comment();
        return res;
    }

    void Name::Serialize(YellowPages::Name &proto) const {
        proto.set_value(value);
        if (type == "MAIN") {
            proto.set_type(YellowPages::Name::MAIN);
        } else if (type == "SYNONYM") {
            proto.set_type(YellowPages::Name::SYNONYM);
        } else if (type == "SHORT") {
            proto.set_type(YellowPages::Name::SHORT);
        }
    }

    Name Name::Deserialize(const YellowPages::Name &proto) {
        Name res;
        res.value = proto.value();
        if (proto.type() == YellowPages::Name::MAIN) {
            res.type = "MAIN";
        } else if (proto.type() == YellowPages::Name::SYNONYM) {
            res.type = "SYNONYM";
        } else if (proto.type() == YellowPages::Name::SHORT) {
            res.type = "SHORT";
        } else {
            res.type = "MAIN";
        }
        return res;
    }

    void Phone::Serialize(YellowPages::Phone &proto) const {
        if (!formatted.empty()) {
            proto.set_formatted(formatted);
        }
        if (!country_code.empty()) {
            proto.set_country_code(country_code);
        }

        if (!local_code.empty()) {
            proto.set_local_code(local_code);
        }

        if (!number.empty()) {
            proto.set_number(number);
        }

        if (!extension.empty()) {
            proto.set_extension(extension);
        }

        if (!description.empty()) {
            proto.set_description(description);
        }

        if (type == "FAX") {
            proto.set_type(YellowPages::Phone::FAX);
        } else {
            proto.set_type(YellowPages::Phone::PHONE);
        }

    }

    Phone Phone::Deserialize(const YellowPages::Phone &proto) {
        Phone res;
        res.formatted = proto.formatted();
        if (proto.type() == YellowPages::Phone::FAX) {
            res.type = "FAX";
        } else {
            res.type = "PHONE";
        }
        res.country_code = proto.country_code();
        res.local_code = proto.local_code();
        res.number = proto.number();
        res.extension = proto.extension();
        res.description = proto.description();
        return res;
    }

    void Url::Serialize(YellowPages::Url &proto) const {
        proto.set_value(value);
    }

    Url Url::Deserialize(const YellowPages::Url &proto) {
        return Url{proto.value()};
    }

    void WorkingTimeInterval::Serialize(YellowPages::WorkingTimeInterval &proto) const {
        proto.set_day(dayStringToEnum.at(day));
        proto.set_minutes_from(minutes_from);
        proto.set_minutes_to(minutes_to);
    }

    const std::unordered_map<YellowPages::WorkingTimeInterval::Day, std::string> dayEnumToString{
            {YellowPages::WorkingTimeInterval::EVERYDAY,  "EVERYDAY"},
            {YellowPages::WorkingTimeInterval::MONDAY,    "MONDAY"},
            {YellowPages::WorkingTimeInterval::TUESDAY,   "TUESDAY"},
            {YellowPages::WorkingTimeInterval::WEDNESDAY, "WEDNESDAY"},
            {YellowPages::WorkingTimeInterval::THURSDAY,  "THURSDAY"},
            {YellowPages::WorkingTimeInterval::FRIDAY,    "FRIDAY"},
            {YellowPages::WorkingTimeInterval::SATURDAY,  "SATURDAY"},
            {YellowPages::WorkingTimeInterval::SUNDAY,    "SUNDAY"}
    };

    WorkingTimeInterval WorkingTimeInterval::Deserialize(const YellowPages::WorkingTimeInterval &proto) {
        WorkingTimeInterval res;
        res.day = dayEnumToString.at(proto.day());
        res.minutes_to = proto.minutes_to();
        res.minutes_from = proto.minutes_from();
        return res;
    }

    void WorkingTime::Serialize(YellowPages::WorkingTime &proto) const {
        proto.set_formatted(formatted);
        for (const auto &interval : intervals) {
            auto &protoInterval = *proto.add_intervals();
            interval.Serialize(protoInterval);
        }
    }

    WorkingTime WorkingTime::Deserialize(const YellowPages::WorkingTime &proto) {
        WorkingTime res;
        res.formatted = proto.formatted();
        res.intervals.reserve(proto.intervals_size());
        for (const auto &protoInterval : proto.intervals()) {
            res.intervals.push_back(WorkingTimeInterval::Deserialize(protoInterval));
        }
        return res;
    }

    void NearbyStop::Serialize(YellowPages::NearbyStop &proto) const {
        proto.set_name(name);
        proto.set_meters(meters);
    }

    NearbyStop NearbyStop::Deserialize(const YellowPages::NearbyStop &proto) {
        return NearbyStop{proto.name(), proto.meters()};
    }

    void Company::Serialize(YellowPages::Company &proto) const {
        address.Serialize(*proto.mutable_address());
        for (const auto &name: names) {
            auto &protoName = *proto.add_names();
            name.Serialize(protoName);
        }
        for (const auto &phone : phones) {
            auto &protoPhone = *proto.add_phones();
            phone.Serialize(protoPhone);
        }
        for (const auto &url : urls) {
            auto &protoUrl = *proto.add_urls();
            url.Serialize(protoUrl);
        }
        for (const auto rubric : rubrics) {
            proto.add_rubrics(rubric);
        }
        working_time.Serialize(*proto.mutable_working_time());

        for (const auto &stop : nearby_stops) {
            auto &protoStop = *proto.add_nearby_stops();
            stop.Serialize(protoStop);
        }
    }

    Company Company::Deserialize(const YellowPages::Company &proto) {
        Company res;
        res.address = Address::Deserialize(proto.address());
        res.names.reserve(proto.names_size());
        for (const auto &protoName : proto.names()) {
            res.names.push_back(Name::Deserialize(protoName));
        }
        res.phones.reserve(proto.phones_size());
        for (const auto &protoPhone : proto.phones()) {
            res.phones.push_back(Phone::Deserialize(protoPhone));
        }
        res.urls.reserve(proto.urls_size());
        for (const auto &protoUrl : proto.urls()) {
            res.urls.push_back(Url::Deserialize(protoUrl));
        }
        res.rubrics.reserve(proto.rubrics_size());
        for (const auto rubric : proto.rubrics()) {
            res.rubrics.push_back(rubric);
        }
        res.working_time = WorkingTime::Deserialize(proto.working_time());
        res.nearby_stops.reserve(proto.nearby_stops_size());
        for (const auto &protoStop : proto.nearby_stops()) {
            res.nearby_stops.push_back(NearbyStop::Deserialize(protoStop));
        }
        return res;
    }

    std::string Company::GetMainName() const {
        for (const auto &n : names) {
            if (n.type == "MAIN") {
                return n.value;
            }
        }
        // should never reach this line
        return "";
    }

    bool Company::IsOpenRoundTheClock() const {
        return working_time.intervals.empty();
    }

    void Rubric::Serialize(YellowPages::Rubric &proto) const {
        proto.set_name(name);
        for (const auto &kw : keywords) {
            proto.add_keywords(kw);
        }
    }

    Rubric Rubric::Deserialize(const YellowPages::Rubric &proto) {
        Rubric res;
        res.name = proto.name();
        res.keywords.reserve(proto.keywords_size());
        for (const auto &protoKw : proto.keywords()) {
            res.keywords.push_back(protoKw);
        }
        return res;
    }

    bool PhoneQuery::DoesPhoneMatch(const DB::Phone &object) const {
        if (!extension.empty() && extension != object.extension) {
            return false;
        }

        if (!type.empty() && type != object.type) {
            return false;
        }
        if (!countryCode.empty() && countryCode != object.country_code) {
            return false;
        }
        if (
                (!localCode.empty() || !countryCode.empty())
                && localCode != object.local_code
                ) {
            return false;
        }
        return number == object.number;
    }

    DateTime DateTime::ParseFromJson(const Json::Dict &input) {
        const auto &arr = input.at("datetime").AsArray();
        DateTime res;
        res.day = arr[0].AsInt();
        res.hours = arr[1].AsInt();
        res.minutes = arr[2].AsInt();
        return res;
    }

    CompanyQuery CompanyQuery::ParseFromJson(const Json::Dict &input) {
        CompanyQuery companyQuery;
        const auto &namesIt = input.find("names");
        if (namesIt != input.end()) {
            for (const auto &n : namesIt->second.AsArray()) {
                companyQuery.names.insert(n.AsString());
            }
        }

        const auto &urlsIt = input.find("urls");
        if (urlsIt != input.end()) {
            for (const auto &url : urlsIt->second.AsArray()) {
                companyQuery.urls.insert(url.AsString());
            }
        }

        const auto &rubricsIt = input.find("rubrics");
        if (rubricsIt != input.end()) {
            for (const auto &r : rubricsIt->second.AsArray()) {
                companyQuery.rubrics.insert(r.AsString());
            }
        }
        const auto &phonesIt = input.find("phones");
        if (phonesIt != input.end()) {
            for (const auto &phoneJson : phonesIt->second.AsArray()) {
                const auto &phoneMap = phoneJson.AsMap();
                PhoneQuery phoneQuery;
                const auto &typeIt = phoneMap.find("type");
                if (typeIt != phoneMap.end()) {
                    phoneQuery.type = typeIt->second.AsString();
                }

                const auto &countryCodeIt = phoneMap.find("country_code");
                if (countryCodeIt != phoneMap.end()) {
                    phoneQuery.countryCode = countryCodeIt->second.AsString();
                }

                const auto &localCodeIt = phoneMap.find("local_code");
                if (localCodeIt != phoneMap.end()) {
                    phoneQuery.localCode = localCodeIt->second.AsString();
                }

                const auto &numberIt = phoneMap.find("number");
                if (numberIt != phoneMap.end()) {
                    phoneQuery.number = numberIt->second.AsString();
                }

                const auto &extensionIt = phoneMap.find("extension");
                if (extensionIt != phoneMap.end()) {
                    phoneQuery.extension = extensionIt->second.AsString();
                }
                companyQuery.phones.push_back(std::move(phoneQuery));
            }
        }
        return companyQuery;
    }

    void DisplayCompany::Serialize(Serialization::CompaniesDescription &serializedComp) const {
        serializedComp.set_mainname(mainName);
        serializedComp.set_displayname(displayName);
        auto &serializedCoords = *serializedComp.mutable_coords();
        serializedCoords.set_lon(coords.longitude);
        serializedCoords.set_lat(coords.latitude);
        for (const auto &nearbyStop : nearbyStops) {
            nearbyStop.Serialize(*serializedComp.add_nearbystops());
        }
    }

    DisplayCompany DisplayCompany::Deserialize(const Serialization::CompaniesDescription &serializedComp) {
        DisplayCompany res;
        res.mainName = serializedComp.mainname();
        res.displayName = serializedComp.displayname();
        res.coords = Sphere::Point{};
        res.coords.latitude = serializedComp.coords().lat();
        res.coords.longitude = serializedComp.coords().lon();
        res.nearbyStops.reserve(serializedComp.nearbystops_size());
        for (const auto &n : serializedComp.nearbystops()) {
            res.nearbyStops.push_back(NearbyStop::Deserialize(n));
        }
        return res;
    }

}






















