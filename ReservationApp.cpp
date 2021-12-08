// ReservationApp.cpp : Defines the entry point for the application.
//

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
void removeElement(std::vector<T>& vec, size_t pos)
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
    Customer* pChosenCustomer = nullptr;
    int incr = 1;
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
            cout << "inSelected loop names: " << cust->getFullName() << endl; // // DEGUG
            if (cust->getFullName().compare(txt) == 0)
                pChosenCustomer = cust; //store the pointer to the chosen customer;
        }
        });

    /* ------- Customers <start>------- */

    textbox fname(fm1), lname(fm1), age(fm1), address(fm1);
    button removeBtn(fm1), selectBtn(fm1), cancel(fm1);
    

    fname.tip_string("Firstname").multi_lines(false);
    lname.tip_string("Lastname").multi_lines(false);
    age.tip_string("Age").multi_lines(false);
    address.tip_string("Address").multi_lines(false);

    removeBtn.caption("Remove");
    removeBtn.enabled(false);
    selectBtn.caption("Add Customer");
    selectBtn.enabled(false);
    cancel.caption("Cancel");

    


    /* Creates a customer with textbox values*/
    selectBtn.events().click([&] {
        bool exist = false;
        string fnameTyped, lnameTyped, ageTyped, addressType;
        fname.getline(0, fnameTyped);
        lname.getline(0, lnameTyped);
        age.getline(0, ageTyped);
        address.getline(0, addressType);

        //cout << "First name from text:" << fnameTyped << endl; // DEBUG    
        Customer* customer = new Customer();
        
        customer->setFirstName(fnameTyped);
        customer->setLastName(lnameTyped);
        customer->setFullName(fnameTyped, lnameTyped);
        customer->setAge(stoi(ageTyped));
        customer->setAddress(addressType);
        customer->id = incr;

        string firstName = fnameTyped;
        string lastName = lnameTyped;
        

        cout << "\Customers size=" << customers.size() << endl;
        incr++;
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
                    cout << "Customer is new." << endl;
                }
            index++;
        }

        if (exist == false){
            customer->getCustomer_Info();
            customers.push_back(customer);
            string fullName = firstName + " " + lastName;
            child.push_back(fullName); // back to string
        }

        });

    child.events().focus([&] { // selected or focus

        //toggleView(fl);
        if (customers.empty()) {
            cout << "List is empty." << endl; // DEGUG
            removeBtn.enabled(false);
        }

        });

    removeBtn.events().click([&] {
        if(pChosenCustomer != nullptr){
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

    fname.events().focus([&selectBtn] { // selected or focus
    //fm.close();
        selectBtn.caption("Add Customer");
        selectBtn.enabled(true);

        });









    child.events().selected([&] { // selected or focus
        //fm.close();

        removeBtn.enabled(true);
        selectBtn.caption("Next");
        selectBtn.enabled(true);


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
    plc.field("buttons") << cancel << selectBtn;
    //Finially, the widgets should be collocated.
    //Do not miss this line, otherwise the widgets are not collocated
    //until the form is resized.


    /* ------- Customers </end> ------- */

    label location_headerText{ fm2, "Hello, <bold red size=16>Locations</>" }, loc_screen_desc{ fm2, "You can add new rental locations to the database." };
    location_headerText.format(true);

    textbox location_name(fm2);
    button  remove_locationBtn(fm2), clear(fm2), validate_location(fm2);

    location_name.tip_string("City").multi_lines(false);
    remove_locationBtn.caption("Remove");
    remove_locationBtn.enabled(false);

    clear.caption("Clear All");
    clear.enabled(false);
    
    validate_location.caption("Add location");
    validate_location.enabled(false);

    combox lc_droplist(fm2, rectangle(20, 3, 150, 30));
    lc_droplist.push_back("O.. 1");
    lc_droplist.push_back("W.. 2");
    lc_droplist.push_back("S.. 3");
    lc_droplist.push_back("U.. 4");
    lc_droplist.events().selected([](const arg_combox& ar_cbx) { std::cout << ar_cbx.widget.caption() << std::endl; });


    place plc_location(fm2);

    // Divide the form into fields
    plc_location.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist>  < weight=5%> <weight=25 removeBtn> < weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");
    
    //Insert widgets
    plc_location.field("title") << location_headerText;
    plc_location.field("description") << loc_screen_desc;
    plc_location.field("droplist") << lc_droplist;
    plc_location.field("removeBtn") << remove_locationBtn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc_location.field("textboxs") << location_name;
    plc_location.field("buttons") << clear << validate_location;


    /* ------- Location </end> ------- */

    label vehicle_headerText{ fm3, "Hello, <bold green size=16>Vehicles</>" }, veh_screen_desc{ fm3, "You can add new vehicles to the repository." };
    vehicle_headerText.format(true);

    textbox vehicle_name(fm3);
    button  remove_vehicleBtn(fm3), clear_veh(fm3), validate_vehicle(fm3);

    vehicle_name.tip_string("Car Model").multi_lines(false);
    remove_vehicleBtn.caption("Remove");
    remove_vehicleBtn.enabled(false);

    clear_veh.caption("Clear All");
    clear_veh.enabled(false);

    validate_vehicle.caption("Add car");
    validate_vehicle.enabled(false);

    combox veh_droplist(fm3, rectangle(20, 3, 150, 30));
    veh_droplist.push_back("Avantador");
    veh_droplist.push_back("Urus");
    veh_droplist.push_back("Range Rover");
    veh_droplist.push_back("Mercedes 4Matic");
    veh_droplist.events().selected([](const arg_combox& ar_cbx) { std::cout << ar_cbx.widget.caption() << std::endl; });


    place plc_vehicle(fm3);

    // Divide the form into fields
    plc_vehicle.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist> <weight=5%> <weight=25 removeBtn> <weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");

    //Insert widgets
    plc_vehicle.field("title") << vehicle_headerText;
    plc_vehicle.field("description") << veh_screen_desc;
    plc_vehicle.field("droplist") << veh_droplist;
    plc_vehicle.field("removeBtn") << remove_vehicleBtn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc_vehicle.field("textboxs") << vehicle_name;
    plc_vehicle.field("buttons") << clear_veh << validate_vehicle;

    /* ------- Vehicle </end> ------- */


    label rental_headerText{ fm4, "Hello, <bold black size=16>Rentals</>" }, rental_screen_desc{ fm4, "You can add new rentals to the repository." };
    rental_headerText.format(true);

    textbox rental_startDate(fm4), rental_endDate(fm4);
    button  remove_rentalBtn(fm4), clear_rental(fm4), validate_rental(fm4);

    rental_startDate.tip_string("Start date").multi_lines(false);
    rental_endDate.tip_string("End date").multi_lines(false);
    remove_rentalBtn.caption("Remove");
    remove_rentalBtn.enabled(false);

    clear_rental.caption("Return a car");
    clear_rental.enabled(false);

    validate_rental.caption("Submit Rental");
    validate_rental.enabled(false);

    combox rental_droplist(fm4, rectangle(20, 3, 150, 30));
   rental_droplist.push_back("Rental 1 - Customer A");
   rental_droplist.push_back("Rental 2 - Customer B");
   rental_droplist.push_back("Rental 3 - Customer C");
   rental_droplist.push_back("Rental 4 - Customer D");
   rental_droplist.events().selected([](const arg_combox& ar_cbx) { std::cout << ar_cbx.widget.caption() << std::endl; });


    place plc_rental(fm4);

    // Divide the form into fields
    plc_rental.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist> <weight=5%> <weight=25 removeBtn> <weight=15%> <weight=15% description> <weight=25 buttons gap=14> ><>><>");

    //Insert widgets
    plc_rental.field("title") << rental_headerText;
    plc_rental.field("description") <<rental_screen_desc;
    plc_rental.field("droplist") <<rental_droplist;
    plc_rental.field("removeBtn") << remove_rentalBtn;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc_rental.field("textboxs") << rental_startDate << rental_endDate;
    plc_rental.field("buttons") << clear_rental << validate_rental;



    plc.collocate();
    plc_location.collocate();
    plc_vehicle.collocate();
    plc_rental.collocate();



    fm1.show();
   //fm2.show();
    //fm3.show();
    //fm4.show();

    exec();


}

