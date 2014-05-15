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

class SetTireState : public State{
private:

public:
	SetTireState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};
#endif /* SETTIRESTATE_H_ */
