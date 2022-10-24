//
// Created by noureddine on 10/16/22.
//

#include "HLP.h"

HLP::HLP(const string &idTrip, BusStation *depart, BusStation *arrival, double duration) : trip(idTrip, depart,
                                                                                                arrival),
                                                                                           duration(duration) {}
