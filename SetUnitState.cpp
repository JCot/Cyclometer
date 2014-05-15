/*
 * SetUnitState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "SetUnitState.h"

SetUnitState::SetUnitState(){
}


void SetUnitState::onEntry(){
    printf("Entering Set Unit State State\n");
}
void SetUnitState::onReEntry(){
    NOP();
}
void SetUnitState::onExit(){
    printf("Leaving Set Unit State State\n");
}
// TODO reimplement this function to work
int SetUnitState::transition(int event_id){

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
