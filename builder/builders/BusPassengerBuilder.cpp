#include <iostream>

#include "BusPassengerBuilder.h"

void BusPassengerBuilder::set_category(BusPassengerCategory new_cat) {
    BusPassenger* pass = dynamic_cast<BusPassenger*>(this->object);
    if (pass == nullptr) {
        cout << "Wrong passenger" << endl;
    }
    pass->set_category(new_cat);
}
