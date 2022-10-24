//
// Created by noureddine on 10/15/22.
//

#include "ligne.h"

#include <utility>
#include <iostream>

ligne::ligne(string id_ligne) {
    this->id_ligne = std::move(id_ligne);
}

void ligne::add_voyage(voyage *v) {
    this->list_voyages.insert(v);
}

void ligne::construct_itenaires(BusStation *depot) {
    // we must first sort the voyages per time depart
    cout << endl;
    // then we must construct itenaires per voyages sequentially

    for (auto &it: this->list_voyages) {
        bool added = false;
        if (!this->list_des_itenaires.empty()) {
            for (auto &list_des_itenaire: this->list_des_itenaires) {
                auto itr = list_des_itenaire.rbegin();
                if (it->time_depart > (**itr).time_arrive &&
                    it->depart->get_id_station() == (**itr).arrival->get_id_station()) {
                    double duration = it->diff_duration(**itr);
                    this->attente_durations += duration;
                    list_des_itenaire.insert(it);
                    added = true;
                    break;
                } else if (it->time_depart > (**itr).time_arrive) {
                    if ((**itr).arrival->checkPossiblityHLP(it->depart,
                                                            difftime(it->time_depart, (**itr).time_arrive) / 60)) {
                        double hlp = it->diff_duration(**itr);
                        this->hlps.push_back(hlp);
                        list_des_itenaire.insert(it);
                        added = true;
                        break;
                    }
                }
            }
        }
        if (!added) {
            set<voyage *> itenaire_possible;

            itenaire_possible.insert(it);
            this->list_des_itenaires.push_back(itenaire_possible);
        }
    }
}

string ligne::get_id_ligne() {
    return (this->id_ligne);
}

void ligne::get_ligne_details() {
    cout << "In the ligne " << this->id_ligne << " We found " << this->list_voyages.size() << " We constructed : "
         << this->list_des_itenaires.size() << endl;
    long total = 0;
    double hlp = this->hlps.size();
    for (const auto &it: this->list_des_itenaires) {
        total += it.size();
    }
    double total_time_hlp = 0;
    for ( auto it: this->hlps){
        cout << it << endl;
         total_time_hlp += it;
    }
    cout << " total attents duration : "<<this->attente_durations << " and total hlp :" << total_time_hlp ;
    cout << " and after checking : " << total << " With hlp " << hlp << endl;
}

int ligne::get_voyages_number() {

    return this->list_voyages.size();
}


