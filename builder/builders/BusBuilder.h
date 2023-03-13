#pragma once

#include "BaseCarBuilder.h"
#include "../cars/Bus.h"


class BusBuilder : public BaseCarBuilder {
public:
    BusBuilder() : BaseCarBuilder(new Bus()) {};
    void add_passenger();
    void add_driver();
    void add_passenger(Passenger* new_passenger) override;
    void add_driver(Driver* new_driver) override;
};

