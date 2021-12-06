#pragma once

#ifndef Customer_
#define Customer_
#include <iostream>
using namespace std;

class Customer { // extends person

public:
	string firstname, lastname, address;
	int age;
	int attrb_rental_id = -1;
	int isFavorite = 1;
	bool reputation;
	//Rental* rtl;

	Customer(); // constructor
	Customer(string cs_fname); // 1 parameter constructor

	/*Get Methods*/
	string getFirstName();
	string getLastName();
	string getAddress();
	int getAge();
	int getAttrb_Rental_Id();
	bool getReputation();
	void getCustomer_Info();

	/*Set Methods*/
	void setFirstName(string);
	void setLastName(string);
	void setAddress(string);
	void setAge(int);
	void setAttrb_Rental_Id(int);
	void updateAttrb_Rental_Id(int);
	void setReputation(bool);
	

	~Customer();

};
#endif