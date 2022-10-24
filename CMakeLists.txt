cmake_minimum_required(VERSION 3.23)
project(Auto_Bus_Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Auto_Bus_Project main.cpp BusStation.cpp BusStation.h voyage.cpp voyage.h ligne.cpp ligne.h Depot.cpp Depot.h trip.cpp trip.h HLP.cpp HLP.h)
