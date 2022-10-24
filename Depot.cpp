//
// Created by noureddine on 10/15/22.
//

#include <iostream>
#include "Depot.h"

using namespace std;

Depot::Depot(string depot_id) {
    this->depot_id = depot_id;
}

void Depot::add_ligne(set<ligne *> ligne) {
    this->les_ligne_associated = std::move(ligne);
}

void Depot::Depot_Details() {
    cout << "In the depot" << this->depot_id << " We found lignes :: " << this->les_ligne_associated.size();
    this->depot->busStationDetail();
    int number = 0;
    for (auto &l: this->les_ligne_associated) {
        l->construct_itenaires(this->depot);
        l->get_ligne_details();
    }
    cout << "******************************" << endl;
}
