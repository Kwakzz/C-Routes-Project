//
// Created by Kwaku Osafo on 16/12/2022.
//

#ifndef INC_2ND_PROJECT_AIRPORTNODE_H
#define INC_2ND_PROJECT_AIRPORTNODE_H
#include <string>
using namespace std;


class airportNode {

public:
    // CONSTRUCTOR
    airportNode();
    airportNode(const string &airportCode, const string &airlineUsedForFlight);

private:
    // MEMBER VARIABLES
    string airportCode;
    string airlineUsedForFlight;

public:
    // GETTER METHODS

    /**
     * @return the airport's code
     */
    const string &getAirportCode() const;

    /**
     * @return the airline used to travel to this airport
     */
    const string &getAirlineUsedForFlight() const;

    // SETTER METHODS
    /**
     * @param airportCode is the airport's code
     */
    void setAirportCode(const string &airportCode);

    /**
     * @param airlineUsedForFlight is the airline used to travel to this airport
     */
    void setAirlineUsedForFlight(const string &airlineUsedForFlight);

    /**
     * print the path that led to this airport
     */
    void getPath ();
};


#endif //INC_2ND_PROJECT_AIRPORTNODE_H
