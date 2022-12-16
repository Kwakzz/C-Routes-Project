//
// Created by Kwaku Osafo on 16/12/2022.
//
#include <iostream>
#include "Airport.h"
using namespace std;

// CONSTRUCTORS
Airport::Airport() {}
Airport::Airport(const string &airportId, const string &city) : airportID(airportId), city(city) {}
Airport::Airport(const string &airportCode, const string &airportId, const airportNode &sourceAirport):
airportCode(airportCode), airportID(airportId), sourceAirport(sourceAirport) {}
Airport::Airport(const string &airportName, const string &airportId, const string &country, const string &city)
        : airportName(airportName), airportID(airportId), country(country), city(city) {}

// GETTER METHODS
const string &Airport::getAirportName() const {
    return airportName;
}

const string &Airport::getAirportCode() const {
    return airportCode;
}

const string &Airport::getAirportId() const {
    return airportID;
}

const string &Airport::getCountry() const {
    return country;
}

const string &Airport::getCity() const {
    return city;
}

const airportNode &Airport::getSourceAirport() const {
    return sourceAirport;
}



// SETTER METHODS
void Airport::setAirportName(const string &airportName) {
    Airport::airportName = airportName;
}

void Airport::setAirportCode(const string &airportCode) {
    Airport::airportCode = airportCode;
}

void Airport::setAirportId(const string &airportId) {
    airportID = airportId;
}

void Airport::setCountry(const string &country) {
    Airport::country = country;
}

void Airport::setCity(const string &city) {
    Airport::city = city;
}

void Airport::setSourceAirport(const airportNode &sourceAirport) {
    Airport::sourceAirport = sourceAirport;
}

string Airport::path() const {
    string p;
    p = sourceAirport.getAirlineUsedForFlight() + " from " + sourceAirport.getAirportCode() + " to " + getAirportCode() + "\n";
    return p;
}


