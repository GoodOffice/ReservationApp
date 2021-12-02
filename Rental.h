#pragma once

#ifndef Rental_
#define Rental_
#include <iostream>
#include <vector>
#include "Location.h"
#include "Customer.h"
#include "Repository.h"

class Rental {
public:
	int rental_id = 0, start_date, end_date;
	Customer* cstm;

	Rental(){ }
	Rental(int r_id, Customer* customer) {
		/*rental_id = r_id;*/
		setRentalCustomer(customer);
	}

	
	void createNewRental(Customer* customer) {
		if (customer->getAge() <= 25) {
			cout << "\nYou are 25 or below, 20% extra will be applied, and you cannot be designated\n" << endl;
			
			setRentalCustomer(customer);
		}
		rental_id++;
		customer->setAttrb_Rental_Id(rental_id);
	}

	void setRentalCustomer(Customer* customer) {
		cstm = customer;		
	}

	Customer* getRentalCustomer() {
		return cstm;
	}

	int getRentalSize() { // number of rentals
		int count = rental_id;
		cout << "Rental.h:: getRentalSize: " << count << endl;

		return count;
	}

	void getRentalBy_Id(int rental_id) {
		if (cstm->attrb_rental_id == rental_id) {
			cout << "You are viewing rental by Id_: " << cstm->getLastName() << endl;
			/*cstm->getFirstName()*/
		}
		

	}



};
#endif