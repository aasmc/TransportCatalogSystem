#pragma once

#include "companies_components.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "json.h"
#include "string"
#include "database.pb.h"
#include "descriptions.h"
#include "optional"

namespace DB {

    class CompaniesDatabase {
    private:

        CompaniesDatabase() = default;

        std::vector<Company> companies;
        std::unordered_map<uint64_t, Rubric> rubrics;
        CompaniesDict companiesDict;

        const std::unordered_map<YellowPages::Phone::Type, std::string> phoneTypeToString{
                {YellowPages::Phone::PHONE, "PHONE"},
                {YellowPages::Phone::FAX,   "FAX"}
        };

        void ReadDatabaseFromJson(const Json::Dict &yellowPages);

        void FillRubrics(const Json::Dict &rubricsInfo);

        void FillCompanies(const Json::Dict &yellowPages);

        void FillCompanyNames(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyUrls(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyRubrics(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyAddress(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyNearbyStops(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyWorkingTime(const Json::Dict &companiesInfo, DB::Company &company);

        void FillCompanyPhones(const Json::Dict &companiesInfo, DB::Company &company);

        void BuildCompaniesDict();

        struct WorkTime {
            double minutesFrom{};
            double minutesTo{};
        };

        std::unordered_map<int, std::vector<WorkTime>> companyIdxToWorkTimeIntervals;

        const std::unordered_map<std::string, int> dayToIndex{
                {"MONDAY",    0},
                {"TUESDAY",   1},
                {"WEDNESDAY", 2},
                {"THURSDAY",  3},
                {"FRIDAY",    4},
                {"SATURDAY",  5},
                {"SUNDAY",    6},
        };

    public:

        const DB::CompaniesDict &GetCompaniesDict() const;

        double GetWaitTime(
                const DB::CompanyResponse &companyResponse,
                const DateTime &dateTime,
                double totalTime
        ) const;

        void BuildWorkingTimeIndices();

        explicit CompaniesDatabase(const Json::Dict &yellow_pages);

        explicit CompaniesDatabase(YellowPages::Database &&database_);

        std::vector<CompanyResponse> FindCompanies(const DB::CompanyQuery &query) const;

        void Serialize(YellowPages::Database &serializedDb);

        static CompaniesDatabase Deserialize(const YellowPages::Database &serializedDb);

    };
}