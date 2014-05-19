//
//  ShowSpeedState.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/19/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__ShowSpeedState__
#define __StateMachine__ShowSpeedState__

#include <iostream>
#include "State.h"
#include "Calculations.h"

class ShowSpeedState : public State{
private:
    Calculations *calc;
public:
	ShowSpeedState( Calculations* calc);
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);
    void toggleAutoMode();
    void tripReset();
    void pauseCalc();

};
#endif /* defined(__StateMachine__ShowSpeedState__) */
