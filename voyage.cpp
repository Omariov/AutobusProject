//
// Created by noureddine on 10/15/22.
//

#include "voyage.h"

#include <utility>
#include <iostream>



bool voyage::operator==(const voyage &other) const {
    return this->time_depart < other.time_depart && this->time_arrive < other.time_arrive &&
           this->arrival == other.depart;
}

bool voyage::operator<(const voyage &r) const {
    return this->time_arrive < r.time_arrive && this->time_depart < r.time_depart;
}

bool voyage::operator>(const voyage &r) const {
    return this->time_arrive > r.time_arrive && this->time_depart > r.time_depart;
}
double voyage::operator-(const voyage &r) const {
    return this->time_arrive - r.time_depart ;
}

long voyage::duration() const {
    return this->time_arrive - this->time_depart;
}

double voyage::diff_duration(const voyage &other) const {

    return difftime(this->time_depart , other.time_arrive)/60;
}

void voyage::voyage_detailled() {
    cout << this->depart->id_station << " "
         << this->dateTimeToString(*localtime(&this->time_depart), "%A %B, %d %Y %I:%M%p")
         << "   arrive: " << this->arrival->get_id_station() << " "
         << this->dateTimeToString(*localtime(&this->time_arrive), "%A %B, %d %Y %I:%M%p") << endl;
}

string voyage::get_voyage_id() const {
    return this->id_voyage;
}

voyage::voyage(string idTrip, BusStation *depart, BusStation *arrival, time_t timeDepart, time_t timeArrive)
        : id_voyage(std::move(idTrip)), depart(depart), arrival(arrival), time_depart(timeDepart), time_arrive(timeArrive) {}

