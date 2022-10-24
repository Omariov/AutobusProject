//
// Created by noureddine on 10/16/22.
//

#include "trip.h"

#include <utility>

trip::trip(string idTrip, BusStation *depart, BusStation *arrival) : id_trip(std::move(idTrip)), depart(depart),
                                                                     arrival(arrival) {}
