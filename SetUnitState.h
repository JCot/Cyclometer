/*
 * SetUnitState.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef SETUNITSTATE_H_
#define SETUNITSTATE_H_

#include <iostream>
#include "State.h"
#include "Calculations.h"

class SetUnitState : public State{
private:
	bool useKilometers;
    Display* display;

public:
    SetUnitState();
	SetUnitState(Display* myDisplay);
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};
#endif /* SETUNITSTATE_H_ */
