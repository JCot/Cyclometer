/*
 * ShowDistanceState.h
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#ifndef SHOWDISTANCESTATE_H_
#define SHOWDISTANCESTATE_H_

#include <iostream>
#include "State.h"
#include "Calculations.h"

class ShowDistanceState : public State{
private:
    Calculations *calc;
public:
	ShowDistanceState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);
    void tripReset();
    void pauseCalc();

};

#endif /* SHOWDISTANCESTATE_H_ */
