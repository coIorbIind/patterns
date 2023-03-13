#pragma once

#include "BaseCarBuilder.h"
#include "../cars/Taxi.h"


class TaxiBuilder : public BaseCarBuilder {
public:
    TaxiBuilder() : BaseCarBuilder(new Taxi()) {};
    void add_child_seat();
    void add_passenger();
    void add_driver();
    void add_passenger(Passenger* new_passenger) override;
    void add_driver(Driver* new_driver) override;
};
