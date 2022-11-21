#pragma once

#include <iostream>

#include "Customer.h"


Customer::Customer() {}

Customer::Customer(string cs_fname) : firstname(cs_fname) {}

/*Gets*/
string Customer::getFirstName() {
    return firstname;
}

string Customer::getLastName() {
    return lastname;
}

string Customer::getFullName() {
    return fullName;
}

string Customer::getAddress() {
    return address;
}

int Customer::getAge() {
    return age;
}

int Customer::getAttrb_Rental_Id() {
    if (attrb_rental_id < 0)
        cout << "\n**Customer.cpp:: getAttrb_Rental_Id - Log: Rental must be created before operation, check and fix code order:" << attrb_rental_id << endl;
    else
        cout << "Customer.cpp:: getAttrb_Rental_Id - Rental Id (attributed):" << attrb_rental_id << endl;
    return attrb_rental_id;
}

int Customer::getReputation() {
    return reputation;
}

void Customer::getCustomer_Info() {
    if (getFirstName() != "")
        cout << "Customer.cpp:: getCustomer_Info -> getFirstName: " << getFirstName() << endl;
    if (getLastName() != "")
        cout << "Customer.cpp:: getCustomer_Info -> getLastName: " << getLastName() << endl;
    if (getAddress() != "")
        cout << "Customer.cpp:: getCustomer_Info -> getAddress: " << getAddress() << endl;
    if (getAge() < 100 && getAge() >= 16)
        cout << "Customer.cpp:: getCustomer_Info -> getAge: " << getAge() << endl;
    if (getReputation() == 1)
        cout << "Customer.cpp:: getCustomer_Info -> getReputation: is preferred " << endl;
    else
        cout << "Customer.cpp:: getCustomer_Info -> getReputation:has no designation " << endl;
}

bool Customer::getCustomerRentalStatus() {
    return isCurrentlyRenting;
}

/*Sets*/
void Customer::setFirstName(string cs_fname) {
    firstname = cs_fname;
}

void Customer::setLastName(string cs_lname) {
    lastname = cs_lname;
}

void Customer::setFullName(string cs_fname, string cs_lname) {
    fullName = cs_fname + " " + cs_lname;
}

void Customer::setAddress(string cs_address) {
    address = cs_address;
}

void Customer::setAge(int a) {
    age = a;
}

void Customer::setAttrb_Rental_Id(int rental_id) {
    cout << "Customer.cpp:: setAttrb_Rental_Id: " << rental_id << endl;
    attrb_rental_id = rental_id;
}

void Customer::updateAttrb_Rental_Id(int rental_id) {
    cout << "Customer.cpp:: updateAttrb_Rental_Id: " << rental_id << endl;
    attrb_rental_id = rental_id;
}

void Customer::setReputation(int rep) {
    reputation = rep;
}

void Customer::setCustomerRentalStatus(bool status) {
    isCurrentlyRenting = status;
}

Customer::~Customer() {} // desctructor