//
// Created by noureddine on 10/16/22.
//

#ifndef AUTO_BUS_PROJECT_HLP_H
#define AUTO_BUS_PROJECT_HLP_H


#include "trip.h"

class HLP : public trip{
public:
    double duration;

    HLP(const string &idTrip, BusStation *depart, BusStation *arrival, double duration);
};


#endif //AUTO_BUS_PROJECT_HLP_H
