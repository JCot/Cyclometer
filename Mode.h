/*
 * Mode.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef MODE_H_
#define MODE_H_

#include <iostream>
#include "Event.h"
class Mode : public Event{

public:
    Mode(std::string m, int id);
    std::string getMessage();
    int getID();

};
#endif /* MODE_H_ */
