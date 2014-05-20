/*
 * Reset.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef RESET_H_
#define RESET_H_

#include <iostream>
#include "Event.h"
class Reset : public Event{

public:
    Reset(std::string m, int id);
    std::string getMessage();
    int getID();

};
#endif /* RESET_H_ */
