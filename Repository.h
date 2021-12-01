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
	int unAvailable = 0;
	int Available = 1;
	int vehicles_capacity; // size

	///*Create locations*/
	//Location* location = new Location(29, "Vancouver");
	///*TO_DO: add a list of locations*/

	///*Create vehicles*/
	//Vehicle* veh = new Vehicle(32, "Lamborghini Veratti");
	

	void addVehicleToLocation() {
		//if(location->capacity < 10)

		Location* location1 = new Location(4, "Toronto, ON");
		Location* location2 = new Location(5, "Montreal, QC");
		Location* location3 = new Location(7, "Vancouver, BC");
		//Vehicle* veh = new Vehicle(32, "Lamborghini Veratti");
		Vehicle* veh1 = new Vehicle(18, "Mercedes S-Class");
		Vehicle* veh2 = new Vehicle(19, "BMW 7 Series");
		Vehicle* veh3 = new Vehicle(20, "Audi A8");
		Vehicle* veh4 = new Vehicle(60, "porsche panamera");
		Vehicle* veh5 = new Vehicle(61, "Lamborghini Diablo");
		Vehicle* veh6 = new Vehicle(62, "Jeep Gladiator");
		Vehicle* veh7 = new Vehicle(32, "Lamborghini Veratti");

		//location->addVehicles(veh);
		//veh->getVehicle_Info();
		//location->getLocation_Info();

		//location->addVehicles(veh2);
		//veh2->getVehicle_Info();
		//location->getLocation_Info();

		vector<Location*> locations;
		locations.push_back(location1);
		locations.push_back(location2);
		locations.push_back(location3);
		cout << "Locations size=" << locations.size() << endl;
		vector<Vehicle*> vehicles;
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
		for (vector<Vehicle*>::iterator itr = vehicles.begin(); itr != vehicles.end(); itr++)
		{
			try {				
				// cout << "vec.at(" << index << ")=" << vehicles.at(index)->getVehicle_Name() << endl;
				location1->addVehicles(vehicles.at(index));
				location1->getLocation_Info();
			}
			catch (out_of_range exc)
			{
				cout << "Out of range exception" << endl;
			}
			index ++;
		}

		


		//delete veh;
		//delete location;
	}

	void removeVehicleFromLocation() {

	}

	void removeAllVehicleFromLocation(int loc_id) {

	}

};
#endif