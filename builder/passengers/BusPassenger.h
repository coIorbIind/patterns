#pragma once

#include "../Enums.h"
#include "Passenger.h"

class BusPassenger : public Passenger{
public:
    BusPassengerCategory category = BusPassengerCategory::Adult;
    void set_category(BusPassengerCategory new_cat);
};
