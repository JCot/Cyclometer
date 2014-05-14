/*
 * TripReset.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef TRIPRESET_H_
#define TRIPRESET_H_

#include <iostream>
#include "Event.h"
class TripReset : public Event{

public:
    TripReset(std::string m, int id);
    std::string getMessage();
    int getID();

};
#endif /* TRIPRESET_H_ */
