//
// Created by noureddine on 10/15/22.
//

#ifndef AUTO_BUS_PROJECT_BUSSTATION_H
#define AUTO_BUS_PROJECT_BUSSTATION_H

#include <string>
using namespace std;
#include <map>


class BusStation {
public:
    string id_station;
    bool is_depot{};
    map<BusStation*,int> bus_stations;
public:
    BusStation(string id_station, int is_depot );
    explicit BusStation(string id_station);
    void add_Bus_station_relation(BusStation* bus_station, int distance);
    bool operator==(const BusStation& bustation);
    bool operator<(const BusStation& bustation);
    void busStationDetail();
    string get_id_station();
    bool checkPossiblityHLP(BusStation* b, double time);
};


#endif //AUTO_BUS_PROJECT_BUSSTATION_H
