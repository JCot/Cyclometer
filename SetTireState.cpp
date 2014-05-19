/*
 * SetTireState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "SetTireState.h"

SetTireState::SetTireState(Calculations* myCalc){
	systemReset = true;
	tireSize = 190;
	this -> calc = myCalc;
}


void SetTireState::onEntry(){
    printf("Entering Set Tire State State\n");
}
void SetTireState::onReEntry(){
    NOP();
}
void SetTireState::onExit(){
    printf("Leaving Set Tire State State\n");
}

//190 to 220 inclusive

int SetTireState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		if( systemReset ){
			return STATE_SHOWSPEED;
			systemReset = false;
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
	tireSize = 190;
}

void SetTireState::adjustTireSize( int increment ){
	tireSize += increment;
	if( tireSize > 220){
		tireSize = (tireSize - 221) + 190;
	}
}
