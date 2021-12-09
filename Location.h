#pragma once

#ifndef Location_
#define Location_
#include <iostream>
#include<vector>
#include "Vehicle.h"

using namespace std;

class Location : public Vehicle {

public:
	int location_id;
	string location_name;
	int location_status = 0;
	int capacity = 0;
	Vehicle* location_Veh;
	vector<Vehicle*> vehicles;
	Location();
	Location(int, string);
	//Location(int, string, bool);

	/*Get Methods*/

	int getLocation_Id();
	string getLocation_Name();
	int getLocation_Status();
	int getCapacity();
	void getLocation_Info();

	/*Set Methods*/
	void setLocation_Id(int);
	void setLocation_Name(string);
	void setLocation_Status(int);
	~Location();

	void addVehicles(Vehicle*);
	vector<Vehicle*> getVehicles();

};
#endif