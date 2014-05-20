/*
 * Input.cpp
 *
 *  Created on: May 19, 2014
 *      Author: jdc9622
 */

#include "Input.h"
#include "global.h"

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>


#define IO_PORT_SIZE 1

#define SET_MASK 0x08
#define MODE_MASK 0x02
#define TRIP_MASK 0x0A
#define START_STOP_MASK 0x20
#define RESET_MASK 0x2A

uintptr_t ctrlIBHandle;

uint8_t Icurrent;
uint8_t IBcurrent;

void* keyBoardHelper(void* args);

void Input::sendCMD(char c){
    this->myQueue->enterCMD(c);
}

void* inputHelper(void* args){
	return static_cast<Input*>(args)->runProcess(NULL);
}

Input::Input(EventQueue *queue) {
    this->myQueue = queue;
    this-> done = false;

    ctrlIBHandle = mmap_device_io(IO_PORT_SIZE, DATA_PORT_B);
    pthread_create(&input, NULL, &inputHelper, this);
}

Input::~Input() {}

void* Input::runProcess(void* args){
	//printf("Begin scanning for user input\n");
	    std::string input = "";
	    while( !done ){
	      // printf("waaaaiting...\n");


	       Icurrent = in8(ctrlIBHandle );

	       bool modePressed = Icurrent & MODE_MASK;
	       bool setPressed = Icurrent & SET_MASK;
	       bool startStopPressed = Icurrent & START_STOP_MASK;

	       if( modePressed && setPressed && startStopPressed){
	    	   modeCount = 0;
	    	   tripCount = 0;
	    	   if( resetCount++ > 2){
	    		   resetCount = 0;
	    		   sendCMD('r');
	    	   }
	       }
	       else if( modePressed && setPressed){
	    	   modeCount = 0;
	    	   resetCount = 0;
	    	   if( tripCount++ > 2){
	    		   tripCount = 0;
	    		   sendCMD('t');
	    	   }
	       }
	       else if ( modePressed){
	    	   tripCount = 0;
	    	   resetCount = 0;
	    	   if( modeCount++ > 2 ){
	    		   sendCMD('f');
	    	   }
	    	   else{
	    		   sendCMD('m');
	    	   }
	       }
	       else if ( setPressed){
	    	   modeCount = 0;
	    	   tripCount = 0;
	    	   resetCount = 0;

	    	   sendCMD('s');
	       }
	       else if(startStopPressed){
	    	   sendCMD('x');
	       }else{

	       }

	       /*
	       if(Icurrent & RESET_MASK){ //raise reset event
	    	   modeCount = 0;
	    	   tripCount = 0;
	    	   if( resetCount++ > 2){
	    		   resetCount = 0;
	    		   sendCMD('r');
	    	   }
//	    	   sleep (1);
	       }
	       if(Icurrent & TRIP_MASK){ //raise trip event
	    	   modeCount = 0;
	    	   resetCount = 0;
	    	   if( tripCount++ > 2){
	    		   tripCount = 0;
	    		   sendCMD('t');
	    	   }
//	    	   sleep (1);
	       }

	       if( Icurrent & SET_MASK){ //raise SET event
	    	   modeCount = 0;
	    	   tripCount = 0;
	    	   resetCount = 0;

	    	   sendCMD('s');
//	    	   sleep (1);
	       }
	       if( Icurrent & MODE_MASK){ //raise MODE or FAST_MODE event
	    	   tripCount = 0;
	    	   resetCount = 0;
	    	   if( modeCount++ > 2 ){
	    		   sendCMD('f');
	    	   }
	    	   else{
	    		   sendCMD('m');
	    	   }
//	    	   sleep (1);
	       }

	       if(Icurrent & START_STOP_MASK){ //raise start stop event

	    	   sendCMD('x');
//	    	   sleep (1);
	       }
			*/
	       sleep (1);

	    }
	    return EXIT_SUCCESS;
}
