#pragma once

#include <iostream>

#include "Composite.h"


int main() {
    Plane *plane = new Plane(8);
    for (int i = 0; i < 2; ++i) {
        plane->addPerson(new Pilot());
    }
    for (int i = 0; i < 2; ++i) {
        plane->addPerson(new Stewardess());
    }
    EconomyClass *economyClass = new EconomyClass();
    BusinessClass *businessClass = new BusinessClass();
    FirstClass *firstClass = new FirstClass();
    // пассажиры первого(макс. 10 чел) бизнес (макс. 20 чел) и эконом (150 чел) классов
    for (int i = 0; i < 10; ++i) {
        firstClass->addPerson(new Passenger(1, 5));
    }
    for (int i = 0; i < 20; ++i) {
        businessClass->addPerson(new Passenger(2, 5));
    }
    for (int i = 0; i < 150; ++i) {
        economyClass->addPerson(new Passenger(3, 5));
    }
    plane->addPerson(economyClass);
    plane->addPerson(businessClass);
    plane->addPerson(firstClass);

    plane->checkBeforeStart();

    delete plane;
    return 0;
}
