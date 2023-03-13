#include "BusBuilder.h"

void BusBuilder::add_driver() {
    BaseCarBuilder::add_driver(new BusDriver());
}

void BusBuilder::add_passenger() {
    BaseCarBuilder::add_passenger(new BusPassenger());
}

void BusBuilder::add_driver(Driver *new_driver) {
    this->object->add_driver(new_driver);
}

void BusBuilder::add_passenger(Passenger *new_passenger) {
    this->object->add_passenger(new_passenger);
}
