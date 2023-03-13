#include "Passenger.h"

Passenger::~Passenger() {
    this->fio = "fio";
}

Passenger::Passenger(string fio) {
    this->fio = fio;
}

Passenger::Passenger() {
    this->fio = "fio";
}
