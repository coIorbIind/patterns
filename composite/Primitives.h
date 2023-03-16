#pragma once

#include <iostream>

#include "Component.h"


using namespace std;


class Passenger : public Component {
private:
    int luggage;
public:
    int passenger_class;
    Passenger(int cls) { passenger_class = cls; }
    Passenger(int cls, int lug) { passenger_class = cls; luggage = lug; }

    void setLuggage(int new_lug) override {
        luggage = new_lug;
    }

    void addLuggage(int lug) override {
        luggage += lug;
        if (luggage > 60) {
            cout << "Sorry! We've removed " << luggage - 60 << " kg from your luggage.\n";
            luggage = 60;
        }
    };

    void removeLuggage(int lug) override {
        luggage -= lug;
        if (luggage < 0) {
            cout << "You don't have that much luggage\n";
            luggage = 0;
        }
    };

    int getLuggage() override {
        return luggage;
    };
};


class Pilot : public Component {};


class Stewardess: public Component{};