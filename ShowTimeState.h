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

class ShowTimeState : public State{
private:

public:
	ShowTimeState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};

#endif /* SHOWTIMESTATE_H_ */
