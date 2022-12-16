//
// Created by Kwaku Osafo on 16/12/2022.
//

#ifndef INC_2ND_PROJECT_AIRPORT_H
#define INC_2ND_PROJECT_AIRPORT_H
#include <string>
#include "airportNode.h"
using namespace std;


class Airport {

public:
    Airport();

    Airport(const string &airportName, const string &airportId, const string &country, const string &city);

    Airport(const string &airportId, const string &city);

    Airport(const string &airportCode, const string &airportId, const airportNode &sourceAirport);

private:
    // MEMBER VARIABLES
    string airportName;
    string airportCode;
    string airportID;
    string country;
    string city;
    airportNode sourceAirport;

public:
    // GETTER METHODS
    /**
     * @return the name of the airport
     */
    const string &getAirportName() const;

    /**
     * @return the airport code
     */
    const string &getAirportCode() const;

    /**
     * @return the airport ID
     */
    const string &getAirportId() const;

    /**
     * @return the country the airport is situated in
     */
    const string &getCountry() const;

    /**
     * @return the city the airport is situated in
     */
    const string &getCity() const;


    /**
     * @return the airport the flight was from
     */
    const airportNode &getSourceAirport() const;


    // SETTER METHODS
    /**
     * @param airportName is the name of the airport
     */
    void setAirportName(const string &airportName);

    /**
     * @param airportCode is the airport's code
     */
    void setAirportCode(const string &airportCode);

    /**
     * @param airportId is the airport's ID
     */
    void setAirportId(const string &airportId);

    /**
     * @param country is the country the airport is situated in
     */
    void setCountry(const string &country);

    /**
     * @param city is the city the airport is situated in
     */
    void setCity(const string &city);

    /**
     * print path that led to destination city.
     * write path to an out file as well.
     */
    string path () const;


    /**
     * @param sourceAirport is the airport the flight was from
     */
    void setSourceAirport(const airportNode &sourceAirport);

    /**
     * @param otherAirport is the airport being compared with
     * @return true if airports are the same.
     */
    bool operator==(const Airport& otherAirport) const
    {
        return getAirportId() ==  otherAirport.getAirportId();
    }

};


#endif //INC_2ND_PROJECT_AIRPORT_H
