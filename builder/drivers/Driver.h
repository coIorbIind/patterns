#include <string>

#include "../Enums.h"

#pragma once

using namespace std;

class Driver {
public:
    string fio = "surname name patronymic";
    DriverLicence licence;
    Driver(string driverFio, DriverLicence driverLicence);
};
