#pragma once

#include <iostream>

#include "Composite.h"


int main() {
    Plane *plane = new Plane(800);
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

    if (plane->getLuggage() > plane->getMaxLuggage()){
        int old = plane->getLuggage();
        int diff = plane->getLuggage() - plane->getMaxLuggage();
        cout << "We have extra " << diff << " kg\n";
        if (diff > economyClass->getLuggage()) {
            cout << "We have too much luggage in business and first classes\n. "
                    "Please remove " << diff - economyClass->getLuggage() << " kg\n";
        } else {
            int percents = (100 * diff) /  economyClass->getLuggage();
            int new_lug;
            for (int i = 0; i < economyClass->personsCount(); ++i) {
                new_lug = economyClass->getPersons()[i]->getLuggage() * (100 - percents) / 100;
                economyClass->getPersons()[i]->setLuggage(new_lug);
            }
            cout << "Removed " << old - plane->getLuggage() << " kg from economy class\n";
            cout << "New luggage " << plane->getLuggage() << " kg\n";
        }
    } else {
        cout << "Luggage is ok\n";
    }

    delete plane;
    return 0;
}
