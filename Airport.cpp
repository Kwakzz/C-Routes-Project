//
// Created by Kwaku Osafo and Kirklyn Aduachie on 29/11/2022.
//

#include "Airport.h"
#include <utility>


// --- CONSTRUCTORS ---
Airport::Airport(const string &parentAirportCode, const string &airportId, const string &airportCode,
                 const string &parentAirportAirlineCode) : parentAirportCode(parentAirportCode), airportID(airportId),
                                                           airportCode(airportCode),
                                                           parentAirportAirlineCode(parentAirportAirlineCode) {}

Airport::Airport(string airportId, string airportCode, string city)
        : airportID(std::move(airportId)), airportCode(std::move(airportCode)), city(std::move(city)) {}

Airport::Airport(const string &airportCode, const string &parentAirportAirlineCode) : airportCode(airportCode),
                                                                                      parentAirportAirlineCode(
                                                                                              parentAirportAirlineCode) {}

// --- MEMBER FUNCTIONS ---
const string &Airport::getParentAirportCode() const {
    return parentAirportCode;
}

const string &Airport::getAirportId() const {
    return airportID;
}

const string &Airport::getAirportCode() const {
    return airportCode;
}

const string &Airport::getCity() const {
    return city;
}

const string &Airport::getParentAirportAirlineCode() const {
    return parentAirportAirlineCode;
}

