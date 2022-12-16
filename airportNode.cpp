//
// Created by Kwaku Osafo on 16/12/2022.
//

#include "airportNode.h"

// CONSTRUCTOR
airportNode::airportNode() = default;
airportNode::airportNode(const string &airportCode, const string &airlineUsedForFlight) : airportCode(airportCode),
                                                                                          airlineUsedForFlight(
                                                                                                  airlineUsedForFlight) {}

// GETTER METHODS
const string &airportNode::getAirportCode() const {
    return airportCode;
}

const string &airportNode::getAirlineUsedForFlight() const {
    return airlineUsedForFlight;
}

void airportNode::setAirportCode(const string &airportCode) {
    airportNode::airportCode = airportCode;
}

void airportNode::setAirlineUsedForFlight(const string &airlineUsedForFlight) {
    airportNode::airlineUsedForFlight = airlineUsedForFlight;
}


