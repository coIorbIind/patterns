#pragma once

#include <vector>

#include "../drivers/Driver.h"
#include "../passengers/Passenger.h"


class Car {
protected:
    Driver* driver;
public:
    int max_passengers_count;
    vector<Passenger*> passengers;
    Car();
    Car(Driver* driver, int max_passengers_count);
    ~Car();
    bool is_ready();
    virtual bool add_driver(Driver* new_driver);
    virtual bool add_passenger(Passenger* new_passenger);
};
