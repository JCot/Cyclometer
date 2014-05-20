/*
 * ShowTimeState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "ShowTimeState.h"

ShowTimeState::ShowTimeState(){
}

ShowTimeState::ShowTimeState(Calculations* myCalc){
	this -> calc = myCalc;
}


void ShowTimeState::onEntry(){
    printf("Entering Show Time State State\n");
    calc->setState(STATE_SHOWTIME);
}
void ShowTimeState::onReEntry(){
    NOP();
}
void ShowTimeState::onExit(){
    printf("Leaving Show Time State State\n");
}
// TODO reimplement this function to work
int ShowTimeState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		toggleAutoMode();
		return STATE_SHOWTIME;
		break;
	case EVENT_FASTMODE:
	case EVENT_MODE:
		return STATE_SHOWSPEED;
		break;
	case EVENT_TRIPRESET:
		tripReset();
		return STATE_SHOWTIME;
		break;
	case EVENT_RESET:
		return STATE_FULLRESET;
		break;
	case EVENT_STARTSTOP:
		pauseCalc();
		return STATE_SHOWTIME;
		break;
	default:
		std::printf( "ERROR: no event definition for FullReset code:%d\n", event_id);
		return -1;

	}
	return -1;
}

void ShowTimeState::toggleAutoMode(){
	printf("Switching between auto and manual mode\n");

	calc->toggleMode();

}

void ShowTimeState::tripReset(){

	calc->resetTrip();

}

void ShowTimeState::pauseCalc(){

	calc->toggleCalcs();

}
