#include "companies_database.h"
#include "sstream"
#include "utility"
#include "algorithm"

namespace DB {
    CompaniesDatabase::CompaniesDatabase(const Json::Dict &yellow_pages) {
        ReadDatabaseFromJson(yellow_pages);
        BuildCompaniesDict();
    }

    void CompaniesDatabase::ReadDatabaseFromJson(const Json::Dict &yellowPages) {
        FillRubrics(yellowPages.at("rubrics").AsMap());
        FillCompanies(yellowPages);
    }

    void CompaniesDatabase::FillRubrics(const Json::Dict &rubricsInfo) {
        for (const auto &r : rubricsInfo) {
            Rubric rubric;
            uint64_t key;
            std::istringstream keyStream(r.first);
            keyStream >> key;
            const auto &rubricMap = r.second.AsMap();
            rubric.name = rubricMap.at("name").AsString();
            if (rubricMap.count("key_words")) {
                const auto &keyWords = rubricMap.at("key_words").AsArray();
                rubric.keywords.reserve(keyWords.size());
                for (const auto &keyWord : keyWords) {
                    rubric.keywords.push_back(keyWord.AsString());
                }
            }
            rubrics[key] = std::move(rubric);
        }
    }

    void CompaniesDatabase::FillCompanies(const Json::Dict &yellowPages) {
        const auto &jsonCompanies = yellowPages.at("companies").AsArray();
        companies.reserve(jsonCompanies.size());
        for (const auto &c : jsonCompanies) {
            const auto &companyInfo = c.AsMap();
            DB::Company company;
            FillCompanyNames(companyInfo, company);
            FillCompanyUrls(companyInfo, company);
            FillCompanyRubrics(companyInfo, company);
            FillCompanyAddress(companyInfo, company);
            FillCompanyNearbyStops(companyInfo, company);
            FillCompanyWorkingTime(companyInfo, company);
            FillCompanyPhones(companyInfo, company);
            companies.push_back(std::move(company));
        }
    }

    void CompaniesDatabase::FillCompanyNames(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &names = companiesInfo.at("names").AsArray();
        company.names.reserve(names.size());
        for (const auto &nameJson : names) {
            const auto &nameMap = nameJson.AsMap();
            Name companyName;
            companyName.value = nameMap.at("value").AsString();
            const auto &typeJson = nameMap.find("type");
            if (typeJson != nameMap.end()) {
                companyName.type = typeJson->second.AsString();
            } else {
                companyName.type = "MAIN";
            }
            company.names.push_back(std::move(companyName));
        }
    }

    void CompaniesDatabase::FillCompanyUrls(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &urlsIt = companiesInfo.find("urls");
        if (urlsIt != companiesInfo.end()) {
            const auto &urls = urlsIt->second.AsArray();
            company.urls.reserve(urls.size());
            for (const auto &urlJson : urls) {
                Url companyUrl;
                companyUrl.value = urlJson.AsMap().at("value").AsString();
                company.urls.push_back(std::move(companyUrl));
            }
        }
    }

    void CompaniesDatabase::FillCompanyRubrics(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &rubricsIt = companiesInfo.find("rubrics");
        if (rubricsIt != companiesInfo.end()) {
            const auto &jsonRubrics = rubricsIt->second.AsArray();
            company.rubrics.reserve(jsonRubrics.size());
            for (const auto &rubricJson : jsonRubrics) {
                company.rubrics.push_back(rubricJson.AsInt());
            }
        }
    }

    void CompaniesDatabase::FillCompanyAddress(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &addrIt = companiesInfo.find("address");
        if (addrIt != companiesInfo.end()) {
            Address companyAddress;
            const auto &addressMap = addrIt->second.AsMap();

            const auto &formattedIt = addressMap.find("formatted");
            if (formattedIt != addressMap.end()) {
                companyAddress.formatted = formattedIt->second.AsString();
            }

            const auto &componentIt = addressMap.find("components");
            if (componentIt != addressMap.end()) {
                const auto &componentJson = componentIt->second.AsArray();
                companyAddress.addressComponents.reserve(componentJson.size());
                for (const auto &component : componentJson) {
                    companyAddress.addressComponents.emplace_back(component.AsMap().at("value").AsString());
                }
            }

            const auto &coordIt = addressMap.find("coords");
            if (coordIt != addressMap.end()) {
                const auto &coordMap = coordIt->second.AsMap();
//                Sphere::Point companyCoords{};
                auto &latStr = coordMap.at("lat").AsString();
                auto &lonStr = coordMap.at("lon").AsString();
                std::stringstream latStream(latStr);
                std::stringstream lonStream(lonStr);
                double lat;
                double lon;
                latStream >> lat;
                lonStream >> lon;
//                companyCoords.latitude = lat;
//                companyCoords.longitude = lon;
                companyAddress.coords = {lat, lon};
            }

            const auto &commentIt = addressMap.find("comment");
            if (commentIt != addressMap.end()) {
                companyAddress.comment = commentIt->second.AsString();
            }
            company.address = std::move(companyAddress);
        }
    }

    void CompaniesDatabase::FillCompanyNearbyStops(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &nearbyStopsJsonIt = companiesInfo.find("nearby_stops");
        if (nearbyStopsJsonIt != companiesInfo.end()) {
            const auto &nearbyStopsJson = nearbyStopsJsonIt->second.AsArray();
            company.nearby_stops.reserve(nearbyStopsJson.size());
            for (const auto &nearbyStopJson : nearbyStopsJson) {
                NearbyStop companyNearbyStop;
                const auto &nearbyStopMap = nearbyStopJson.AsMap();

                const auto &nameIt = nearbyStopMap.find("name");
                if (nameIt != nearbyStopMap.end()) {
                    companyNearbyStop.name = nameIt->second.AsString();
                }

                const auto &metersIt = nearbyStopMap.find("meters");
                if (metersIt != nearbyStopMap.end()) {
                    companyNearbyStop.meters = metersIt->second.AsInt();
                }
                company.nearby_stops.push_back(companyNearbyStop);
            }
        }
    }

    void CompaniesDatabase::FillCompanyWorkingTime(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &workingTimeIt = companiesInfo.find("working_time");
        if (workingTimeIt != companiesInfo.end()) {
            WorkingTime companyWorkingTime;
            const auto &workingTimeMap = workingTimeIt->second.AsMap();

            const auto &formattedIt = workingTimeMap.find("formatted");
            if (formattedIt != workingTimeMap.end()) {
                companyWorkingTime.formatted = formattedIt->second.AsString();
            }

            const auto &intervalsIt = workingTimeMap.find("intervals");
            if (intervalsIt != workingTimeMap.end()) {
                const auto &intervalsJson = intervalsIt->second.AsArray();
                companyWorkingTime.intervals.reserve(intervalsJson.size());
                for (const auto &intervalJson : intervalsJson) {
                    const auto &intervalMap = intervalJson.AsMap();
                    WorkingTimeInterval companyWorkingTimeInterval;
                    const auto &dayJson = intervalMap.at("day").AsString();
                    companyWorkingTimeInterval.day = dayJson;
                    companyWorkingTimeInterval.minutes_from = intervalMap.at("minutes_from").AsInt();
                    companyWorkingTimeInterval.minutes_to = intervalMap.at("minutes_to").AsInt();
                    companyWorkingTime.intervals.push_back(std::move(companyWorkingTimeInterval));
                }
            }
            company.working_time = std::move(companyWorkingTime);
        }
    }

    void CompaniesDatabase::FillCompanyPhones(const Json::Dict &companiesInfo, DB::Company &company) {
        const auto &phonesIt = companiesInfo.find("phones");
        if (phonesIt != companiesInfo.end()) {
            const auto &phonesArr = phonesIt->second.AsArray();
            company.phones.reserve(phonesArr.size());
            for (const auto &phoneJson : phonesArr) {
                const auto &phoneMap = phoneJson.AsMap();
                Phone companyPhones;

                const auto &formattedIt = phoneMap.find("formatted");
                if (formattedIt != phoneMap.end()) {
                    companyPhones.formatted = formattedIt->second.AsString();
                }

                const auto &typeIt = phoneMap.find("type");
                if (typeIt != phoneMap.end()) {
                    companyPhones.type = typeIt->second.AsString();
                } else {
                    companyPhones.type = "PHONE";
                }

                const auto &countryCodeIt = phoneMap.find("country_code");
                if (countryCodeIt != phoneMap.end()) {
                    companyPhones.country_code = countryCodeIt->second.AsString();
                }

                const auto &localCodeIt = phoneMap.find("local_code");
                if (localCodeIt != phoneMap.end()) {
                    companyPhones.local_code = localCodeIt->second.AsString();
                }

                const auto &numberIt = phoneMap.find("number");
                if (numberIt != phoneMap.end()) {
                    companyPhones.number = numberIt->second.AsString();
                }

                const auto &extensionIt = phoneMap.find("extension");
                if (extensionIt != phoneMap.end()) {
                    companyPhones.extension = extensionIt->second.AsString();
                }

                const auto &descrIt = phoneMap.find("description");
                if (descrIt != phoneMap.end()) {
                    companyPhones.description = descrIt->second.AsString();
                }
                company.phones.push_back(std::move(companyPhones));
            }
        }
    }

    bool CheckNames(const DB::Company &company, const CompanyQuery &query) {
        if (query.names.empty()) {
            return true;
        }
        if (!company.names.empty()) {
            for (const auto &companyName : company.names) {
                if (const auto it = query.names.find(companyName.value); it != query.names.end()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool CheckUrls(const DB::Company &company, const CompanyQuery &query) {
        if (query.urls.empty()) {
            return true;
        }
        if (!company.urls.empty()) {
            for (const auto &companyUrl : company.urls) {
                if (const auto it = query.urls.find(companyUrl.value); it != query.urls.end()) {
                    return true;
                }
            }
        }

        return false;
    }

    bool
    CheckRubrics(const DB::Company &company, const CompanyQuery &query,
                 const std::unordered_map<uint64_t, Rubric> &rubrics) {
        if (query.rubrics.empty()) {
            return true;
        }
        if (!company.rubrics.empty()) {
            for (const auto &companyRubricIndex : company.rubrics) {
                const auto &companyRubric = rubrics.at(companyRubricIndex);
                if (auto it = query.rubrics.find(companyRubric.name); it != query.rubrics.end()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool CheckPhones(const DB::Company &company, const CompanyQuery &query) {
        if (query.phones.empty()) {
            return true;
        }

        if (!company.phones.empty()) {
            for (const auto &companyPhone : company.phones) {
                for (const auto &queryPhone : query.phones) {
                    if (queryPhone.DoesPhoneMatch(companyPhone)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    std::vector<DB::CompanyResponse> CompaniesDatabase::FindCompanies(const DB::CompanyQuery &query) const {
        std::vector<CompanyResponse> response;
        // check names
        int idx = 0;
        for (const auto &company : companies) {

            if (!CheckNames(company, query)) {
                ++idx;
                continue;
            }
            if (!CheckUrls(company, query)) {
                ++idx;
                continue;
            }
            if (!CheckRubrics(company, query, rubrics)) {
                ++idx;
                continue;
            }
            if (!CheckPhones(company, query)) {
                ++idx;
                continue;
            }
            for (const auto &name : company.names) {
                if (name.type == "MAIN") {
                    response.push_back(CompanyResponse{name.value, idx});
                    break;
                }
            }
            ++idx;
        }
        return response;
    }

    void CompaniesDatabase::Serialize(YellowPages::Database &serializedDb) {
        for (const auto &company : companies) {
            auto &protoCompany = *serializedDb.add_companies();
            company.Serialize(protoCompany);
        }
        for (const auto&[idx, rubric] : rubrics) {
            auto &protoRubricsPair = *serializedDb.mutable_rubrics();
            auto &protoRubric = protoRubricsPair[idx];
            rubric.Serialize(protoRubric);
        }
    }

    CompaniesDatabase::CompaniesDatabase(YellowPages::Database &&serializedDb) {
        companies.reserve(serializedDb.companies_size());
        rubrics.reserve(serializedDb.rubrics_size());
        for (const auto &protoCompany : serializedDb.companies()) {
            companies.push_back(Company::Deserialize(protoCompany));
        }
        for (const auto &protoRubricPair : serializedDb.rubrics()) {
            rubrics[protoRubricPair.first] = Rubric::Deserialize(protoRubricPair.second);
        }
        BuildCompaniesDict();
    }

    CompaniesDatabase DB::CompaniesDatabase::Deserialize(const YellowPages::Database &serializedDb) {
        CompaniesDatabase db;
        db.companies.reserve(serializedDb.companies_size());
        db.rubrics.reserve(serializedDb.rubrics_size());
        for (const auto &protoCompany : serializedDb.companies()) {
            db.companies.push_back(Company::Deserialize(protoCompany));
        }
        for (const auto &protoRubricPair : serializedDb.rubrics()) {
            db.rubrics[protoRubricPair.first] = Rubric::Deserialize(protoRubricPair.second);
        }
        db.BuildCompaniesDict();
        db.BuildWorkingTimeIndices();
        return db;
    }

    void CompaniesDatabase::BuildCompaniesDict() {
        for (const auto &company : companies) {
            std::string companyName;
            for (const auto &n : company.names) {
                if (n.type == "MAIN") {
                    companyName = n.value;
                    break;
                }
            }
            const auto &companyRubrics = company.rubrics;
            std::string displayName;
            if (companyRubrics.empty()) {
                displayName = companyName;
            } else {
                displayName = rubrics.at(company.rubrics.front()).name + " " + companyName;
            }
            companiesDict[companyName] =
                    DisplayCompany{companyName, displayName, company.nearby_stops, company.address.coords};

        }
    }

    const DB::CompaniesDict &CompaniesDatabase::GetCompaniesDict() const {
        return companiesDict;
    }

    size_t GetMinimumDistanceToNearbyStops(const DB::Company &company) {
        auto it = std::min_element(company.nearby_stops.begin(), company.nearby_stops.end(),
                                   [](const NearbyStop &l, const NearbyStop &r) {
                                       return l.meters < r.meters;
                                   });
        if (it == company.nearby_stops.end()) {
            throw std::runtime_error("Passed company with no nearby stops to method GetMinimumDistanceToNearbyStops");
        }
        return it->meters;
    }

    void DB::CompaniesDatabase::BuildWorkingTimeIndices() {
        const double minutesInDay = 24.0 * 60.0;

        for (int i = 0; i < companies.size(); ++i) {
            const auto &company = companies[i];

            if (company.IsOpenRoundTheClock()) {
                continue;
            }

            std::vector<WorkTime> intervals;
            for (const auto &interval : company.working_time.intervals) {
                if (interval.day == "EVERYDAY") {
                    for (size_t j = 0; j < 7; ++j) {
                        double start = j * minutesInDay + interval.minutes_from;
                        double end = j * minutesInDay + interval.minutes_to;
                        intervals.push_back({start, end});
                    }
                } else {
                    int day_of_week = dayToIndex.at(interval.day);
                    double start = minutesInDay * day_of_week + interval.minutes_from;
                    double end = minutesInDay * day_of_week + interval.minutes_to;
                    intervals.push_back({start, end});
                }
            }
            std::sort(intervals.begin(), intervals.end(),
                      [](const WorkTime &lhs, const WorkTime &rhs) { return lhs.minutesFrom < rhs.minutesFrom; });
            companyIdxToWorkTimeIntervals[i] = std::move(intervals);
        }
    }

    double
    CompaniesDatabase::GetWaitTime(
            const DB::CompanyResponse &companyResponse,
            const DateTime &dateTime,
            double totalRouteTime
    ) const {

        const double minutes_per_week = 7.0 * 24.0 * 60.0;
        double arrivalTime = dateTime.day * 60 * 24 + dateTime.hours * 60 + dateTime.minutes + totalRouteTime;

        const auto &it = companyIdxToWorkTimeIntervals.find(companyResponse.idx);

        if (it == companyIdxToWorkTimeIntervals.end()) {
            return -1.0;
        }
        // slice arrival time in case a route takes longer than one week
        while (arrivalTime >= minutes_per_week) {
            arrivalTime -= minutes_per_week;
        }

        const auto &intervals = it->second;
        // get iterator pointing to the first WorkTime object that has minutesFrom field greater than arrival time
        auto upper_bound = std::upper_bound(intervals.begin(), intervals.end(), arrivalTime,
                                            [](double time, const WorkTime &rhs) { return time < rhs.minutesFrom; });

        auto prev =
                upper_bound == intervals.begin() // if points to the first element in the vector of company intervals
                ? std::prev(intervals.end()) // get the last interval
                : std::prev(upper_bound); // else get previous interval

        // if company is working at arrival time
        if (arrivalTime >= prev->minutesFrom && arrivalTime < prev->minutesTo) {
            return 0;
        }

        if (upper_bound == intervals.end()) {
            return minutes_per_week - arrivalTime + intervals.begin()->minutesFrom;
        }

        return upper_bound->minutesFrom - arrivalTime;
    }
}































