/*
 * ShowTimeState.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef SHOWTIMESTATE_H_
#define SHOWTIMESTATE_H_

#include <iostream>
#include "State.h"
#include "Calculations.h"

class ShowTimeState : public State{
private:
	Calculations *calc;
public:
	ShowTimeState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);
    void toggleAutoMode();
    void tripReset();
    void pauseCalc();

};

#endif /* SHOWTIMESTATE_H_ */
