#include <iostream>

#include "TaxiPassengerBuilder.h"


void TaxiPassengerBuilder::set_category(TaxiPassengerCategory new_cat) {
    TaxiPassenger* pass = dynamic_cast<TaxiPassenger*>(this->object);
    if (pass == nullptr) {
        cout << "Wrong passenger" << endl;
    }
    pass->set_category(new_cat);
}
