#include <iostream>

#include "Taxi.h"

using namespace std;

Taxi::Taxi(TaxiDriver *driver) : Car(driver, 4) {
    this->children_seats_count = 0;
    this->children_count = 0;
}

Taxi::Taxi(): Car(nullptr, 4) {
    this->children_seats_count = 0;
    this->children_count = 0;
}


bool Taxi::add_driver(Driver *new_driver) {
    if (new_driver->licence != DriverLicence::B) {
        cout << "Driver has wrong licence" << endl;
        return false;
    }
    return Car::add_driver(new_driver);
}

bool Taxi::add_passenger(Passenger *new_passenger) {
    TaxiPassenger* pass = dynamic_cast<TaxiPassenger*>(new_passenger);
    if (pass == nullptr) {
        cout << "Wrong passenger" << endl;
        return false;
    }
    if (pass->category == TaxiPassengerCategory::Child) {
        if (this->children_seats_count - this->children_count <= 0) {
            cout << "There are no free child seats" << endl;
            return false;
        }
        bool is_set = Car::add_passenger(new_passenger);
        if (is_set) {
            this->children_count += 1;
        }
        return is_set;
    }
    return Car::add_passenger(new_passenger);
}

void Taxi::add_child_seat() {
    if (this->children_seats_count == 3) {
        cout << "Already have 3 child seats" << endl;
        return;
    }
    this->children_seats_count += 1;
}
