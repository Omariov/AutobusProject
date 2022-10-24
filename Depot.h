//
// Created by noureddine on 10/15/22.
//

#ifndef AUTO_BUS_PROJECT_DEPOT_H
#define AUTO_BUS_PROJECT_DEPOT_H


#include "ligne.h"

class Depot {
private:
    string depot_id;
    set<ligne *> les_ligne_associated;
    BusStation *depot;

public:
    explicit Depot(string depot_id);
    void add_ligne(set<ligne *> ligne);
    void Depot_Details();
    void add_depot(BusStation* d) {
        this->depot = d;
    }
};


#endif //AUTO_BUS_PROJECT_DEPOT_H
