#pragma once

#ifndef Customer_
#define Customer_
#include <iostream>
using namespace std;

class Customer { // extends person

public:
	string firstname, lastname, fullName, address;
	int id;
	int age = 0;
	int attrb_rental_id = -1;
	int isFavorite = 1;
	int reputation;
	bool isCurrentlyRenting = false;

	//Rental* rtl;

	Customer(); // constructor
	Customer(string cs_fname); // 1 parameter constructor

	/*Get Methods*/
	string getFirstName();
	string getLastName();
	string getFullName();
	string getAddress();
	int getAge();
	int getAttrb_Rental_Id();
	int getReputation();
	void getCustomer_Info();
	bool getCustomerRentalStatus();

	/*Set Methods*/
	void setFirstName(string);
	void setLastName(string);
	void setFullName(string, string);
	void setAddress(string);
	void setAge(int);
	void setAttrb_Rental_Id(int);
	void updateAttrb_Rental_Id(int);
	void setReputation(int);
	void setCustomerRentalStatus(bool);
	
	bool operator==(const Customer& other) const {
		return firstname == other.firstname && lastname == other.lastname;
	}

	~Customer();

};
#endif