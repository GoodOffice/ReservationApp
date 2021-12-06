// ReservationApp.cpp : Defines the entry point for the application.
//

#include "ReservationApp.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include "Customer.h"
#include "Vehicle.h"
#include "Location.h"
#include "Repository.h"
#include "Rental.h"
#include <iostream>
using namespace std;
using namespace nana;

int main()
{
 

    //Vehicle* vehicle = new Vehicle(32, "Lamborghini Veratti");
    //vehicle->getVehicle_Info();

    //Location* location = new Location(99, "Vancouver");
    //location->getLocation_Info();
    
    Repository* repo = new Repository();
    repo->addVehicleToLocation();
    //repo->getVehicle_Info(); // accessible if Repository extends : public Location

    //Customer* customer = new Customer("Olga");
     /*TO_DO: epand Customer constructor parameter list to have all necessary or below properties */
    Customer* customer1 = new Customer();
    customer1->setLastName("Likken");
    customer1->setAddress("140 Paramount View");
    customer1->setAge(19);
    customer1->setDesignation(true);
    customer1->setAddress("140 Paramount View");
    //customer1->getCustomer_Info(); 

    Customer* customer2 = new Customer();
    customer2->setLastName("Debby");
    customer2->setAddress("140 Paramount View");
    customer2->setAge(24);
    customer2->setDesignation(true);
    customer2->setAddress("9400 Pinterest Avenue");

    
   // if (customer1->getAge() < 18)
   //     printf("Sorry, you must be 18+ for rentals.");
   //else {
        Rental* rental = new Rental();
        rental->createNewRental(customer1);
        rental->getRentalBy_Id(1); // works sequentially by the element
        rental->createNewRental(customer2);
        //rental->getRentalSize();
        rental->getRentalCustomer()->getCustomer_Info();
   // }
    
        customer1->getAttrb_Rental_Id();

        rental->getRentalBy_Id(2); /*TO_DO: catch exception for when number is higher than size of all rentals*/
        cout << "Setting new Id... " << endl;
        //rental->setRentalId_By_Customer(customer1, 87);
        //customer1->getAttrb_Rental_Id();

        /* --- Setting up rental location --- */
        Repository* repository = new Repository();
        vector<Location*> location_List = repository->getLocationList();
        int sizeLoc = location_List.size();
        /* TO_DO: Print location list here using iterator */

        /* Get a location by Id */
        Location* location = location_List.at(3);
        string loc_name = location->getLocation_Name();

        cout << "Location size... " << sizeLoc << endl;
        cout << "Location name... " << loc_name << endl;

        rental->setRentalLocation(location);

        /* --- Setting up rental vehicle --- */

        vector<Vehicle*> vehicle_List = repository->getVehicleList();
        int sizeVeh = vehicle_List.size();
        /* TO_DO: Print location list here using iterator */

        /* Get a location by Id */
        Vehicle* vehicle = vehicle_List.at(3);
        string veh_name = vehicle->getVehicle_Name();

        //cout << "Vehicle size... " << sizeVeh << endl;
        //cout << "Vehicle name... " << veh_name << endl;

        rental->setRentalVehicle(vehicle);
        rental->getRentalVehicle();

        cout << "This customer selected a ... " << rental->getRentalVehicle()->getVehicle_Name() << endl;



        

    return 0;
}