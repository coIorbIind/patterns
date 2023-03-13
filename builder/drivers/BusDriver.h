#pragma once

#include "Driver.h"

class BusDriver: public Driver {
public:
    BusDriver(): Driver("fio", DriverLicence::D) {};
    BusDriver(string fio): Driver(fio, DriverLicence::D) {};
    void info();
};
