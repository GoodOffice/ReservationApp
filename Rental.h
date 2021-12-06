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
	int rental_id = 0;
		int start_date, end_date, days_count;
	Customer* cstm;
	Location* rentalLocation;
	Vehicle* rentalVehicle;
	Repository* repo;

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

	void setRentalLocation(Location* location) {
		rentalLocation = location;
	}

	Location* getRentalLocation() {
		return rentalLocation;
	}


	void setRentalVehicle(Vehicle* vehicle) {
		rentalVehicle = vehicle;

	}

	Vehicle* getRentalVehicle() {
		return rentalVehicle;
	}


	/*......*/

	int getRentalSize() { // number of rentals
		int count = rental_id;
		cout << "Rental.h:: getRentalSize: " << count << endl;

		return count;
	}

	int getRental_Id() {
		return rental_id;
	}

	void getRentalBy_Id(int rental_id) {
		if (cstm->attrb_rental_id == rental_id) {
			cout << "You are viewing rental by Id_: " << cstm->getLastName() << endl;
			/*cstm->getFirstName()*/
		}
	}

	void setRentalId_By_Customer(Customer* customer, int new_id) {
		cstm = customer; // setRentalCustomer(customer);
		int id = cstm->getAttrb_Rental_Id(); // getRentalCustomer()->getAttrb_Rental_Id();
		if(id == -1)
			cout << "Rental.h:: setRentalId_By_Customer - This customer has no rental " << endl;
		else {
			rental_id = new_id;
			cstm->updateAttrb_Rental_Id(rental_id);
			cout << "Rental.h:: setRentalId_By_Customer - New Id is: " << getRental_Id() << endl;
		}
	}

	



};
#endif