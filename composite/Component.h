#pragma once

#include <vector>
#include <cassert>

using namespace std;


class Component {
public:
    virtual void addPerson(Component *component) { assert(false); };

    virtual void addLuggage(int luggage) { assert(false); };

    virtual void removeLuggage(int luggage) { assert(false); };

    virtual void setLuggage(int new_lug) { assert(false); };

    virtual int personsCount() {
        assert(false);
        return 0;
    };

    virtual vector<Component *> getPersons() {
        assert(false);
        return {};
    };

    virtual int getLuggage() { return 0; };

    virtual ~Component() = default;
};
