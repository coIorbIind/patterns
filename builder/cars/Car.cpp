#include <iostream>

#include "Car.h"

using namespace std;

Car::Car(Driver *driver, int max_passengers_count) {
    this->max_passengers_count = max_passengers_count;
    this->driver = driver;
}

Car::~Car() {
    delete this->driver;
    for (auto & passenger : this->passengers) {
        delete passenger;
    }
}

bool Car::is_ready() {
    return this->driver != nullptr && !this->passengers.empty();
}

bool Car::add_passenger(Passenger *new_passenger) {
    if (this->max_passengers_count == this->passengers.size()) {
        cout << "All seats are occupied" << endl;
        return false;
    }

    this->passengers.push_back(new_passenger);
    cout << "Passenger has been set" << endl;
    return true;
}

bool Car::add_driver(Driver *new_driver) {
    if (this->driver != nullptr) {
        cout << "Driver already in the taxi" << endl;
        return false;
    }

    this->driver = new_driver;
    cout << "Driver has been set" << endl;
    return true;
}

Car::Car() {
    this->driver = nullptr;
}
