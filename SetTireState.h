/*
 * SetTireState.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef SETTIRESTATE_H_
#define SETTIRESTATE_H_

#include <iostream>
#include "State.h"
#include "Calculations.h"

class SetTireState : public State{
private:
	bool systemReset;
	int tireSize;
    Calculations *calc;

public:
	SetTireState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);
    void fullSystemReset();
    void adjustTireSize(int increment);
};
#endif /* SETTIRESTATE_H_ */
