#pragma once

#include <iostream>
#include "Vehicle.h"
#include "Location.h"

Vehicle::Vehicle(){ }
Vehicle::Vehicle(Vehicle& vh){
	setVehicle_Name(vh.getVehicle_Name());

}
Vehicle::Vehicle(int vh_id, string vh_name) : vehicle_id(vh_id), vehicle_name(vh_name) { }
Vehicle::Vehicle(int vh_id, string vh_name,  bool vh_status) : vehicle_id(vh_id), vehicle_name(vh_name), status(vh_status) { }

/*Gets*/
int Vehicle::getVehicle_Id() { return this->vehicle_id; }
string Vehicle::getVehicle_Name() { return vehicle_name; }
int Vehicle::getVehicle_Location_Id() { return vehicle_location_id; }
bool Vehicle::getVehicle_Status() { 
	if(status == isUnAvailable )
		cout << "Vehicle.cpp:: getVehicle_Status - Status: This vehicule is currently rented out. Sorry " << endl;
	else
		cout << "Vehicle.cpp:: getVehicle_Status - Status: This vehicule is available for rent " << endl;
	return status; }
void Vehicle::getVehicle_Info() {
	if (getVehicle_Id() != NULL)
		cout << "Vehicle.cpp:: getVehicle_Info -> getVehicle_Id: " << getVehicle_Id() << endl;
	if (getVehicle_Name() != "")
		cout << "Vehicle.cpp:: getVehicle_Info -> getVehicle_Name: " << getVehicle_Name() << endl;
	if (getVehicle_Location_Id() != NULL)
		cout << "Vehicle.cpp:: getVehicle_Info -> getVehicle_Location_Id: " << getVehicle_Location_Id() << endl;
	if (getVehicle_Status() == false || getVehicle_Status() == true)
		cout << "Vehicle.cpp:: getVehicle_Info -> getVehicle_Status: " << getVehicle_Status() << endl;
}

/*Sets*/
void Vehicle::setVehicle_Id(int vh_id) { this->vehicle_id = vh_id; }
void Vehicle::setVehicle_Name(string vh_name) { this->vehicle_name = vh_name; }
void Vehicle::setVehicle_Location_Id(int vh_location) { this->vehicle_location_id = vh_location; }
void Vehicle::setVehicle_Status(bool status) { this->status = status; }
Vehicle::~Vehicle() { }