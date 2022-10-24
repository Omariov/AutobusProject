//
// Created by noureddine on 10/16/22.
//

#ifndef AUTO_BUS_PROJECT_TRIP_H
#define AUTO_BUS_PROJECT_TRIP_H


#include <string>
#include "BusStation.h"

class trip {
public:
    std::string id_trip;
    BusStation* depart;
    BusStation* arrival;

    trip(string idTrip, BusStation *depart, BusStation *arrival);
};


#endif //AUTO_BUS_PROJECT_TRIP_H
