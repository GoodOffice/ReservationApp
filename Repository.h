#pragma once

#ifndef Repository_
#define Repository_
#include <iostream>
#include "Vehicle.h"
using namespace std;

#include "Location.h"

class Repository : public Location { // public Vehicle,
public:
	int unAvailable = 0;
	int Available = 1;
	int vehicles_capacity; // size

	/*Create locations*/
	Location* location = new Location(1, "Vancouver");
	/*TO_DO: add a list of locations*/

	/*Create vehicles*/
	Vehicle* veh = new Vehicle(32, "Lamborghini Veratti");
	

	void addVehicleToLocation() {
		//if(location->capacity < 10)
		
		location->addVehicles(veh);
		veh->getVehicle_Info();
	}

};
#endif