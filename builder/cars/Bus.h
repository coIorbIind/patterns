#pragma once

#include "Car.h"
#include "../drivers/BusDriver.h"
#include "../passengers/BusPassenger.h"


class Bus : public Car {
public:
    Bus() : Car(nullptr, 30) {};
    Bus(BusDriver *driver) : Car(driver, 30) {};
    bool add_driver(Driver* new_driver) override;
    bool add_passenger(Passenger* new_passenger) override;
};