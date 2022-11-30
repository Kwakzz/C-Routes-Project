// --- IMPORTING LIBRARIES ---
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Airport.h"
using namespace std;


// --- FILE PATHS ---
static string airportsCSV = "airports.csv";
static string routesCSV = "routes.csv";


// --- STREAM DECLARATIONS ---
static ifstream airportsStream;
static ifstream routesStream;


// --- MEMBER VARIABLE DECLARATIONS ---
static string startCity;
static string destinationCity;
static vector <string> destinationCityVector;

static unordered_map<string, vector<Airport>> citiesAndTheirAirports;
static unordered_map<string, Airport> airportsMap;
static unordered_map<string, vector<Airport>> routesMap;
static unordered_map<string, vector<Airport>> paths;


// --- FUNCTION DECLARATIONS ---
/**
 * initialize an unordered map called citiesAndTheirAirports.
 * key is a city name.
 * value is a vector of airports.
 */
void createCitiesAndTheirAirportsMap ();

/**
 * initialize an unordered map called airportsMap.
 * key is an airport ID.
 * value is an airport object.
 */
void createAirportsMap ();

/**
 * create an unordered map called routesMap.
 * key is a city name.
 * value is a vector of airports.
 */
void createRoutesMap();

/**
 * gets the start and destination cities.
 * @param fileName is the path to the file containing the start city and destination city.
 */
void getStartCityAndDestinationCity (const string& fileName);

/**
 * @param city is the name of a city.
 * @return true if city's name is equal to the destination city's name.
*/
bool foundDestination (const string& city);

/**
 * runs a breadth-first search to find the destination city.
 */
void search();


// --- MAIN FUNCTION ---
int main() {

    createCitiesAndTheirAirportsMap();

    createAirportsMap();

    createRoutesMap();

    getStartCityAndDestinationCity("input.txt");

    search();


    return 0;
}


// --- FUNCTION DEFINITIONS ---

void createCitiesAndTheirAirportsMap () {

    // Airport tuple is below
    // Airport ID, Name, City, Country, IATA code (Airport code), ICAO code,

    string line;

    airportsStream.open(airportsCSV);

    while (getline(airportsStream, line)) {

        stringstream airportsTuple (line);


        string airportID;
        string airportName;
        string cityName;
        string countryName;
        string airportCode;

        getline(airportsTuple, airportID, ',');
        getline(airportsTuple, airportName, ',');
        getline(airportsTuple, cityName, ',');
        getline(airportsTuple, countryName, ',');
        getline(airportsTuple, airportCode, ',');


        if (citiesAndTheirAirports.count(cityName) != 0)
            citiesAndTheirAirports[cityName].emplace_back(Airport(airportID, airportCode, cityName));

        citiesAndTheirAirports.insert({cityName, {Airport(airportID, airportCode, cityName)}});
    }
    airportsStream.close();
}

void createAirportsMap () {

    // Airport tuple is below
    // Airport ID, Name, City, Country, IATA code (Airport code), ICAO code,

    string line;

    airportsStream.open(airportsCSV);

    while (getline(airportsStream, line)) {

        stringstream airportsTuple(line);

        string airportID;
        string airportName;
        string cityName;
        string countryName;
        string airportCode;

        getline(airportsTuple, airportID, ',');
        getline(airportsTuple, airportName, ',');
        getline(airportsTuple, cityName, ',');
        getline(airportsTuple, countryName, ',');
        getline(airportsTuple, airportCode, ',');

        airportsMap.insert({airportID, Airport(airportID, airportCode, cityName)});
    }
    airportsStream.close();

}

void createRoutesMap() {

    // Routes tuple is below
    // Airline code, Airline ID, Source airport code, Source airport ID,
    // Destination airport code, Destination airport ID,

    string line;

    routesStream.open(routesCSV);

    while (getline(routesStream, line)) {

        stringstream routesTuple(line);

        string airlineCode;
        string airlineID;
        string sourceAirportCode;
        string sourceAirportID;
        string destinationAirportCode;
        string destinationAirportID;

        getline(routesTuple, airlineCode, ',');
        getline(routesTuple, airlineID, ',');
        getline(routesTuple, sourceAirportCode, ',');
        getline(routesTuple, sourceAirportID, ',');
        getline(routesTuple, destinationAirportCode, ',');
        getline(routesTuple, destinationAirportID, ',');


        if (routesMap.count(sourceAirportCode) != 0)
            routesMap[sourceAirportCode].emplace_back(Airport(sourceAirportCode, destinationAirportID, destinationAirportCode, airlineCode));
        routesMap.insert({sourceAirportCode, {Airport(sourceAirportCode, destinationAirportID, destinationAirportCode, airlineCode)}});

    }
    routesStream.close();
}

void getStartCityAndDestinationCity (const string& fileName) {
    ifstream fileStream (fileName);

    string firstCity_name;
    string firstCity_country;

    string secondCity_name;
    string secondCity_country;

    string space;

    // Start city and its country
    getline(fileStream, firstCity_name, ',');
    getline(fileStream, space, ' ');
    getline(fileStream, firstCity_country, '\n');

    // Destination city and its country
    getline(fileStream, secondCity_name, ',');
    getline(fileStream, space, ' ');
    getline(fileStream, secondCity_country,'\n');

    startCity =  firstCity_name;
    destinationCity = secondCity_name;

}

bool foundDestination (const string& city) {
    return city == destinationCity;
}

void search () {

    cout << "Searching for route to destination..." << endl;

    vector <string> frontier;
    frontier = {startCity};
    vector <string> explored;
    string node = frontier[0];

    int counter = 0;

    while (destinationCityVector.empty()) {
        for (const Airport& airport: citiesAndTheirAirports.at(node)) {
            if (counter == 0) {
                paths[airport.getAirportCode()];
            }
            // paths[airport.getParentAirportCode()].emplace_back(airport);

            for (const Airport& destinationAirport: routesMap.at(airport.getAirportCode())) {
                if (foundDestination(airportsMap.at(destinationAirport.getAirportId()).getCity())) {
                    cout << "Found destination. You've arrived at " <<
                    airportsMap.at(destinationAirport.getAirportId()).getCity() << endl;
                    destinationCityVector.push_back(destinationAirport.getCity());
                }
            }
        }
        for (const Airport& airport: citiesAndTheirAirports.at(node)) {
            for (const Airport& destinationAirport: routesMap.at(airport.getAirportCode()))
                for (const string& city: explored) {
                    if (destinationAirport.getCity() == city)
                        continue;
                    frontier.push_back(destinationAirport.getCity());
                }
        }
        explored.push_back(frontier[0]);
        frontier.erase(frontier.begin());

        counter++;

    }


    // --- PRINT PATH ---
    vector <string> codes;
    vector <string> airlines;

    auto it = paths.begin();

    while (it != paths.end()) {
        // Accessing the key
        string code = it->first;
        // Accessing the value
        vector<Airport> airports = it->second;

        if (airports.end()->getCity() == destinationCity) {
            for (const Airport &airport: airports)
                codes.push_back(airport.getAirportCode());
            codes.push_back(code);
            break;
        }

        it++;
    }

//    for (int i = codes.size()-1; i>=1; i--)
//        cout << codes[i] << " to " << codes[i-1];


}

