#pragma once

#include "PassengerBuilder.h"
#include "../passengers/BusPassenger.h"


class BusPassengerBuilder : public PassengerBuilder {
public:
    BusPassengerBuilder() : PassengerBuilder(new BusPassenger()) {};

    void set_category(BusPassengerCategory new_cat);
};
