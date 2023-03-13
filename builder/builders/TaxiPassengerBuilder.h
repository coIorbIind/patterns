#pragma once

#include "PassengerBuilder.h"
#include "../passengers/TaxiPassenger.h"


class TaxiPassengerBuilder : public PassengerBuilder {
public:
    TaxiPassengerBuilder() : PassengerBuilder(new TaxiPassenger()) {};

    void set_category(TaxiPassengerCategory new_cat);
};
