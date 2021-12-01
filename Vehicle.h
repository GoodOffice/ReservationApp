#pragma once

#ifndef Vehicle_
#define Vehicle_
#include <iostream>
using namespace std;

class Vehicle {

public:
	int vehicle_id, vehicle_location_id;
	string vehicle_name; // to remove later - >vehicle_location_name 
	bool status;

	Vehicle();
	Vehicle(int, string);
	Vehicle(int, string,  bool);

	/*Get Methods*/
	int getVehicle_Id();
	string getVehicle_Name();
	int getVehicle_Location_Id();
	bool getVehicle_Status();
	void getVehicle_Info();

	/*Set Methods*/
	void setVehicle_Id(int);
	void setVehicle_Name(string);
	void setVehicle_Location_Id(int );
	void setVehicle_Status(bool );
	~Vehicle();

};
#endif