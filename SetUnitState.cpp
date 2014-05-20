/*
 * SetUnitState.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "SetUnitState.h"
#include "global.h"

SetUnitState::SetUnitState(){
	NOP();
}


SetUnitState::SetUnitState(Display* myDisplay){
	useKilometers = true;
	this -> display = myDisplay;
}


void SetUnitState::onEntry(){
    printf("Entering Set Unit State State\n");
    if( useKilometers ){
    	printf( "Currently using metric units\n");
    	units = METRIC;
    }else{
    	printf("Currently using imperial units\n");
    	units = ENGLISH;
    }

    display->displayUnits(useKilometers);
}
void SetUnitState::onReEntry(){
	printf("Switching between kilometers and miles\n");
	useKilometers = !useKilometers;
    if( useKilometers ){
    	printf( "Currently using metric units\n");
    	units = METRIC;
    }else{
    	printf("Currently using imperial units\n");
    	units = ENGLISH;
    }

    display->displayUnits(useKilometers);
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
