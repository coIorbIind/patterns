#pragma once

#include "Car.h"
#include "../drivers/TaxiDriver.h"
#include "../passengers/TaxiPassenger.h"


class Taxi : public Car {
private:
    int children_count;
    int children_seats_count;
public:
    Taxi();
    Taxi(TaxiDriver* driver);
    bool add_driver(Driver* new_driver) override;
    bool add_passenger(Passenger* new_passenger) override;
    void add_child_seat();
};
