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
		int start_date = 0, return_date = 0;
		int time_elapsed = 0;
		int days_count = 0;
	Customer* cstm;
	Location* rentalLocation;
	Vehicle* rentalVehicle;
	vector<Rental*> rentals;
	Repository* repo;

	Rental(){ }
	Rental(int r_id, Customer* customer) {
		/*rental_id = r_id;*/
		setRentalCustomer(customer);
	}

	
	void init(Customer* customer) {

		setRentalCustomer(customer);				
		customer->setAttrb_Rental_Id(rental_id); // DEBUG - comment out to skip exception

	}

	void updateRentalID() {
		rental_id++;
	}

	void addRentals(Rental* rental) {
		rentals.push_back(rental);
		rental_id++;
	}

	vector<Rental*> getRentals() {

		int index = 0;
		for (vector<Rental*>::iterator itr = rentals.begin(); itr != rentals.end(); itr++)
		{
			try {
				/*vehicles.push_back(v);*/
				cout << "Rental.h:: getRentals - RENTAL ID: "  << rental_id << endl;
				cout << "Rental.h:: getRentals - RENTAL of: "  << rentals.at(index)->getRentalVehicle()->getVehicle_Name()<< endl;
			}
			catch (out_of_range exc)
			{
				cout << "Out of range exception" << endl;
			}

			index++;
		}
		return rentals;

	}
	void setRental_Repository(Repository* repository) {
		repo = repository;

	}

	Repository* getRental_Repository() {
		return repo;
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

	int getBegins_Date() {
		cout << "Rental.h:: getBegins_Date - Begins date ## "<< start_date << endl;
		return start_date;
	}

	void setBegins_Date(string start) {
		start_date = stoi(start);

	}

	int getReturn_Date() {
		cout << "Rental.h:: getReturn_Date - Return date ## " << return_date << endl;
		return return_date;
	}

	void setReturn_Date(string end) {
		return_date = stoi(end);
	}

	void bonoCheck(Customer* customer) {
		cstm = customer;
		if (cstm->getAge() <= 25) {
			applyCharge();			
		}
		else {
			if (cstm->getReputation() == cstm->isFavorite) {
				applyPromo();
			}
			else
				cout << "Rental.h:: getReputation Standard payment fees  " << endl; 
		}			
	}

	void applyCharge() {
		cout << "Rental.h:: applyCharge Additional Charge of 20% applied " << endl;
	}

	void applyPromo() {
		cout << "Rental.h:: applyPromo 20% off Promotion applied " << endl;
	}

	void dayIncrementer() {
		
		//int expected_day = 0;
		time_elapsed = return_date - (start_date + days_count); // 10
		

		time_elapsed--; // 9
		days_count++;

		int change = start_date + days_count;
	

		if(change == return_date)
			cout << "Rental.h:: dayIncremental - You've reached return date: " << return_date << endl;

		else if (change > return_date) {
			cout << "Rental.h:: dayIncremental - You've MAXED out your return date - EXPECTED: " << return_date << endl;
			cout << "Rental.h:: dayIncremental - You've MAXED out your return date - CURRENT: " << start_date + days_count << endl;
		}


		cout << "Rental.h:: dayIncremental - time elapsed: " << time_elapsed << endl;
		cout << "Rental.h:: dayIncremental - days count: " << days_count << endl;
	}


};
#endif