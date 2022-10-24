#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include<algorithm>
#include <ctime>
#include "Depot.h"

using namespace std;

Depot *reading_the_file(ifstream &fin, string depot);

set<BusStation *> readBusStation(ifstream &fin);

set<ligne *> readLignesBusStation(ifstream &fin, set<struct BusStation *> BusStations);

void updateBusStationwithOtherStation(ifstream &fin, set<struct BusStation *> &BusStations);

BusStation *get_depot_main(set<BusStation *> busStations);

int main() {
    vector<Depot *> depots;
    std::string depots_txt[] = {"50"};
    for (auto &i: depots_txt) {
        std::ifstream fin;
        fin.open("/home/noureddine/CLionProjects/Auto_Bus_Project/Depots/depot" + i + ".txt");
        if (!fin) {
            std::cerr << "Error in opening the file" << std::endl;
            return 1; // if this is main
        } else {
            Depot *d = reading_the_file(fin, i);
            depots.push_back(d);
        }
    }
    for (auto d : depots) {
        d->Depot_Details();
    }
    return 0;
}

Depot *reading_the_file(ifstream &fin, string depot) {
    string line;
    getline(fin, line);
    auto *d = new Depot(depot);
    if (line == "BusStations={") {
        set<BusStation *> BusStations = readBusStation(fin);
        set<ligne *> lignes = readLignesBusStation(fin, BusStations);
        updateBusStationwithOtherStation(fin, BusStations);
        d->add_depot(get_depot_main(BusStations));
        d->add_ligne(lignes);
        return d;
    }
}

BusStation *get_depot_main(set<BusStation *> busStations) {
    for(auto it: busStations){
        if(it->is_depot){
            return it;
        }
    }

}

void updateBusStationwithOtherStation(ifstream &fin, set<BusStation *> &BusStations) {
    string line, interid, stationdepart, stationarrive, t;
    int tempstring;
    getline(fin, line);
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line == "InterTrips={") {
        while (getline(fin, line)) {
            istringstream iss(line);
            if (iss.str() == "};") {
                line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
                if (line == "};") {
                    cout << "End of Intertrips" << endl;
                    break;
                }

            } else {
                iss >> interid >> stationdepart >> stationarrive >> tempstring >> t;

                auto *depart = new BusStation(stationdepart);
                auto *arrive = new BusStation(stationarrive);
                for (auto &tt: BusStations) {
                    if (*tt == *depart) {
                        depart = tt;
                    } else if (*tt == *arrive) {
                        arrive = tt;
                    }
                }

                depart->add_Bus_station_relation(arrive, tempstring);

            }
        }
    }
}

set<ligne *> readLignesBusStation(ifstream &fin, set<struct BusStation *> BusStations) {
    set<ligne *> BusTrips;
    string line, id_ligne, id_voyage, date_debut, date_time_debut, date_time_arrived, date_arrived, id_station_depart, id_station_arrived, s;
    int i = 0;
    getline(fin, line);
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line != "BusTrips={") {
        cerr << "No bus trips !!!!";
    }
    while (getline(fin, line)) {
        istringstream iss(line);
        if (iss.str() == "};") {
            break;
        } else {
            (iss >> id_ligne >> id_voyage >> id_station_depart >> date_debut >> date_time_debut >> id_station_arrived
                 >> date_arrived >> date_time_arrived >> s);
            auto *depart = new BusStation(id_station_depart);
            auto *arrive = new BusStation(id_station_arrived);
            for (auto tt: BusStations) {
                if (*tt == *depart) {
                    depart = tt;
                } else if (*tt == *arrive) {
                    arrive = tt;
                }
            }

            struct tm date_time_depart_t = {};
            string dateTimeFormat{"%Y/%m/%d %H:%M"};
            istringstream ss(date_debut + " " + date_time_debut);
            ss >> get_time(&date_time_depart_t, dateTimeFormat.c_str());
            struct tm date_time_arrive_t = {};
            istringstream sss(date_arrived + " " + date_time_arrived);

            sss >> get_time(&date_time_arrive_t, dateTimeFormat.c_str());
            // Construct the voyage
            auto *v = new voyage(id_voyage, depart, arrive, mktime(&date_time_depart_t), mktime(&date_time_arrive_t));
            //now we must looking for the correspondance ligne
            bool exist = false;
            if (!BusTrips.empty()) {
                for (auto TripItenaire: BusTrips) {
                    if (TripItenaire->get_id_ligne() == id_ligne) {
                        TripItenaire->add_voyage(v);
                        exist = true;
                        break;
                    }
                }
            }

            if (!exist) {
                auto *temp = new ligne(id_ligne);
                temp->add_voyage(v);
                BusTrips.insert(temp);
            }
        }

    }
    return BusTrips;
}

set<BusStation *> readBusStation(ifstream &fin) {
    set<BusStation *> BusStations;
    string t, line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string id_station;
        int id_depot;
        if (!(iss >> id_station >> id_depot >> t)) {
            break;
        }
        auto *temp = new BusStation(id_station, id_depot);
        BusStations.insert(temp);
    }
    return BusStations;
}
