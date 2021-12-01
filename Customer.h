#pragma once

#ifndef Customer_
#define Customer_
#include <iostream>
using namespace std;

class Customer { // extends person

public:
	string firstname, lastname, address;
	int age;
	bool has_designation;

	Customer(); // constructor
	Customer(string cs_fname); // 1 parameter constructor

	/*Get Methods*/
	string getFirstName();
	string getLastName();
	string getAddress();
	int getAge();
	bool getDesignation();
	void getCustomer_Info();

	/*Set Methods*/
	void setFirstName(string);
	void setLastName(string);
	void setAddress(string);
	void setAge(int);
	void setDesignation(bool);
	

	~Customer();

};
#endif