//
// Created by Kwaku Osafo and Kirklyn Aduachie on 29/11/2022.
//

#ifndef SEARCH_PROJECT_AIRPORT_H
#define SEARCH_PROJECT_AIRPORT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Airport {
public:

    // --- CONSTRUCTORS ---
    Airport(const string &parentAirportCode, const string &airportId, const string &airportCode,
            const string &parentAirportAirlineCode);

    Airport(string airportId, string airportCode, string city);

    Airport(const string &airportCode, const string &parentAirportAirlineCode);

    // --- MEMBER FUNCTIONS ---
    /**
     * @return the source airport's code.
     */
    const string &getParentAirportCode() const;

    /**
     * @return the airport's ID.
     */
    const string &getAirportId() const;

    /**
     * @return the airport's code.
     */
    const string &getAirportCode() const;

    /**
     * @return the airport's city.
     */
    const string &getCity() const;

    /**
     * @return the airport's name.
     */
    const string &getAirportName() const;

    /**
     * @return the airline used to get to the airport
     */
    const string &getParentAirportAirlineCode() const;


private:

    // --- MEMBER VARIABLES ---
    string parentAirportCode;
    string airportID;
    string airportCode;
    string city;
    string parentAirportAirlineCode;

};


#endif //SEARCH_PROJECT_AIRPORT_H
