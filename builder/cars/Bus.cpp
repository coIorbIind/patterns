#include <iostream>

#include "Bus.h"

using namespace std;

bool Bus::add_driver(Driver *new_driver) {
    if (new_driver->licence != DriverLicence::D) {
        cout << "Driver has wrong licence" << endl;
        return false;
    }
    return Car::add_driver(new_driver);
}

bool Bus::add_passenger(Passenger *new_passenger) {
    BusPassenger* pass = dynamic_cast<BusPassenger*>(new_passenger);
    if (pass == nullptr) {
        cout << "Wrong passenger" << endl;
        return false;
    }
    return Car::add_passenger(new_passenger);
}
