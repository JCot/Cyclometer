/*
 * FullResetState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "FullResetState.h"
#include "global.h"

FullResetState::FullResetState(){
	NOP();
}

FullResetState::FullResetState(Calculations* myCalc){
	this -> calc = myCalc;
}

void FullResetState::onEntry(){
    printf("Entering Full Reset State State\n");
}
void FullResetState::onReEntry(){
    NOP();
}
void FullResetState::onExit(){
    printf("Leaving Full Reset State State\n");
    calc->fullReset();

}
// TODO reimplement this function to work
int FullResetState::transition(int event_id){

	return STATE_SETUNITS;

	switch( event_id ){

	case EVENT_SET:
		return STATE_SETUNITS;
		break;
	case EVENT_FASTMODE:
	case EVENT_MODE:
		return STATE_SETUNITS;
		break;
	case EVENT_TRIPRESET:
		return STATE_FULLRESET;
		break;
	case EVENT_RESET:
		return STATE_FULLRESET;
		break;
	case EVENT_STARTSTOP:
		return STATE_FULLRESET;
		break;
	default:
		std::printf( "ERROR: no event definition for FullReset code:%d\n", event_id);
		return -1;

	}
	return -1;
}
