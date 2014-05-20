/*
 * ShowDistanceState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "ShowDistanceState.h"

ShowDistanceState::ShowDistanceState(){
}

ShowDistanceState::ShowDistanceState(Calculations* myCalc){
	this -> calc = myCalc;
}


void ShowDistanceState::onEntry(){
    printf("Entering Show Distance State State\n");
    calc->setState(STATE_SHOWDISTANCE);
}
void ShowDistanceState::onReEntry(){
    NOP();
}
void ShowDistanceState::onExit(){
    printf("Leaving Show Distance State State\n");
}
// TODO reimplement this function to work
int ShowDistanceState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		toggleAutoMode();
		return STATE_SHOWDISTANCE;
		break;
	case EVENT_FASTMODE:
	case EVENT_MODE:
		return STATE_SHOWTIME;
		break;
	case EVENT_TRIPRESET:
		tripReset();
		return STATE_SHOWDISTANCE;
		break;
	case EVENT_RESET:
		return STATE_FULLRESET;
		break;
	case EVENT_STARTSTOP:
		pauseCalc();
		return STATE_SHOWDISTANCE;
		break;
	default:
		std::printf( "ERROR: no event definition for FullReset code:%d\n", event_id);
		return -1;

	}
	return -1;
}

void ShowDistanceState::toggleAutoMode(){

	calc->toggleMode();

}

void ShowDistanceState::tripReset(){

	calc->resetTrip();

}

void ShowDistanceState::pauseCalc(){

	calc->toggleCalcs();

}
