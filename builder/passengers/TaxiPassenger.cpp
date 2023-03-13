#include "TaxiPassenger.h"

TaxiPassenger::TaxiPassenger() : Passenger() {
    this->category = TaxiPassengerCategory::Adult;
}

void TaxiPassenger::set_category(TaxiPassengerCategory new_cat) {
    this->category = new_cat;
}
