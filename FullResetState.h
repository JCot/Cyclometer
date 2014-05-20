/*
 * FullResetState.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef FULLRESETSTATE_H_
#define FULLRESETSTATE_H_

#include <iostream>
#include "State.h"
#include "Calculations.h"

class FullResetState : public State{
private:
	Calculations *calc;
public:
	FullResetState();
	FullResetState(Calculations* myCalc);
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};
#endif /* FULLRESETSTATE_H_ */
