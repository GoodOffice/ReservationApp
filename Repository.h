#pragma once

#ifndef Repository_
#define Repository_
#include <iostream>

#include <vector>

#include "Location.h"

#include "Vehicle.h"


using namespace std;

class Repository { // public Location,
public:
    int vehicles_capacity; // size

  ///*Create locations*/
  //Location* location = new Location(29, "Vancouver");
  ///*TO_DO: add a list of locations*/

  ///*Create vehicles*/
  //Vehicle* veh = new Vehicle(32, "Lamborghini Veratti");

    vector < Location* > getLocationList() {
        Location* location1 = new Location(4, "Toronto, ON");
        Location* location2 = new Location(5, "Montreal, QC");
        Location* location3 = new Location(7, "Vancouver, BC");
        Location* location4 = new Location(8, "Calgary, AB");

        vector < Location* > locations;
        locations.push_back(location1);
        locations.push_back(location2);
        locations.push_back(location3);
        locations.push_back(location4);

        return locations;
    }

    vector < Vehicle* > getVehicleList() {
        Vehicle* veh1 = new Vehicle(18, "Mercedes S-Class");
        Vehicle* veh2 = new Vehicle(19, "BMW 7 Series");
        Vehicle* veh3 = new Vehicle(20, "Audi A8");
        Vehicle* veh4 = new Vehicle(60, "porsche panamera");
        Vehicle* veh5 = new Vehicle(61, "Lamborghini Diablo");
        Vehicle* veh6 = new Vehicle(62, "Jeep Gladiator");
        Vehicle* veh7 = new Vehicle(32, "Lamborghini Veratti");

        vector < Vehicle* > vehicles;
        vehicles.push_back(veh1);
        vehicles.push_back(veh2);
        vehicles.push_back(veh3);
        vehicles.push_back(veh4);
        vehicles.push_back(veh5);
        vehicles.push_back(veh6);
        vehicles.push_back(veh7);

        return vehicles;
    }

    void addVehicleToLocation() {
        Location* location1 = new Location(4, "Vancouver, BC");
        Location* location2 = new Location(5, "Montreal, QC");
        Location* location3 = new Location(7, "Calgary, AB");
        Vehicle* veh1 = new Vehicle(18, "Mercedes S-Class");
        Vehicle* veh2 = new Vehicle(19, "BMW 7 Series");
        Vehicle* veh3 = new Vehicle(20, "Audi A8");
        Vehicle* veh4 = new Vehicle(60, "Porsche panamera");
        Vehicle* veh5 = new Vehicle(61, "Lamborghini Diablo");
        Vehicle* veh6 = new Vehicle(62, "Jeep Gladiator");
        Vehicle* veh7 = new Vehicle(32, "Lamborghini Veratti");

        vector < Location* > locations;
        locations.push_back(location1);
        locations.push_back(location2);
        locations.push_back(location3);
        cout << "Locations size=" << locations.size() << endl;
        vector < Vehicle* > vehicles;
        cout << "Now adding vehicles:";
        vehicles.push_back(veh1);
        vehicles.push_back(veh2);
        vehicles.push_back(veh3);
        vehicles.push_back(veh4);
        vehicles.push_back(veh5);
        vehicles.push_back(veh6);
        vehicles.push_back(veh7);

        cout << "\nVehicles size=" << vehicles.size() << endl;

        int index = 0;
        for (vector < Vehicle* > ::iterator itr = vehicles.begin(); itr != vehicles.end(); itr++) {
            try {
                location1->addVehicles(vehicles.at(index));
                location1->getLocation_Info();
            }
            catch (out_of_range exc) {
                cout << "Out of range exception" << endl;
            }
            index++;
        }
    }

    void removeVehicleFromLocation() {}

    void removeAllVehicleFromLocation(int loc_id) {}
};
#endif