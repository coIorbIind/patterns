#include "Director.h"

Director::Director() {
    taxiBuilder = new TaxiBuilder();
    taxiPassengerBuilder = new TaxiPassengerBuilder();

    busBuilder = new BusBuilder();
    busPassengerBuilder = new BusPassengerBuilder();
}

Director::~Director() {
    delete taxiBuilder;
    delete taxiPassengerBuilder;
    delete busBuilder;
    delete busPassengerBuilder;
}

void Director::buildTaxi() {
    taxiPassengerBuilder->set_fio("Ivanov Ivan Ivanovich");
    taxiPassengerBuilder->set_category(TaxiPassengerCategory::Child);

    taxiBuilder->add_driver();
    taxiBuilder->add_passenger(taxiPassengerBuilder->get_object());
    taxiBuilder->add_child_seat();
    taxiBuilder->add_passenger(taxiPassengerBuilder->get_object());

    for (int i = 0; i < 5; ++i) {
        taxiBuilder->add_passenger();
    }
}

void Director::buildBus() {
    busPassengerBuilder->set_fio("Ivanov Ivan Ivanovich");
    busPassengerBuilder->set_category(BusPassengerCategory::Child);

    busBuilder->add_driver();
    busBuilder->add_passenger(taxiPassengerBuilder->get_object());
    busBuilder->add_passenger(busPassengerBuilder->get_object());

    for (int i = 0; i < 30; ++i) {
        busBuilder->add_passenger();
    }
}
