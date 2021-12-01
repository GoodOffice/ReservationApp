#pragma once

#include <iostream>
#include "Customer.h"


Customer::Customer() { }

Customer::Customer(string cs_fname) : firstname(cs_fname){ }

/*Gets*/
string Customer::getFirstName(){ return firstname; }
string Customer::getLastName() { return lastname; }
string Customer::getAddress() {	return address; }
int Customer::getAge() { return age; }
bool Customer::getDesignation() { return has_designation; }
void Customer::getCustomer_Info() {
	if (getFirstName() != " ")
		cout << "Customer.cpp:: getCustomer_Info -> getFirstName: " << getFirstName() << endl;
	if (getLastName() != " ")
		cout << "Customer.cpp:: getCustomer_Info -> getLastName: " << getLastName() << endl;
	if (getAddress() != " ")
		cout << "Customer.cpp:: getCustomer_Info -> getAddress: " << getAddress() << endl;
	if (getAge() < 100 && getAge() >= 16)
		cout << "Customer.cpp:: getCustomer_Info -> getAge: " << getAge() << endl;
	if (getDesignation() == false || getDesignation() == true)
		cout << "Customer.cpp:: getCustomer_Info -> getDesignation: " << getDesignation() << endl;
}

/*Sets*/
void Customer::setFirstName(string cs_fname) { this->firstname = cs_fname; }
void Customer::setLastName(string cs_lname) { this->lastname = cs_lname; }
void Customer::setAddress(string cs_address) { this->address = cs_address; }
void Customer::setAge(int age) { this->age = age; }
void Customer::setDesignation(bool designation) { this->has_designation = designation; }
Customer::~Customer() { } // desctructor
	
	

