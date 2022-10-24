//
// Created by noureddine on 10/15/22.
//

#ifndef AUTO_BUS_PROJECT_LIGNE_H
#define AUTO_BUS_PROJECT_LIGNE_H


#include <vector>
#include <set>
#include "voyage.h"
using namespace std;

class ligne {
private :
    string id_ligne;
    set<voyage*> list_voyages;
    vector<set<voyage*>> list_des_itenaires;
    vector<double> hlps;
    double attente_durations = 0;

public:
    explicit ligne(string id_ligne);
    void add_voyage(voyage* v);
    void construct_itenaires(BusStation* depot);
    string get_id_ligne();
    void get_ligne_details();
    int get_voyages_number();
};


#endif //AUTO_BUS_PROJECT_LIGNE_H
