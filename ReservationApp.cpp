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
#include <iostream>
using namespace std;
using namespace nana;

int main()
{
/*    Customer* customer = new Customer("Olga");
    customer->setLastName("Likken");
    customer->setAddress("140 Paramount View");
    customer->setAge(19);
    customer->setDesignation(true);
    customer->setAddress("140 Paramount View");
    customer->getCustomer_Info(); */   

    //Vehicle* vehicle = new Vehicle(32, "Lamborghini Veratti");
    //vehicle->getVehicle_Info();

    //Location* location = new Location(99, "Vancouver");
    //location->getLocation_Info();

    Repository* repo = new Repository();
    repo->addVehicleToLocation();


    return 0;
}