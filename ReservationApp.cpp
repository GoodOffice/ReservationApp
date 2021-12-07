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



int main()
{
    using namespace std;
    using namespace nana;

    //Define widgets
    form fm;
    fm.outline_size({ 300, 550 });
    fm.caption("Customer");
    label lab{ fm, "Hello, <bold blue size=16>Customers</>" }, desc{ fm, "Create a new customer or select from the list above to continue." };
    lab.format(true);

    combox child(fm, rectangle(20, 3, 150, 30));
    child.push_back("Item 1");
    child.push_back("Item 2");
    child.push_back("Item 3");
    child.push_back("Item 4");
    child.events().selected([](const arg_combox& ar_cbx) { std::cout << ar_cbx.widget.caption() << std::endl; });

    textbox fname(fm), lname(fm), age(fm), address(fm);
    button login(fm), cancel(fm);

    fname.tip_string("Firstname").multi_lines(false);
    lname.tip_string("Lastname").multi_lines(false);
    age.tip_string("Age").multi_lines(false);
    address.tip_string("Address").multi_lines(false);

    login.caption("Add Customer");
    cancel.caption("Cancel");

    fname.events().focus([&login] { // selected or focus
    //fm.close();
        login.caption("Add Customer");

        });

    child.events().selected([&login] { // selected or focus
        //fm.close();
        login.caption("Select");

        });


    cancel.events().click([&fm] {
        fm.close();
        });

    //Define a place for the form.
    place plc(fm);

    // Divide the form into fields
    plc.div("<><weight=80% vertical<><weight=85% vertical <weight=15% title> <vertical gap=10 textboxs arrange=[25,25,25,25]> <weight=6% droplist> < weight=25%> <weight=15% description> <weight=25 buttons> ><>><>");
    //Insert widgets
    plc.field("title") << lab;
    plc.field("description") << desc;
    plc.field("droplist") << child;
    //The field textboxs is vertical, it automatically adjusts the widgets' top and height. 
    plc.field("textboxs") << fname << lname << age << address;
    plc.field("buttons") << login << cancel;
    //Finially, the widgets should be collocated.
    //Do not miss this line, otherwise the widgets are not collocated
    //until the form is resized.
    plc.collocate();

    //auto s = screen();
    //auto pa = s.get_primary().workarea();
    //form fm0, fm1, fm2, fm3;
    ////fm0.move(pa.x, pa.y);
    //fm0.outline_size({ 600, 250 });
    //fm0.caption("screen 0");
    //fm0.show();



    fm.show();
    exec();


}