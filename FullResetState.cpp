/*
 * FullResetState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "FullResetState.h"

FullResetState::FullResetState(){
}


void FullResetState::onEntry(){
    printf("Entering Full Reset State State\n");
}
void FullResetState::onReEntry(){
    NOP();
}
void FullResetState::onExit(){
    printf("Leaving Full Reset State State\n");
}
// TODO reimplement this function to work
int FullResetState::transition(int event_id){

	switch( event_id ){

	case EVENT_PUSHBUTTON:
		return 4;
		break;
	case EVENT_IR:
		return 3;
		break;
	case EVENT_DOOROPEN:
		std::printf("No transition for DoorOpen event in Closing state.\n");
		return -1;
		break;
	case EVENT_DOORCLOSED:
		return 0;
		break;
	case EVENT_MOTOROVERCURRENT:
		return 3;
		break;
	case EVENT_RESET:
		return 0;
		break;
	default:
		std::printf( "ERROR: no event definition for closing code:%d\n", event_id);
		return -1;

	}

	return -1;
}
