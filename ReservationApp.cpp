// ReservationApp.cpp : Defines the entry point for the application.//

#include "ReservationApp.h"
#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/tooltip.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/combox.hpp>
#include "Customer.h"
#include "Vehicle.h"
#include "Location.h"
#include "Repository.h"
#include "Rental.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

template <typename T>
void removeElement(std::vector<T>&vec, size_t pos)
{
    std::vector<T>::iterator it = vec.begin();
    std::advance(it, pos);
    vec.erase(it);
}

int main()
{
    using namespace std;
    using namespace nana;


    //Define widgets
    auto s = screen();
    auto pa = s.get_primary().workarea();
    form fm1, fm2, fm3, fm4;

    fm1.move(pa.x + pa.width / 5.5, pa.y + 350);
    fm1.outline_size({ 300, 550 });
    fm1.caption("Customer");

    fm2.move(pa.x + pa.width / 2.95, pa.y + 350);
    fm2.outline_size({ 300, 550 });
    fm2.caption("Rental Location");

    fm3.move(pa.x + pa.width / 2.0185, pa.y + 350);
    fm3.outline_size({ 300, 550 });
    fm3.caption("Car");

    fm4.move(pa.x + pa.width / 1.534, pa.y + 350);
    fm4.outline_size({ 300, 550 });
    fm4.caption("Rental Log");

    label lab{ fm1, "Hello, <bold blue size=16>Customers</>" }, desc{ fm1, "Create a new customer or select from the list above to continue." };
    lab.format(true);

    vector<Customer*> customers;
    Customer* customer;
    Customer* pChosenCustomer = nullptr;
    int customerIDincr = 1, locationIDIncr = 1, vehiculeIDIncr = 1, rentalIDIncr = 1;
    combox child(fm1, rectangle(20, 3, 150, 30));
    //child.push_back("Item 1");
    //child.push_back("Item 2");
    //child.push_back("Item 3");
    //child.push_back("Item 4");
    child.events().selected([&](const arg_combox& ar_cbx) {
        std::cout << ar_cbx.widget.caption() << std::endl;
        //auto custFilter = [&](auto cust) { return cust.getFullName().compare(txt) == 0; };
        auto txt = child.text(child.option());

        cout << "inSelected: " << txt << endl; // DEGUG

        for (auto* cust : customers)
        {
            cout << "inSelected loop names: " << cust->getFullName() << endl;  // DEGUG
            if (cust->getFullName().compare(txt) == 0) {
                pChosenCustomer = cust; //store the pointer to the chosen customer;
                cout << "inSelected: Current user: " << customer->fullName << endl; // DEGUG
                cout << "inSelected: USER: " << pChosenCustomer->fullName << endl; // DEGUG
                customer = pChosenCustomer;
                cout << "inSelected: Current user: (AFTER) " << customer->fullName << endl; // DEGUG
            }
        }
        });

    /* ------- Customers <start>------- */

    textbox fname(fm1), lname(fm1), age(fm1), address(fm1);
    button removeBtn(fm1), validateCSButton(fm1), cancel(fm1);


    fname.tip_string("Firstname").multi_lines(false);
    lname.tip_string("Lastname").multi_lines(false);
    age.tip_string("Age").multi_lines(false);
    address.tip_string("Address").multi_lines(false);

    removeBtn.caption("Remove");
    removeBtn.enabled(false);
    validateCSButton.caption("Add Customer");
    validateCSButton.enabled(false);
    cancel.caption("Cancel");




    /* Creates a customer with textbox values*/
    validateCSButton.events().click([&] {
        bool exist = false;
        string fnameTyped, lnameTyped, ageTyped, addressType;
        fname.getline(0, fnameTyped);
        lname.getline(0, lnameTyped);
        age.getline(0, ageTyped);
        address.getline(0, addressType);

        //cout << "First name from text:" << fnameTyped << endl; // DEBUG    
        customer = new Customer();

        customer->setFirstName(fnameTyped);
        customer->setLastName(lnameTyped);
        customer->setFullName(fnameTyped, lnameTyped);
        customer->setAge(stoi(ageTyped));
        customer->setAddress(addressType);
        customer->id = customerIDincr;

        string firstName = fnameTyped;
        string lastName = lnameTyped;


        cout << "\nCustomers size=" << customers.size() << endl;
        customerIDincr++;
        int index = 0;
        for (vector<Customer*>::iterator itr = customers.begin(); itr != customers.end(); itr++)
        {
            string comp_fname = customers.at(index)->getFirstName();
            string comp_lname = customers.at(index)->getLastName();
            cout << "comp_firstname: " << comp_fname << endl;
            cout << "comp_lastname: " << comp_lname << endl;
            if (firstName == comp_fname && lastName == comp_lname) {
                exist = true;
                cout << "Customer already exists." << endl;
                break;
            }
            else {
                exist = false;
                cout << "Added a new customer." << endl;
            }
            index++;
        }

        if (exist == false) {
            customer->getCustomer_Info();
            customers.push_back(customer);
            string fullNameString = firstName + " " + lastName;
            child.push_back(fullNameString); // back to string
        }

        });

    child.events().focus([&] { // selected or focus

        //toggleView(fl);
        if (customers.empty()) {
            cout << "Customer list is empty." << endl; // DEGUG
            removeBtn.enabled(false);
        }

        });

    removeBtn.events().click([&] {
        if (pChosenCustomer != nullptr) {
            cout << "Chosen customer is at least one." << endl; // DEBUG

            int index = 0;
            auto it = customers.begin();
            while (it != customers.end())
            {
                try {
                    if (pChosenCustomer->getFullName() == customers.at(index)->fullName)
                    {
                        it = customers.erase(it);
                        child.erase(index);
                    }
                    else {
                        ++it;
                    }
                    ++index;
                }
                catch (out_of_range exc) // catching out of range exception
                {
                    cout << "Out of range exception" << endl;
                    break;
                }
            }
            //for (Customer* const& i : customers) {
            //    std::cout << i << ' ';
            //}
        }
        else {
            cout << "Chosen customer is empty." << endl; // DEGUG
        }
        });

    fname.events().focus([&] { // selected or focus
    //fm.close();
        validateCSButton.caption("Add Customer");
        validateCSButton.enabled(true);

        });









    child.events().selected([&] { // selected or focus
        //fm.close();

        removeBtn.enabled(true);
        validateCSButton.caption("Next");
        validateCSButton.enabled(true);


        });


    cancel.events().click([&fm1] {
        fm1.close();
        });

    //Define a place for the form.
    place plc(fm1);

    // Divide the form into fields
    plc.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist>  < weight=5%> <weight=25 removeBtn> < weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");
    //Insert widgets
    plc.field("title") << lab;
    plc.field("description") << desc;
    plc.field("droplist") << child;
    plc.field("removeBtn") << removeBtn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc.field("textboxs") << fname << lname << age << address;
    plc.field("buttons") << cancel << validateCSButton;
    //Finially, the widgets should be collocated.
    //Do not miss this line, otherwise the widgets are not collocated
    //until the form is resized.


    /* ------- Customers </end> ------- */

    label location_headerText{ fm2, "Hello, <bold red size=16>Locations</>" }, loc_screen_desc{ fm2, "You can add new rental locations to the database." };
    location_headerText.format(true);

    vector<Location*> locations;
    Location* location;
    Location* pChosenLocation = nullptr;

    combox droplistLOCView(fm2, rectangle(20, 3, 150, 30));

    vector<Vehicle*> vehicles;
    combox droplistVEHView(fm3, rectangle(20, 3, 150, 30));
    //droplistLOCView.events().selected([](const arg_combox& ar_cbx) { std::cout << ar_cbx.widget.caption() << std::endl; });

    droplistLOCView.events().selected([&](const arg_combox& ar_cbx) {
        std::cout << ar_cbx.widget.caption() << std::endl;
        auto txt = droplistLOCView.text(droplistLOCView.option());

        cout << "inSelected: " << txt << endl; // DEGUG

        for (auto* loc : locations)
        {
            cout << "inSelected loop city: " << loc->getLocation_Name() << endl; // // DEGUG
            if (loc->getLocation_Name().compare(txt) == 0) {
                pChosenLocation = loc; //store the pointer to the chosen customer;
                cout << "inSelected: Current location: " << location->getLocation_Name() << endl; // DEGUG
                cout << "inSelected: LOCATION: " << pChosenLocation->getLocation_Name() << endl; // DEGUG
                location = pChosenLocation;
                cout << "inSelected: Current location: (AFTER) " << location->getLocation_Name() << endl; // DEGUG

            }
        }

        });

    textbox city_name(fm2);
    button  remove_locationBtn(fm2), clear(fm2), validateLCButton(fm2);

    city_name.tip_string("City").multi_lines(false);
    remove_locationBtn.caption("Remove");
    remove_locationBtn.enabled(false);

    clear.caption("Clear All");
    clear.enabled(false);

    validateLCButton.caption("Add location");
    validateLCButton.enabled(false);

    validateLCButton.events().click([&] {
        bool exist = false;
        string cityTyped;
        city_name.getline(0, cityTyped);

        location = new Location();
        location->setLocation_Name(cityTyped);
        location->setLocation_Id(locationIDIncr);

        cout << "\nLocation size=" << locations.size() << endl; // DEBUG
        locationIDIncr++;
        int index = 0;
        for (vector<Location*>::iterator itr = locations.begin(); itr != locations.end(); itr++)
        {
            string comp_city = locations.at(index)->getLocation_Name();
            cout << "comp_city: " << comp_city << endl;
            if (cityTyped == comp_city) {
                exist = true;
                cout << "This location exists already." << endl;
                break;
            }
            else {
                exist = false;
                cout << "Added a new location." << endl;
            }
            index++;
        }

        if (exist == false) {
            location->getLocation_Info();
            locations.push_back(location);
            droplistVEHView.clear();
            string cityString = location->getLocation_Name();
            droplistLOCView.push_back(cityString); // back to string
        }

        });

    remove_locationBtn.events().click([&] {
        if (pChosenLocation != nullptr) {
            cout << "Chosen location is at least one." << endl; // DEBUG

            int index = 0;
            auto it = locations.begin();
            while (it != locations.end())
            {
                try {
                    if (pChosenLocation->getLocation_Name() == locations.at(index)->location_name)
                    {
                        it = locations.erase(it);
                        droplistLOCView.erase(index);
                    }
                    else {
                        ++it;
                    }
                    ++index;
                }
                catch (out_of_range exc) // catching out of range exception
                {
                    cout << "Out of range exception" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Chosen location is empty." << endl; // DEGUG
        }
        });

    city_name.events().focus([&] { // selected or focus
    //fm.close();
        validateLCButton.caption("Add Location");
        validateLCButton.enabled(true);

        });

    droplistLOCView.events().focus([&] { // selected or focus
        if (locations.empty()) {
            cout << "Location list is empty." << endl; // DEGUG
            remove_locationBtn.enabled(false);
        }
        });

    bool clearVEHList = false;

    

    droplistLOCView.events().selected([&] { // selected or focus
        remove_locationBtn.enabled(true);
        validateLCButton.caption("Next");
        remove_locationBtn.enabled(true);

        city_name.caption(""); // clearing textbox
        droplistVEHView.enabled(true);
        droplistVEHView.clear();
        //droplistVEHView.caption("test");
        int locationCapacity = location->getCapacity();

        if (locationCapacity < 0) {
            droplistVEHView.caption("");

        }
        else {
            droplistVEHView.caption("");
            vehicles = location->getVehicles();
            //vector<Vehicle*> veh = location->getVehicles();

            for (int i = 0; i < locationCapacity; i++) {

                droplistVEHView.push_back(vehicles.at(i)->getVehicle_Name());

            }
        }

        });


    place plc_location(fm2);

    // Divide the form into fields
    plc_location.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist>  < weight=5%> <weight=25 removeBtn> < weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");

    //Insert widgets
    plc_location.field("title") << location_headerText;
    plc_location.field("description") << loc_screen_desc;
    plc_location.field("droplist") << droplistLOCView;
    plc_location.field("removeBtn") << remove_locationBtn;
    plc_location.field("textboxs") << city_name;
    plc_location.field("buttons") << clear << validateLCButton;


    /* ------- Location </end> ------- */


    label vehicle_headerText{ fm3, "Hello, <bold green size=16>Vehicles</>" }, veh_screen_desc{ fm3, "You can add new vehicles to the repository." };
    vehicle_headerText.format(true);

    
    Vehicle* vehicle;
    Vehicle* pChosenVehicle = nullptr;

    droplistVEHView.enabled(false);

    droplistVEHView.events().selected([&](const arg_combox& ar_cbx) {
        std::cout << ar_cbx.widget.caption() << std::endl;
        auto txt = droplistVEHView.text(droplistVEHView.option());

        cout << "inSelected: " << txt << endl; // DEGUG

        for (auto* veh : vehicles)
        {
            cout << "inSelected loop city: " << veh->getVehicle_Name() << endl; // // DEGUG
            if (veh->getVehicle_Name().compare(txt) == 0) {
                pChosenVehicle = veh; //store the pointer to the chosen customer;
                cout << "inSelected: Current vehicle: " << vehicle->getVehicle_Name() << endl; // DEGUG
                cout << "inSelected: VEHICLE: " << pChosenVehicle->getVehicle_Name() << endl; // DEGUG
                vehicle = pChosenVehicle;
                cout << "inSelected: Current vehicle: (AFTER) " << vehicle->getVehicle_Name() << endl; // DEGUG

            }
        }
        });

    textbox vehicle_name(fm3);
    button  remove_vehicleBtn(fm3), clear_veh(fm3), validateVHButton(fm3);

    vehicle_name.tip_string("Vehicle Model").multi_lines(false);
    remove_vehicleBtn.caption("Remove");
    remove_vehicleBtn.enabled(false);

    clear_veh.caption("Clear All");
    clear_veh.enabled(false);

    validateVHButton.caption("Add car");
    validateVHButton.enabled(false);

    validateVHButton.events().click([&] {
        bool exist = false;
        string vehicleTyped;
        vehicle_name.getline(0, vehicleTyped);

        vehicle = new Vehicle();
        vehicle->setVehicle_Name(vehicleTyped);
        vehicle->setVehicle_Id(vehiculeIDIncr);

        cout << "\nVehicle size=" << vehicles.size() << endl; // DEBUG
        vehiculeIDIncr++;
        int index = 0;
        for (vector<Vehicle*>::iterator itr = vehicles.begin(); itr != vehicles.end(); itr++)
        {
            string comp_car = vehicles.at(index)->getVehicle_Name();
            cout << "comp_car: " << comp_car << endl;
            if (vehicleTyped == comp_car) {
                exist = true;
                cout << "This vehicle exists already." << endl;
                break;
            }
            else {
                exist = false;
                cout << "Added a new vehicle." << endl;
            }
            index++;
        }

        if (exist == false) {
            location->addVehicles(vehicle);
            location->getVehicles();
            vehicle->getVehicle_Info();
            location->getLocation_Info();
            vehicles.push_back(vehicle);
            string locationString = vehicle->getVehicle_Name();
            droplistVEHView.push_back(locationString); // back to string
        }

        });


    remove_vehicleBtn.events().click([&] {
        if (pChosenVehicle != nullptr) {
            cout << "Chosen vehicle is at least one." << endl; // DEBUG

            int index = 0;
            auto it = vehicles.begin();
            while (it != vehicles.end())
            {
                try {
                    if (pChosenVehicle->getVehicle_Name() == vehicles.at(index)->vehicle_name)
                    {
                        it = vehicles.erase(it);
                        droplistVEHView.erase(index);
                    }
                    else {
                        ++it;
                    }
                    ++index;
                }
                catch (out_of_range exc) // catching out of range exception
                {
                    cout << "Out of range exception" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Chosen vehicle is empty." << endl; // DEGUG
        }
        });

    vehicle_name.events().focus([&] { // selected or focus
        validateVHButton.caption("Add Vehicle");
        validateVHButton.enabled(true);
        });

    droplistVEHView.events().focus([&] { // selected or focus
        if (vehicles.empty()) {
            cout << "Vehicle list is empty." << endl; // DEGUG
            remove_locationBtn.enabled(false);
        }
        });

    droplistVEHView.events().selected([&] { // selected or focus
        remove_vehicleBtn.enabled(true);
        validateVHButton.caption("Next");
        remove_vehicleBtn.enabled(true);
        vehicle_name.caption("");
        });



    place plc_vehicle(fm3);

    // Divide the form into fields
    plc_vehicle.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist> <weight=5%> <weight=25 removeBtn> <weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");

    //Insert widgets
    plc_vehicle.field("title") << vehicle_headerText;
    plc_vehicle.field("description") << veh_screen_desc;
    plc_vehicle.field("droplist") << droplistVEHView;
    plc_vehicle.field("removeBtn") << remove_vehicleBtn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc_vehicle.field("textboxs") << vehicle_name;
    plc_vehicle.field("buttons") << clear_veh << validateVHButton;

    /* ------- Vehicle </end> ------- */

    label rental_headerText{ fm4, "Hello, <bold black size=16>Rentals</>" }, rental_screen_desc{ fm4, "Details: --" };
    rental_headerText.format(true);

    vector<Rental*> rentals;
    Rental* rental;
    Rental* pChosenRental = nullptr;

    //combox droplistRENTALView(fm4, rectangle(20, 3, 150, 30));

    //droplistRENTALView.events().selected([&](const arg_combox& ar_cbx) {
    //    std::cout << ar_cbx.widget.caption() << std::endl;
    //    auto txt = droplistRENTALView.text(droplistRENTALView.option());

    //    cout << "inSelected: " << txt << endl; // DEGUG

    //    for (auto* rtl : rentals)
    //    {
    //        cout << "inSelected loop city: " << rtl->getRentalVehicle()->getVehicle_Name() << endl; // // DEGUG
    //        if (rtl->getRentalVehicle()->getVehicle_Name().compare(txt) == 0)
    //            pChosenRental = rtl; //store the pointer to the chosen customer;
    //    }
    //    });

    textbox rental_startDate(fm4), rental_endDate(fm4);
    button  viewActiveRentedCarBttn(fm4), viewLateReturnCarBttn(fm4), simulateBtn(fm4), returnBttn(fm4), validateRETLButton(fm4);

    rental_startDate.tip_string("Start date").multi_lines(false);
    rental_endDate.tip_string("End date").multi_lines(false);
    viewActiveRentedCarBttn.caption("View all Active Rentals ");
    viewActiveRentedCarBttn.enabled(true);

    viewLateReturnCarBttn.caption("View all Late Returns ");
    viewLateReturnCarBttn.enabled(true);

    simulateBtn.caption("Simulate (skip days)");
    simulateBtn.enabled(false);

    returnBttn.caption("Return a car");
    returnBttn.enabled(false);

    validateRETLButton.caption("Create Rental");
    //validateRETLButton.enabled(false);

    validateRETLButton.events().click([&] {
        bool exist = false;
        string beginDateTyped, endDateTyped;
        rental_startDate.getline(0, beginDateTyped);
        rental_endDate.getline(0, endDateTyped);

        rental = new Rental();
        rental->createNewRental(customer);
        rental->setBegins_Date(beginDateTyped);
        rental->setReturn_Date(endDateTyped);
        rental->getBegins_Date();
        rental->getReturn_Date();

        rental->getRentalCustomer()->getCustomer_Info();
        string name = rental->getRentalCustomer()->getFullName();
        string address = rental->getRentalCustomer()->getAddress();
        int age = rental->getRentalCustomer()->getAge();
        int  designation = rental->getRentalCustomer()->getReputation();

        //Repository* repository = new Repository();
       // rental->setRental_Repository(repository);

        rental->setRentalLocation(location);
        Location* rentingLocation = rental->getRentalLocation();
        rental->setRentalVehicle(vehicle);
        Vehicle* rentingVehicle = rental->getRentalVehicle();
        string veh_name = rentingVehicle->getVehicle_Name();
        string rep = " ";
        if (designation == 0)
            rep = "Regular Customer";
        else if (designation == 1)
            rep = "Preferred Customer";

        rental_screen_desc.caption(name + "\n" +
            address +
            to_string(age) + " ~ years old " + "\n" +
            "Reputation: " + rep + "\n" +
            "Model: " + veh_name







        );
        });


    viewActiveRentedCarBttn.events().click([&] {
        if (pChosenRental != nullptr) {
            cout << "Chosen rentals is at least one." << endl; // DEBUG

            int index = 0;
            auto it = rentals.begin();
            while (it != rentals.end())
            {
                try {
                    if (pChosenRental->getRentalVehicle()->getVehicle_Name() == rentals.at(index)->getRentalVehicle()->getVehicle_Name())
                    {
                        it = rentals.erase(it);
                        //droplistRENTALView.erase(index);
                    }
                    else {
                        ++it;
                    }
                    ++index;
                }
                catch (out_of_range exc) // catching out of range exception
                {
                    cout << "Out of range exception" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Chosen rental is empty." << endl; // DEGUG
        }
        });

    city_name.events().focus([&] { // selected or focus

        //validateRETLButton.caption("Add Location");
        validateRETLButton.enabled(true);

        });

    //droplistRENTALView.events().focus([&] { // selected or focus
    //    if (rentals.empty()) {
    //        cout << "Rental list is empty." << endl; // DEGUG
    //        viewActiveRentedCarBttn.enabled(false);
    //    }
    //    });

    //droplistRENTALView.events().selected([&] { // selected or focus
    //    viewActiveRentedCarBttn.enabled(true);
    //    validateRETLButton.caption("View Rental");
    //    viewActiveRentedCarBttn.enabled(true);
    //    });



    place plc_rental(fm4);

    // Divide the form into fields
    plc_rental.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]><weight=5%> <vertical gap=10 actionButtons arrange=[25,25,25,25]> <weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");

    //Insert widgets
    plc_rental.field("title") << rental_headerText;
    plc_rental.field("description") << rental_screen_desc;
    // plc_rental.field("droplist") << droplistRENTALView;
    plc_rental.field("actionButtons") << simulateBtn << viewActiveRentedCarBttn << viewLateReturnCarBttn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc_rental.field("textboxs") << rental_startDate << rental_endDate;
    plc_rental.field("buttons") << returnBttn << validateRETLButton;



    plc.collocate();
    plc_location.collocate();
    plc_vehicle.collocate();
    plc_rental.collocate();




    //fm1.show();
    fm2.show();
    fm3.show();
    //fm4.show();

    exec();


}