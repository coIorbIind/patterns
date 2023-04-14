#pragma once

#include <iostream>
#include <vector>

#include "Component.h"
#include "Primitives.h"

using namespace std;

class FirstClass : public Component {
public:
    void addPerson(Component *component) override {
        if (passengers.size() == 10) {
            cout << "All seats are occupied\n";
        } else {
            passengers.push_back(component);
        }
    };

    int personsCount() override {
        return passengers.size();
    }

    int getLuggage() override {
        int total = 0;
        for (auto &passenger: passengers) {
            total += passenger->getLuggage();
        }
        return total;
    };

    ~FirstClass() {
        for (auto &passenger: passengers) {
            delete passenger;
        }
    };
private:
    vector<Component *> passengers;
};


class BusinessClass : public Component {
public:
    void addPerson(Component *component) override {
        if (passengers.size() == 20) {
            cout << "All seats are occupied\n";
        } else {
            passengers.push_back(component);
        }
    };

    int personsCount() override {
        return passengers.size();
    }

    int getLuggage() override {
        int total = 0;
        for (auto &passenger: passengers) {
            total += passenger->getLuggage();
        }
        return total;
    };

    ~BusinessClass() {
        for (auto &passenger: passengers) {
            delete passenger;
        }
    };
private:
    vector<Component *> passengers;
};


class EconomyClass : public Component {
public:
    void addPerson(Component *component) override {
        if (passengers.size() == 150) {
            cout << "All seats are occupied\n";
        } else {
            passengers.push_back(component);
        }
    };

    vector<Component *> getPersons() override {
        return passengers;
    };

    int personsCount() override {
        return passengers.size();
    }

    int getLuggage() override {
        int total = 0;
        for (auto &passenger: passengers) {
            total += passenger->getLuggage();
        }
        return total;
    };

    ~EconomyClass() {
        for (auto &passenger: passengers) {
            delete passenger;
        }
    };
private:
    vector<Component *> passengers;
};


class Plane : public Component {
private:
    vector<Component *> classes;
    vector<Component *> stewardesses;
    vector<Component *> pilots;
    int max_luggage;
public:
    Component* getEconomyClass() {
        EconomyClass *cls;
        for (int i = 0; i < classes.size(); ++i) {
            cls = dynamic_cast<EconomyClass *>(classes[i]);
            if (cls != nullptr) {
                return classes[i];
            }
        }
        return nullptr;
    }
    void checkBeforeStart() {
        Component* economyClass = this->getEconomyClass();
        if (economyClass == nullptr) {
            cout << "We have no economy class\n";
        }
        else {
            if (this->getLuggage() > this->getMaxLuggage()){
                int old = this->getLuggage();
                int diff = this->getLuggage() - this->getMaxLuggage();
                cout << "We have extra " << diff << " kg\n";
                if (diff > economyClass->getLuggage()) {
                    cout << "We have too much luggage in business and first classes.\n"
                            "Please remove " << diff - economyClass->getLuggage() << " kg\n";
                } else {
                    int percents = (100 * diff) /  economyClass->getLuggage();
                    int new_lug;
                    for (int i = 0; i < economyClass->personsCount(); ++i) {
                        new_lug = economyClass->getPersons()[i]->getLuggage() * (100 - percents) / 100;
                        economyClass->getPersons()[i]->setLuggage(new_lug);
                    }
                    cout << "Removed " << old - this->getLuggage() << " kg from economy class\n";
                    cout << "New luggage " << this->getLuggage() << " kg\n";
                }
            } else {
                cout << "Luggage is ok\n";
            }
        }
    }

    Plane(int max_lug) { max_luggage = max_lug; }

    int getMaxLuggage() { return max_luggage; }

    ~Plane() {
        for (auto &cls: classes) {
            delete cls;
        }
        for (auto &stewardess: stewardesses) {
            delete stewardess;
        }
        for (auto &pilot: pilots) {
            delete pilot;
        }
    };

    int getLuggage() override {
        int total = 0;
        for (auto &passenger_class: classes) {
            total += passenger_class->getLuggage();
        }
        return total;
    };

    void addPerson(Component *component) override {
        FirstClass *cls1 = dynamic_cast<FirstClass *>(component);
        if (cls1 != nullptr && classes.size() < 3) {
            classes.push_back(cls1);
        } else {
            BusinessClass *cls2 = dynamic_cast<BusinessClass *>(component);
            if (cls2 != nullptr && classes.size() < 3) {
                classes.push_back(cls2);
            } else {
                EconomyClass *cls3 = dynamic_cast<EconomyClass *>(component);
                if (cls3 != nullptr && classes.size() < 3) {
                    classes.push_back(cls3);
                } else {
                    Pilot *pilot = dynamic_cast<Pilot *>(component);
                    if (pilot != nullptr && classes.size() < 2) {
                        pilots.push_back(pilot);
                    } else {
                        Stewardess *stewardess = dynamic_cast<Stewardess *>(component);
                        if (stewardess != nullptr && classes.size() < 6) {
                            stewardesses.push_back(stewardess);
                        } else {
                            cout << "Wrong type" << endl;
                        }
                    }
                }
            }
        }
    };
};