#include <iostream>

#include "TaxiBuilder.h"

void TaxiBuilder::add_driver() {
    this->object->add_driver(new TaxiDriver());
}

void TaxiBuilder::add_passenger() {
    this->object->add_passenger(new TaxiPassenger());
}

void TaxiBuilder::add_driver(Driver *new_driver) {
    this->object->add_driver(new_driver);
}

void TaxiBuilder::add_passenger(Passenger *new_passenger) {
    this->object->add_passenger(new_passenger);
}

void TaxiBuilder::add_child_seat() {
    Taxi* car = dynamic_cast<Taxi*>(this->object);
    if (car == nullptr) {
        cout << "Wrong passenger" << endl;
    }
    car->add_child_seat();
}
