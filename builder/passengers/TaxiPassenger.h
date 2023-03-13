#pragma once

#include "Passenger.h"
#include "../Enums.h"


class TaxiPassenger : public Passenger {
public:
    TaxiPassengerCategory category;
    TaxiPassenger();
    void set_category(TaxiPassengerCategory new_cat);
};
