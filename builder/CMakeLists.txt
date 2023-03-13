cmake_minimum_required(VERSION 3.24)
project(builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(builder main.cpp cars/Car.cpp cars/Car.h cars/Bus.cpp cars/Bus.h cars/Taxi.cpp cars/Taxi.h drivers/Driver.cpp drivers/Driver.h drivers/TaxiDriver.cpp drivers/TaxiDriver.h drivers/BusDriver.cpp drivers/BusDriver.h Enums.h passengers/Passenger.cpp passengers/Passenger.h passengers/TaxiPassenger.cpp passengers/TaxiPassenger.h passengers/BusPassenger.cpp passengers/BusPassenger.h builders/BaseCarBuilder.cpp builders/BaseCarBuilder.h builders/TaxiBuilder.cpp builders/TaxiBuilder.h builders/BusBuilder.cpp builders/BusBuilder.h builders/PassengerBuilder.cpp builders/PassengerBuilder.h builders/TaxiPassengerBuilder.cpp builders/TaxiPassengerBuilder.h builders/BusPassengerBuilder.cpp builders/BusPassengerBuilder.h Director.cpp Director.h)
