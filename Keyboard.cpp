//
//  Keyboard.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include "Keyboard.h"

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>


#define IO_PORT_SIZE 1
#define CTRLA_ADDRESS 0x288

#define IR_BEAM_MASK 0x04
#define OVERCURRENT_MASK 0x08
#define BUTTON_MASK 0x10
#define RESET_MASK 0x08

uintptr_t ctrlKAHandle;

uint8_t Kcurrent;
uint8_t KBcurrent;

void* keyBoardHelper(void* args);
void* keyBoardHelperH(void* args);
void* monitorHelper(void* args);

Keyboard::Keyboard( EventQueue *queue, bool useHardware ){
    this->myQueue = queue;
    this-> done = false;
    this -> alreadyRead = true;
    this-> newCmds = false;

    if(useHardware){
    	ctrlKAHandle = mmap_device_io(IO_PORT_SIZE, CTRLA_ADDRESS);
    	pthread_create(&keyboard, NULL, &keyBoardHelperH, this);
    }
    else{
    	pthread_create(&monitor, NULL, &monitorHelper, this);
    	pthread_create(&keyboard, NULL, &keyBoardHelper, this);
    }
}

void Keyboard::sendCMD(char c){
    this->myQueue->enterCMD(c);
}

void* keyBoardHelper(void* args){
	return static_cast<Keyboard*>(args)->runProcess(NULL);
}

void* keyBoardHelperH(void* args){
	return static_cast<Keyboard*>(args)->runProcessH(NULL);
}

void* monitorHelper(void* args){
	return static_cast<Keyboard*>(args)->monitorBlocking(NULL);
}

void* Keyboard::runProcess(void* args){
	printf("Begin processing for user input\n");

	    std::string input = "";
	    while(!done){
	        //printf("In loop....\n");
	        sleep(2);
	        if(newCmds){
	            mtx.lock();
	           // printf( "NEW COMMANDS !!!!\n");
	            sendCMD(command);
	            newCmds = false;
	            mtx.unlock();
	        }
	    }
	    printf("Terminating processing for user input\n");

	    return EXIT_SUCCESS;

}

void* Keyboard::runProcessH(void* args){
	//printf("Begin scanning for user input\n");
	    std::string input = "";
	    while( !done ){
	      // printf("waaaaiting...\n");


	       Kcurrent = in8(ctrlKAHandle );


	       if( Kcurrent & IR_BEAM_MASK){ //raise IR event
	    	   sendCMD('i');
	    	   sleep (1);
	       }
	       if( Kcurrent & OVERCURRENT_MASK){ //raise overcurrent evevnt
	    	   sendCMD('m');
	    	   sleep (1);
	       }
	       if(Kcurrent & BUTTON_MASK){ //raise button event
	    	   //printf("got somthing for button \n");
	    	   sendCMD('p');
	    	   sleep (1);
	       }
	       if(Kcurrent & RESET_MASK){ //raise button event

	    	   sendCMD('r');
	    	   sleep (1);
	       }

	     //  std::printf( "got somoooething...%s\n", input.c_str());

	    }

	    //printf("Terminating scanning for user input\n");

	    return EXIT_SUCCESS;


}

void* Keyboard::monitorBlocking(void* args){

	//printf("Begin scanning for user input\n");

	    std::string input = "";
	    while( !done ){
	       // printf("waiting...\n");
	        getline(std::cin, input);
	       //std::printf( "got something...%s\n", input.c_str());
            command = input[0];
            if(command == 's' || command == 'm' || command == 'f' || command == 't' || command == 'r' || command == 'x'){
                mtx.lock();
                newCmds = true;
                mtx.unlock();
                if(input.compare("q" )== 0) {
                    done = true;
                }
            }else{
                printf("Invalid command %c\n", command);
            }
	    }

	    //printf("Terminating scanning for user input\n");

	    return NULL;
}

void Keyboard::shutDown(){
	done = true;
}



