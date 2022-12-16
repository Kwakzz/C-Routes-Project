//
// Created by Kwaku Osafo on 16/12/2022.
//

#ifndef INC_2ND_PROJECT_MYHASHFUNCTION_H
#define INC_2ND_PROJECT_MYHASHFUNCTION_H
#include "Airport.h"


class MyHashFunction {

    /**
     * hash function for airport
     */
public:
        size_t operator()(const Airport& airport) const {
            return (hash<string>()(airport.getAirportId()));
        }

};


#endif //INC_2ND_PROJECT_MYHASHFUNCTION_H
