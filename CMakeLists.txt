cmake_minimum_required(VERSION 3.23)
project(2nd_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(2nd_Project main.cpp Airport.cpp Airport.h airportNode.cpp airportNode.h MyHashFunction.cpp MyHashFunction.h)
