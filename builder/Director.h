#pragma once

#include "builders/TaxiBuilder.h"
#include "builders/TaxiPassengerBuilder.h"

#include "builders/BusBuilder.h"
#include "builders/BusPassengerBuilder.h"


class Director {
private:
    TaxiBuilder* taxiBuilder;
    TaxiPassengerBuilder* taxiPassengerBuilder;
    BusBuilder* busBuilder;
    BusPassengerBuilder* busPassengerBuilder;
public:
    Director();
    ~Director();
    void buildTaxi();
    void buildBus();
};
