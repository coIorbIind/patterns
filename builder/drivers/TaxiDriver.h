#pragma once

#include "Driver.h"


class TaxiDriver: public Driver {
public:
    TaxiDriver(): Driver("fio", DriverLicence::B) {};
    TaxiDriver(string fio): Driver(fio, DriverLicence::B) {};
    void info();
};
