/*
 * SetTireState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "SetTireState.h"
#include "global.h"

SetTireState::SetTireState(){
	NOP();
}

SetTireState::SetTireState(Display* myDisplay){
	systemReset = true;
	wheelCirc = 190;
	this -> display = myDisplay;
}

void SetTireState::onEntry(){
    printf("Entering Set Tire State State\n");
    printf("Current wheel diameter %d\n", wheelCirc);
    display->displayWheelCirc(wheelCirc);

}

void SetTireState::onReEntry(){
    printf("Current wheel diameter %d\n", wheelCirc);
    display->displayWheelCirc(wheelCirc);
}
void SetTireState::onExit(){
    printf("Leaving Set Tire State State\n");
}

//190 to 220 inclusive

int SetTireState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		if( systemReset ){
			systemReset = false;
			return STATE_SHOWSPEED;
		}
		else{
			return STATE_SHOWDISTANCE;
		}
		break;
	case EVENT_FASTMODE:
		adjustTireSize(10);
		return STATE_SETTIRE;
		break;
	case EVENT_MODE:
		adjustTireSize(1);
		return STATE_SETTIRE;
		break;
	case EVENT_TRIPRESET:
		return STATE_SETTIRE;
		break;
	case EVENT_RESET:
		return STATE_FULLRESET;
		break;
	case EVENT_STARTSTOP:
		return STATE_SETTIRE;
		break;
	default:
		std::printf( "ERROR: no event definition for SetTire code:%d\n", event_id);
		return -1;

	}

	return -1;
}

void SetTireState::fullSystemReset(){
	systemReset = true;
	wheelCirc = 190;
}

void SetTireState::adjustTireSize( int increment ){
	wheelCirc += increment;
	if( wheelCirc > 220){
		wheelCirc = (wheelCirc - 221) + 190;
	}
}
