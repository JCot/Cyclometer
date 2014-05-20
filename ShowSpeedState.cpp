//
//  Closing.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/19/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include "ShowSpeedState.h"

ShowSpeedState::ShowSpeedState(){

}

ShowSpeedState::ShowSpeedState(Calculations* myCalc){
	this -> calc = myCalc;
}


void ShowSpeedState::onEntry(){
    printf("Entering Show Speed State State\n");
    calc->setState(STATE_SHOWSPEED);
}
void ShowSpeedState::onReEntry(){
    NOP();
}
void ShowSpeedState::onExit(){
    printf("Leaving Show Speed State State\n");
}
// TODO reimplement this function to work
int ShowSpeedState::transition(int event_id){

	switch( event_id ){

	case EVENT_SET:
		toggleAutoMode();
		return STATE_SHOWSPEED;
		break;
	case EVENT_FASTMODE:
	case EVENT_MODE:
		return STATE_SHOWDISTANCE;
		break;
	case EVENT_TRIPRESET:
		tripReset();
		return STATE_SHOWSPEED;
		break;
	case EVENT_RESET:
		return STATE_FULLRESET;
		break;
	case EVENT_STARTSTOP:
		pauseCalc();
		return STATE_SHOWSPEED;
		break;
	default:
		std::printf( "ERROR: no event definition for FullReset code:%d\n", event_id);
		return -1;

	}
	return -1;
}

void ShowSpeedState::toggleAutoMode(){

	calc->toggleMode();

}

void ShowSpeedState::tripReset(){

	calc->resetTrip();

}

void ShowSpeedState::pauseCalc(){

	calc->toggleCalcs();

}

