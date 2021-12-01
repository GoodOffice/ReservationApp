#pragma once

#include <iostream>
#include "Location.h"
#include <map>

Location::Location(){ }
Location::Location(int lc_id, string lc_name) : location_id(lc_id), location_name(lc_name) { }
Location::Location(int lc_id, string lc_name, bool lc_status) : location_id(lc_id), location_name(lc_name), location_status(lc_status) { }

/*Gets*/
int Location::getLocation_Id() { return location_id; };
string Location::getLocation_Name() { return location_name; };
bool Location::getLocation_Status() { return location_status; };
void Location::getLocation_Info(){ 
	if (getLocation_Id() != NULL)
		cout << "Location.cpp:: getLocation_Info -> getLocation_Id: " << getLocation_Id() << endl;
	if (getLocation_Name() != " ")
		cout << "Location.cpp:: getLocation_Info -> getLocation_Name: " << getLocation_Name() << endl;
	if (getLocation_Status() != NULL)
		cout << "Location.cpp:: getLocation_Info -> getLocation_Status: " << getLocation_Status() << endl;

		//Location::getVehicle_Id() 
};

int Location::getCapacity() { return capacity; }

/*Sets*/
void Location::setLocation_Id(int loc_id) { this->location_id = loc_id; }
void Location::setLocation_Name(string loc_name) { this->location_name = loc_name; }
void Location::setLocation_Status(int loc_status) { this->location_status = loc_status; }

void Location::addVehicles(Vehicle* v ) {
	/*TO_DO: add a list of vehicles*/
	v->getVehicle_Id();
	v->setVehicle_Location_Id(this->location_id); // update vehicle to current location id
	
	
	//capacity++;
}
Location::~Location() { }