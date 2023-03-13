#include "BaseCarBuilder.h"

BaseCarBuilder::BaseCarBuilder() {
    this->object = new Car();
}

BaseCarBuilder::~BaseCarBuilder() {
    delete this->object;
}

BaseCarBuilder::BaseCarBuilder(Car *car) {
    this->object = car;
}

void BaseCarBuilder::add_passenger(Passenger *new_passenger) {
    this->object->add_passenger(new_passenger);
}

void BaseCarBuilder::add_driver(Driver *new_driver) {
    this->object->add_driver(new_driver);
}
