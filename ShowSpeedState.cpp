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


void ShowSpeedState::onEntry(){
    printf("Entering Show Speed State State\n");
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
