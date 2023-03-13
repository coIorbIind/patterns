#pragma once

#include <string>

using namespace std;

class Passenger {
public:
    string fio;
    Passenger();
    Passenger(string fio);
    virtual ~Passenger();
};
