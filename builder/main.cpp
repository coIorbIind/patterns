#include <iostream>

#include "Director.h"


int main() {
    Director* director = new Director();

    director->buildTaxi();

    cout << "----------------------------\n";

    director->buildBus();

    delete director;
    return 0;
}
