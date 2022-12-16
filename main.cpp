#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "Airport.h"
#include "MyHashFunction.h"
using namespace std;



// MEMBER VARIABLES
const string pathToAirportsFile = "/Users/kwakuosafo/Desktop/Kwaku/Ashesi/SECOND YEAR/Intermediate Computer Programming/C++/Project/2nd Project/airports.csv";
const string pathToRoutesFile = "/Users/kwakuosafo/Desktop/Kwaku/Ashesi/SECOND YEAR/Intermediate Computer Programming/C++/Project/2nd Project/routes.csv";
string inputFile = "/Users/kwakuosafo/Desktop/Kwaku/Ashesi/SECOND YEAR/Intermediate Computer Programming/C++/Project/2nd Project/input.txt";

ifstream airportsStream;
ifstream routesStream;

string startCity;
string *startCityPtr = &startCity;
string destinationCity;
string *destinationCityPtr = &destinationCity;

// key is an airport id, value is the corresponding airport
unordered_map<string, Airport> airportsMap;

// key is an airport code, value is an unordered set of destination airports
unordered_map<string, unordered_set<Airport, MyHashFunction>>routesMap;

// key is a city name, value is an unordered set of the airports in that city
unordered_map<string, unordered_set<Airport, MyHashFunction>>citiesAndTheirAirports;

// MEMBER FUNCTIONS

/**
 * initialize an unordered map called airportsMap.
 * key is an airport ID.
 * value is an airport object.
 */
void createAirportsMap (unordered_map<string, Airport>& airports_map);

/**
 * create an unordered map called routesMap.
 * key is a city name.
 * value is an unordered set of airports.
 * @param routes_map is a map whose key is an airport id. Its value is an unordered set of destination airports
 */
void createRoutesMap (unordered_map<string, unordered_set<Airport, MyHashFunction>>& routes_map);

/**
 * create an unordered map called citiesAndTheirAirports.
 * key is a city name.
 * value is an unordered set of airports.
 * @param cities_and_their_airports is a map whose key is an airport id. Its value is an unordered set of destination airports
 */
void createCitiesAndTheirAirportsMap (unordered_map<string, unordered_set<Airport, MyHashFunction>>& cities_and_their_airports);

/**
 * gets the start and destination cities.
 * @param fileName is the path to the file containing the start city and destination city.
 */
void getStartCityAndDestinationCity (const string& pathToInputFile);

/**
 * @param city is the potential destination city
 * @return true if city is the destination city
 */
bool foundDestination (const string& city);

/**
 * this function searches for the destination airport
 */
void search ();



int main() {

    createAirportsMap(airportsMap);
    createRoutesMap(routesMap);
    createCitiesAndTheirAirportsMap(citiesAndTheirAirports);
    getStartCityAndDestinationCity(inputFile);
    search();
    return 0;
}





// FUNCTION DEFINITIONS

/**
 * stores the start and destination cities in strings.
 * @param fileName is the name of the files containing the start and destination cities
 */
void getStartCityAndDestinationCity (const string& pathToInputFile) {
    ifstream fileStream (pathToInputFile);

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


    *startCityPtr =  firstCity_name;
    *destinationCityPtr = secondCity_name;

    cout << "Your trip starts from " << startCity << "." << endl;
}

void createAirportsMap (unordered_map<string, Airport> & airports_map) {

// Airport tuple is below
// Airport ID, Name, City, Country, IATA code (Airport code), ICAO code,

    string line;

    airportsStream.open(pathToAirportsFile);

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

        airports_map.insert({airportID, Airport(airportName, airportID, countryName, cityName)});
    }
    airportsStream.close();

}

void createRoutesMap (unordered_map<string, unordered_set<Airport, MyHashFunction>>& routes_map) {

    // Routes tuple is below
    // Airline code, Airline ID, Source airport code, Source airport ID,
    // Destination airport code, Destination airport ID,

    string line;

    routesStream.open(pathToRoutesFile);

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

        if (routes_map.count(sourceAirportID) == 0) {
            unordered_set<Airport, MyHashFunction> destinationAirports;
            routes_map.insert({sourceAirportID, destinationAirports});
            destinationAirports.insert({destinationAirportCode, destinationAirportID, airportNode(sourceAirportCode, airlineCode)});
        }
        routes_map[sourceAirportID].insert({destinationAirportCode, destinationAirportID, airportNode(sourceAirportCode, airlineCode)});

    }

}

void createCitiesAndTheirAirportsMap (unordered_map<string, unordered_set<Airport, MyHashFunction>>& cities_and_their_airports) {

    // Airport tuple is below
    // Airport ID, Name, City, Country, IATA code (Airport code), ICAO code,

    string line;

    airportsStream.open(pathToAirportsFile);

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

        if (cities_and_their_airports.count(cityName) == 0) {
            unordered_set<Airport, MyHashFunction> airportsInCity;
            cities_and_their_airports.insert({cityName, airportsInCity});
            airportsInCity.insert({Airport(airportID, cityName)});
        }
        cities_and_their_airports[cityName].insert({Airport(airportID, cityName)});

    }
}

bool foundDestination (const string& city) {
    return city == destinationCity;
}


void search () {
    cout << "Searching for path to destination city..." << endl;

    // queue of cities to be explored
    deque<string> frontier;

    // set of explored cities
    unordered_set<string> exploredCities;

    // add start city to the frontier (from the front) for exploration
    frontier.emplace_front(*startCityPtr);


    unordered_set<Airport>::iterator itr1;
    unordered_set<Airport>::iterator itr2;

    while (!frontier.empty()) {
        for (itr1 = citiesAndTheirAirports.at(frontier.front()).begin();
             itr1 != citiesAndTheirAirports.at(frontier.front()).end(); itr1++) {
            for (itr2 = routesMap.at(itr1->getAirportId()).begin();
                 itr2 != routesMap.at(itr1->getAirportId()).end(); itr2++) {
                if (foundDestination(airportsMap.at(itr2->getAirportId()).getCity())) {
                    cout << "Destination found!" << endl;
                    cout << itr2->path();
                    cout << "You've arrived at " << airportsMap.at(itr2->getAirportId()).getAirportName()<< " in " <<
                    airportsMap.at(itr2->getAirportId()).getCity() << ", " <<
                    airportsMap.at(itr2->getAirportId()).getCountry() << endl;
                    ofstream outputFile ("/Users/kwakuosafo/Desktop/Kwaku/Ashesi/SECOND YEAR/Intermediate Computer Programming/C++/Project/2nd Project/" + startCity + "-" + destinationCity + "-" + "output.txt");
                    outputFile << itr2->path();
                    outputFile.close();
                    exit(0);
                }
            }
        }

        exploredCities.insert(frontier.front());
        frontier.pop_front();

        for (itr1 = citiesAndTheirAirports.at(frontier.front()).begin();
             itr1 != citiesAndTheirAirports.at(frontier.front()).end(); itr1++) {
            for (itr2 = routesMap.at(itr1->getAirportId()).begin();
                 itr2 != routesMap.at(itr1->getAirportId()).end(); itr2++) {
                if (exploredCities.count(itr2->getCity()) == 0 and count(frontier.begin(), frontier.end(), itr2->getCity()) == 0)
                    frontier.emplace_front(itr2->getCity());
            }
        }
    }

}