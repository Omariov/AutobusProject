//
// Created by noureddine on 10/15/22.
//

#ifndef AUTO_BUS_PROJECT_VOYAGE_H
#define AUTO_BUS_PROJECT_VOYAGE_H

#include <string>
#include "BusStation.h"
#include "trip.h"
#include <iomanip>
#include<algorithm>
#include <ctime>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <cstring>

class voyage {
public:
    std::string id_voyage;
    BusStation* depart;
    BusStation* arrival;
    time_t time_depart;
    time_t time_arrive;

public:

    ostream &formatDateTime(ostream &out, const tm &t, const char *fmt) {
        const auto &dateWriter = use_facet<time_put<char> >(out.getloc());
        int n = strlen(fmt);
        if (dateWriter.put(out, out, ' ', &t, fmt, fmt + n).failed()) {
            throw runtime_error("failure to format date time");
        }
        return out;
    }

    string dateTimeToString(const tm &t, const char *format) {
        stringstream s;
        formatDateTime(s, t, format);
        return s.str();
    }

    voyage(string idTrip, BusStation *depart, BusStation *arrival, time_t timeDepart, time_t timeArrive);
    bool operator==(const voyage& other) const;
    bool operator<(const voyage& r) const;
    bool operator>(const  voyage& r) const;
    double operator-(const voyage &r) const;
    [[nodiscard]] long duration() const;
    double diff_duration(const voyage& other) const;
    void voyage_detailled();
    string get_voyage_id() const;
};


#endif //AUTO_BUS_PROJECT_VOYAGE_H
