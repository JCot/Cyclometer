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

class SetUnitState : public State{
private:

public:
	SetUnitState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};
#endif /* SETUNITSTATE_H_ */
