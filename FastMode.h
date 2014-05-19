/*
 * FastMode.h
 *
 *  Created on: May 18, 2014
 *      Author: ajl2612
 */

#ifndef FASTMODE_H_
#define FASTMODE_H_

#include <iostream>
#include "Event.h"
class FastMode : public Event{

public:
    FastMode(std::string m, int id);
    std::string getMessage();
    int getID();

};
#endif /* FASTMODE_H_ */
