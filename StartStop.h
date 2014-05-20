/*
 * StartStop.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef STARTSTOP_H_
#define STARTSTOP_H_

#include <iostream>
#include "Event.h"
class StartStop : public Event{

public:
    StartStop(std::string m, int id);
    std::string getMessage();
    int getID();

};

#endif /* STARTSTOP_H_ */
