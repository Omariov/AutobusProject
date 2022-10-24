//
// Created by noureddine on 10/15/22.
//

#include "BusStation.h"

#include <utility>
#include <iostream>

BusStation::BusStation(string id_stations, int is_depot) {
    this->id_station = std::move(id_stations);
    if (is_depot == 1) {
        this->is_depot = true;
    } else {
        this->is_depot = false;
    }
    this->bus_stations = *new map<BusStation *, int>();
}

void BusStation::add_Bus_station_relation(BusStation *bus_station, int distance) {
    this->bus_stations.insert(pair<BusStation *, int>(bus_station, distance));
}

bool BusStation::operator==(const BusStation &s) {
    return this->id_station == s.id_station;
}

BusStation::BusStation(string id_station) {
    this->id_station = std::move(id_station);

}

bool BusStation::operator<(const BusStation &s) {
    return this->id_station < s.id_station;
}

void BusStation::busStationDetail() {
    cout << "In the station " << this->id_station << " We found relation with " << this->bus_stations.size() << endl;
}

string BusStation::get_id_station() {
    return this->id_station;
}

bool BusStation::checkPossiblityHLP(BusStation *b, double time) {

    if (this->bus_stations.find(b) != this->bus_stations.end()) {
        return this->bus_stations[b] < time;
    } else {
        return false;
    }

}



