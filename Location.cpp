#pragma once

#include <iostream>
#include "Location.h"
#include <map>

Location::Location(){ }
Location::Location(int lc_id, string lc_name) : location_id(lc_id), location_name(lc_name) { }
//Location::Location(int lc_id, string lc_name, bool lc_status) : location_id(lc_id), location_name(lc_name), location_status(lc_status) { }

/*Gets*/
inline int Location::getLocation_Id() { return location_id; };
string Location::getLocation_Name() { return location_name; };
int Location::getLocation_Status() { return location_status; };
void Location::getLocation_Info(){ 
	if (getLocation_Id() != NULL)
		cout << "Location.cpp:: getLocation_Info -> getLocation_Id: " << getLocation_Id() << endl;
	if (getLocation_Name() != " ")
		cout << "Location.cpp:: getLocation_Info -> getLocation_Name: " << getLocation_Name() << endl;
	if (getLocation_Status() <!0)
		cout << "Location.cpp:: getLocation_Info -> getLocation_Status: " << getLocation_Status() << endl;
	if (getCapacity() > 0) {
		cout << "Location.cpp:: getLocation_Info -> getCapacity: location Id " << location_id << " size is " << this->capacity << endl;
		/*Work with location_Veh ...this->location_Veh = v;*/
		cout << "@ Location.cpp:: getLocation_Info -> details: vehicle Id " << this->location_Veh->getVehicle_Id() << " [" << this->location_Veh->getVehicle_Name() << "] is at location " << getVehicle_Location_Id() << endl; // work with this->location_Veh = v;
		//cout << " #2@ Location.cpp:: getLocation_Info -> getCapacity: vehicle Ids " << this->vehicle_id << " (" << this->vehicle_name << ") is at location " << this->vehicle_location_id << endl;
		//Location::getVehicle_Id() 

	}
};

int Location::getCapacity() {
	cout << "Location.cpp:: getCapacity: location Id_ " <<  this->capacity << endl;
	return capacity; }

/*Sets*/
void Location::setLocation_Id(int loc_id) { this->location_id = loc_id; }
void Location::setLocation_Name(string loc_name) { this->location_name = loc_name; }
void Location::setLocation_Status(int loc_status) { this->location_status = loc_status; }

void Location::addVehicles(Vehicle* v ) {
	/*TO_DO: add a list of vehicles*/
	v->getVehicle_Id();
	v->setVehicle_Location_Id(location_id); // // setting id to current vehicle instance
	this->location_Veh = v;
	/*Assigning vehicles to location*/
	this->setVehicle_Location_Id(location_id); // setting vehicle's location_id property to current location instance
	this->setVehicle_Id(v->getVehicle_Id()); // setting location's id property to current location instance
	this->setVehicle_Name(v->getVehicle_Name()); // setting location's name property to current location instance
	//this->setLocation_Id(location_id);
	
	capacity++;
}
Location::~Location() { }