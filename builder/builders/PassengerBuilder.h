#pragma once

#include <string>

#include "../passengers/Passenger.h"


class PassengerBuilder {
protected:
    Passenger *object;
public:
    PassengerBuilder(Passenger* pass) { this->object = pass; }
    PassengerBuilder() { this->object = new Passenger(); }

    ~PassengerBuilder() { delete this->object; }

    void set_fio(string new_fio) { this->object->fio = new_fio; }
    virtual Passenger* get_object() {return this->object;}
};
