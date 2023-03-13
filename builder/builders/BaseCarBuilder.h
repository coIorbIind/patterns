#pragma once

#include "../cars/Car.h"
#include "../passengers/Passenger.h"
#include "../drivers//Driver.h"


class BaseCarBuilder {
protected:
    Car* object;
    virtual void add_passenger(Passenger* new_passenger);
    virtual void add_driver(Driver* new_driver);
public:
    BaseCarBuilder();
    BaseCarBuilder(Car* car);
    ~BaseCarBuilder();
    Car* get_object() {return this->object;}
};
