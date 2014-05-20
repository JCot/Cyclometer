/*
 * StateMachine.h
 *
 *  Created on: Mar 19, 2014
 *      Author: ajl2612
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "EventQueue.h"
#include "FullResetstate.h"
#include "SetUnitState.h"
#include "SetTireState.h"
#include "ShowDistanceState.h"
#include "ShowSpeedState.h"
#include "ShowTimeState.h"
#include "Calculations.h"
#include "Display.h"
#include <pthread.h>


#define NUM_STATES 6


class StateMachine {
private:
    pthread_t io;
    bool done;
    int current_state;
    int last_state;

    EventQueue* myQueue;

    Calculations* calc;
    Display* display;

    FullResetState s0;
    SetUnitState s1;
    SetTireState s2;
    ShowDistanceState s3;
    ShowSpeedState s4;
    ShowTimeState s5;

    State *states[NUM_STATES];
    
    

public:
    void* runProcess(void);
	StateMachine(EventQueue* queue, Calculations* myCalc, Display* myDisplay);
	virtual ~StateMachine();
};

#endif /* STATEMACHINE_H_ */
