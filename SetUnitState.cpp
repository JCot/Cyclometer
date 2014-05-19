/*
 * SetUnitState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "SetUnitState.h"

SetUnitState::SetUnitState(Calculations* myCalc){
	useKilometers = true;
	this -> calc = myCalc;
}


void SetUnitState::onEntry(){
    printf("Entering Set Unit State State\n");
    useKilomteres = true;
}
void SetUnitState::onReEntry(){
	printf("Switching between kilometers and miles\n");
	useKilometers = !useKilometers;
}
void SetUnitState::onExit(){
    printf("Leaving Set Unit State State\n");

}

int SetUnitState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		return STATE_SETTIRE;
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
		std::printf( "ERROR: no event definition for SetUnit code:%d\n", event_id);
		return -1;

	}
	return -1;
}
