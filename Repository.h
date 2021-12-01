#pragma once

#ifndef Repository_
#define Repository_
#include <iostream>
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

		Location* location = new Location(29, "Vancouver");
		Vehicle* veh = new Vehicle(32, "Lamborghini Veratti");
		Vehicle* veh2 = new Vehicle(18, "Mercedes 4 Matic");
		
		location->addVehicles(veh);
		veh->getVehicle_Info();
		location->getLocation_Info();

		location->addVehicles(veh2);
		veh2->getVehicle_Info();
		location->getLocation_Info();

		delete veh;
		delete location;
	}

	void removeVehicleFromLocation() {

	}

	void removeAllVehicleFromLocation(int loc_id) {

	}

};
#endif