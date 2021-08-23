#pragma once

#include "descriptions.h"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"
#include "companies_components.h"

namespace Compression {

    class CoordsCompressor {
    public:
        CoordsCompressor(
                const std::unordered_map<std::string, Sphere::Point> &stopsCoords,
                const DB::CompaniesDict &companiesDict);

        /**
         * Fills lats and lons vectors of CoordInfo with correct target values.
         * I.e. it compresses geographical positions according to a specified formula.
         * @param maxWidth
         * @param maxHeight
         * @param padding
         */
        void fillTargets(double maxWidth, double maxHeight, double padding);

        /**
         * Maps geographical latitude to compressed latitude,
         * if the geographical latitude has been previously compressed. Otherwise
         * there's undefined behaviour.
         * @param value
         * @return
         */
        double mapLat(double value) const;

        /**
         * Maps geographical longitude to compressed longitude,
         * if the geographical longitude has been previously compressed. Otherwise
         * there's undefined behaviour.
         * @param value
         * @return
         */
        double mapLon(double value) const;

        void fillIndices(
                const std::unordered_map<double, std::vector<double>> &neighbourLats,
                const std::unordered_map<double, std::vector<double>> &neighbourLons
        );

    private:
        /**
         * Holds information about coordination (either latitude or longitude).
         * Initial value (geographical) - [source],
         * compressed value - [target].
         *
         * Comparable by initial value.
         */
        struct CoordInfo {
            double source;
            size_t idx = 0;
            double target = 0;

            bool operator<(const CoordInfo &other) const {
                return source < other.source;
            }
        };

        /**
         * Stores sorted latitudes.
         */
        std::vector<CoordInfo> lats;
        /**
         * Stores sorted longitudes.
         */
        std::vector<CoordInfo> lons;

        static const CoordInfo &Find(
                const std::vector<CoordInfo> &sortedValues,
                double value,
                std::optional<std::vector<CoordInfo>::const_iterator> endIt = std::nullopt
        ) {
            // find iterator pointing to the first element (CoordInfo) with source equal to [value],
            // use lower_bound, because the vector is sorted. dereference the iterator.
            // !! DANGER!! will produce UB if used with incorrect [value].
            return *std::lower_bound(std::begin(sortedValues), endIt.value_or((end(sortedValues))), CoordInfo{value});
        }

        size_t findMaxIndex(const std::vector<CoordInfo> &coords) const {
            return std::max_element(
                    std::begin(coords), std::end(coords),
                    [](const CoordInfo &lhs, const CoordInfo &rhs) {
                        return lhs.idx < rhs.idx;
                    }
            )->idx;
        }

        void fillCoordIndices(std::vector<CoordInfo> &coords,
                              const std::unordered_map<double, std::vector<double>> &neighbourValues);

        size_t findMaxLatIdx() const {
            return findMaxIndex(lats);
        }

        size_t findMaxLonIdx() const {
            return findMaxIndex(lons);
        }
    };

    std::unordered_set<std::string> findSupportVertices(
            const Descriptions::BusesDict &busesDict
    );

    std::unordered_map<std::string, Sphere::Point> computeInterpolatedStopsGeoCoordinates(
            const Descriptions::StopsDict &stopsDict,
            const Descriptions::BusesDict &busesDict
    );

    struct NeighboursDicts {
        std::unordered_map<double, std::vector<double>> neighbourLats;
        std::unordered_map<double, std::vector<double>> neighbourLons;
    };

    NeighboursDicts computeNeighboursForCoord(
            const std::unordered_map<std::string, Sphere::Point> &stopsCoords,
            const Descriptions::BusesDict &busesDict,
            const DB::CompaniesDict &companiesDict
    );
}