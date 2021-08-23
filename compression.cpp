#include "compression.h"
#include "utils.h"

using namespace std;

namespace Compression {

    CoordsCompressor::CoordsCompressor(
            const std::unordered_map<std::string, Sphere::Point> &stopsCoords,
            const DB::CompaniesDict &companiesDict
    ) {
        for (const auto&[_, coord] : stopsCoords) {
            lats.push_back({coord.latitude});
            lons.push_back({coord.longitude});
        }
        for (const auto&[_, comp] : companiesDict) {
            lats.push_back({comp.coords.latitude});
            lons.push_back({comp.coords.longitude});
        }

        sort(begin(lats), end(lats));
        sort(begin(lons), end(lons));
    }

    void CoordsCompressor::fillTargets(double maxWidth, double maxHeight, double padding) {
        if (lats.empty() || lons.empty()) {
            return;
        }
        const size_t maxLatIdx = findMaxLatIdx();
        // if there's only 1 coordinate, then step must be equal to 0
        const double y_step = maxLatIdx ? (maxHeight - 2 * padding) / maxLatIdx : 0;

        const auto maxLonIdx = findMaxLonIdx();
        // the same applies for x_step
        const double x_step = maxLonIdx ? (maxWidth - 2 * padding) / maxLonIdx : 0;

        // fill latitudes with compressed values
        for (auto&[_, idx, value] : lats) {
            value = maxHeight - padding - idx * y_step;
        }
        // fill longitudes with compressed values
        for (auto&[_, idx, value]: lons) {
            value = idx * x_step + padding;
        }
    }


    double CoordsCompressor::mapLat(double value) const {
        return Find(lats, value).target;
    }

    double CoordsCompressor::mapLon(double value) const {
        return Find(lons, value).target;
    }

    void CoordsCompressor::fillIndices(const std::unordered_map<double, std::vector<double>> &neighbourLats,
                                       const std::unordered_map<double, std::vector<double>> &neighbourLons) {
        fillCoordIndices(lats, neighbourLats);
        fillCoordIndices(lons, neighbourLons);
    }

/**
 * изменим алгоритм нумерации долгот (и широт) следующим образом.
 * Как и прежде, первая (минимальная) долгота получает номер 0.
 * Номер очередной долготы тоже равен 0, если среди предыдущих (то есть меньших её)
 * долгот нет её маршрутных соседей (см. определение в части K). Если же у очередной
 * долготы есть маршрутные соседи, меньшие её, то номер этой долготы равен номеру
 * максимального из меньших её маршрутных соседей плюс один.
 *
 * @param coords
 * @param neighbourValues
 */
    void CoordsCompressor::fillCoordIndices(std::vector<CoordInfo> &coords,
                                            const std::unordered_map<double, std::vector<double>> &neighbourValues) {

        // traverse all coordinates
        for (auto coordIt = begin(coords); coordIt != end(coords); ++coordIt) {
            // try to find iterator pointing to a neighbour of the stop
            const auto neighboursIt = neighbourValues.find(coordIt->source);
            // if a stop has no neighbour we set its index to 0
            if (neighboursIt == neighbourValues.end()) {
                coordIt->idx = 0;
                continue;
            }
            // get all neighbours of the current stop
            const auto &neighbours = neighboursIt->second;
            optional<size_t> maxNeighbourIdx;
            // traverse all neighbours
            for (const double value : neighbours) {
                // find index of the coordinate
                const size_t idx = Find(coords, value, coordIt).idx;
                // if its index is greater than maxNeighbourIdx
                if (idx > maxNeighbourIdx) {
                    // reset maxNeighbourIdx
                    maxNeighbourIdx = idx;
                }
            }
            coordIt->idx = *maxNeighbourIdx + 1;
        }
    }


/**
 * Finds all support stops. A support stop may be one of the following:
 *  - an end stop
 *  - a stop that is passed by more than one bus
 *  - a stop that is passed by a single bus more than 2 times
 * @param busesDict unordered map of busRoutes to Descriptions::Bus*
 * @return unordered_set<string> of names of support stops
 */
    unordered_set<string> findSupportVertices(
            const Descriptions::BusesDict &busesDict
    ) {
        unordered_set<string> supportStops;
        // helper map that allows us to find out if more than one bus passes a stop.
        // we use the unordered_map's feature: if we try to emplace an element to the map
        // and the key already exists in the map, then no insertion will happen.
        // emplace returns a pair of iterator pointing to a newly inserted element (or to the
        // existing one) and a bool flag that says if insertion happened.
        unordered_map<string, shared_ptr<Descriptions::Bus>> stopsFirstBus;
        // helper map that allows us to find out if a bus passes a stop more than 2 times
        unordered_map<string, int> stopsRank;

        // Traverse all buses
        for (const auto&[_, busPtr] : busesDict) {
            // case 1. Add all end stops to support stops
            for (const string &stop : busPtr->end_stops) {
                supportStops.insert(stop);
            }
            // case 2. traverse all the remaining stops of a bus
            for (const string &stop: busPtr->stops) {
                // increase the stop's rank (number of times a bus passes the stop)
                ++stopsRank[stop];
                // try to emplace {stop, busPtr} to helper map
                const auto[it, inserted] = stopsFirstBus.emplace(stop, busPtr);
                // if no insertion happened and previously stored pointer to Bus is not the same
                // pointer we are currently dealing with, then it means that more than one bus
                // passes through the stop, so add it to the support stops
                if (!inserted && it->second != busPtr) {
                    supportStops.insert(stop);
                }
            }
        }
        // case 3. check if a bus passes through a stop more than 2 times
        for (const auto&[stop, rank] : stopsRank) {
            if (rank > 2) {
                supportStops.insert(stop);
            }
        }
        return supportStops;
    }

/**
 * Evenly distributes all intermediate stops between support stops.
 *
 * Пусть, например, на автобусном маршруте со списком остановок stops есть остановка
 * номер i, являющаяся опорной, следующая опорная после неё имеет номер j. Тогда для
 * каждого k от i + 1 до j - 1 нужно вычислить новую долготу остановки stops[k] по формуле
 *
 * stops[i].lon + lon_step * (k - i), где lon_step = (stops[j].lon - stops[i].lon) / (j - i);
 * формулы для широт аналогичны.
 *
 * @param stopsDict
 * @param busesDict
 * @return
 */
    unordered_map<string, Sphere::Point> computeInterpolatedStopsGeoCoordinates(
            const Descriptions::StopsDict &stopsDict,
            const Descriptions::BusesDict &busesDict
    ) {

        const auto supportVertices = findSupportVertices(busesDict);
        // will hold new coordinates for all stops
        unordered_map<string, Sphere::Point> stopsCoords;
        // initially fill the map with geo coordinates
        for (const auto&[stopName, stopPtr] : stopsDict) {
            stopsCoords[stopName] = stopPtr->position;
        }

        // traverse all buses
        for (const auto&[_, busPtr] : busesDict) {
            // stops for current bus
            const auto &stops = busPtr->stops;
            if (stops.empty()) {
                continue;
            }
            // begin with index 0
            size_t lastSupportIndex = 0;
            // save coordinate of the first stop of the current bus
            stopsCoords[stops[0]] = stopsDict.at(stops[0])->position;
            // traverse all other stops of the current bus starting from the second stop
            for (size_t stopIdx = 1; stopIdx < stops.size(); ++stopIdx) {
                // if the stop is a support stop
                if (supportVertices.count(stops[stopIdx])) {
                    // get the position of the previous support stop
                    const Sphere::Point prevCoord = stopsDict.at(stops[lastSupportIndex])->position;
                    // get the position of the next support stop (i.e. current stop)
                    const Sphere::Point nextCoord = stopsDict.at(stops[stopIdx])->position;
                    // calculate step for latitudes by formula: (stops[j].lat - stops[i].lat) / (j - i)
                    const double latStep = (nextCoord.latitude - prevCoord.latitude) / (stopIdx - lastSupportIndex);
                    // calculate step for longitudes by formula: (stops[j].lon - stops[i].lon) / (j - i)
                    const double lonStep = (nextCoord.longitude - prevCoord.longitude) / (stopIdx - lastSupportIndex);
                    // evenly distribute all intermediate stops (that lie between previous support stop and last support stop)

                    for (size_t middleStopIdx = lastSupportIndex + 1; middleStopIdx < stopIdx; ++middleStopIdx) {
                        stopsCoords[stops[middleStopIdx]] = {
                                // calculate latitude by formula stops[i].lat + lat_step * (k - i),
                                prevCoord.latitude + latStep * (middleStopIdx - lastSupportIndex),
                                // calculate longitude by formula stops[i].lon + lon_step * (k - i),
                                prevCoord.longitude + lonStep * (middleStopIdx - lastSupportIndex)
                        };
                    }
                    // add current support stop's coordinate to the stopsCoordinate map
                    stopsCoords[stops[stopIdx]] = stopsDict.at(stops[stopIdx])->position;
                    // reset the index of the last support stop
                    lastSupportIndex = stopIdx;
                }
            }
        }
        return stopsCoords;
    }


    NeighboursDicts computeNeighboursForCoord(
            const unordered_map<string, Sphere::Point> &stopsCoords,
            const Descriptions::BusesDict &busesDict,
            const DB::CompaniesDict &companiesDict) {
        unordered_map<double, vector<double>> neighbourLats;
        unordered_map<double, vector<double>> neighbourLons;

        // traverse all buses
        for (const auto&[busName, busPtr] : busesDict) {
            const auto &stops = busPtr->stops;
            // if the bus has no stops, skip it
            if (stops.empty()) {
                continue;
            }
            // get position of the first stop of the current bus route
            Sphere::Point pointPrev = stopsCoords.at(stops[0]);
            // start traversing from second stop of the current bus route
            for (size_t stopIdx = 1; stopIdx < stops.size(); ++stopIdx) {
                // get position of the current stop
                const Sphere::Point pointCur = stopsCoords.at(stops[stopIdx]);
                if (stops[stopIdx] != stops[stopIdx - 1]) {
                    // select minimum and maximum latitude between previous position and current position
                    const auto[minLat, maxLat] = minmax(pointPrev.latitude, pointCur.latitude);
                    // select minimum and maximum longitude between previous position and current position
                    const auto[minLon, maxLon] = minmax(pointPrev.longitude, pointCur.longitude);
                    // we save neighbours for maximum values
                    neighbourLats[maxLat].push_back(minLat);
                    neighbourLons[maxLon].push_back(minLon);
                }
                // take step further
                pointPrev = pointCur;
            }
        }

        for (const auto&[_, company]: companiesDict) {
            for (const auto &nearbyStop : company.nearbyStops) {
                const auto currentStop = stopsCoords.at(nearbyStop.name);
                const auto[minLat, maxLat] = minmax(currentStop.latitude, company.coords.latitude);
                const auto[minLon, maxLon] = minmax(currentStop.longitude, company.coords.longitude);
                neighbourLats[maxLat].push_back(minLat);
                neighbourLons[maxLon].push_back(minLon);
            }
        }

        // erase all duplicates from vectors of neighbour coordinates
        for (auto *neighboursDict : {&neighbourLats, &neighbourLons}) {
            for (auto&[_, values] : *neighboursDict) {
                sort(begin(values), end(values));
                values.erase(unique(begin(values), end(values)), end(values));
            }
        }
        return {move(neighbourLats), move(neighbourLons)};
    }
}






















