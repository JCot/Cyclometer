//
//  main.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/5/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "mutex.h"
#include <queue>
#include "Keyboard.h"
#include "EventQueue.h"
#include "Motor.h"
#include "StateMachine.h"

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>

#define IO_PORT_SIZE 1
#define CYCLES 3
#define NUM_THREADS 5
#define END_READ 'q'
#define DIR_ADDRESS 0x28b
#define CTRLB_ADDRESS 0x289
#define RESET_MASK_OFF 0x08
#define RESET_MASK_ON 0xf7

uintptr_t dirHandle;
uintptr_t ctrlMBHandle;
uint8_t val3 = 0b11110000; // 0x0f;
uint8_t Mcurrent;


void* thread (void* arg);

std::string command;
bool newCmds = false;
bool alreadyRead = true;
bool done = false;
bool useTheHardware = true;


PThreads::Mutex mtx;


void* threadIO (void* arg){
/*
    printf("Begin scanning for user input\n");
    
    std::string input = "";
    while( !done ){
        printf("waiting...\n");
        getline(std::cin, input);
        std::printf( "got something...%s\n", input.c_str());
        
        mtx.lock();
        
        cmdQueue.push(input.at(0));
        cmdQueue.push(input.at(0));
        cmdQueue.push(input.at(0));
        
        newCmds = true;
        mtx.unlock();
        if(input.compare("q" )== 0) {
            done = true;
        }
    }
    
    printf("Terminating scanning for user input\n");
    */
    return NULL;
}

int main( int argc, char *argv[]){

	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
		{

		perror("Failed to get I/O access permission");
		return 1;
		}
	//printf("%d \n",argc);
	if (argc > 1){
		useTheHardware = false;
	}else{
		useTheHardware = true;
	}

	dirHandle = mmap_device_io(IO_PORT_SIZE, DIR_ADDRESS);
	ctrlMBHandle = mmap_device_io(IO_PORT_SIZE, CTRLB_ADDRESS);
	out8(dirHandle, val3);
	Mcurrent = in8(ctrlMBHandle);

	out8(ctrlMBHandle, Mcurrent & RESET_MASK_ON);
	sleep(.5);
	out8(ctrlMBHandle, Mcurrent | RESET_MASK_OFF);

	EventQueue myQueue = EventQueue();
	printf("%d \n",useTheHardware);
	Keyboard keys = Keyboard(&myQueue, useTheHardware);
    Motor myMotor = Motor(&myQueue, useTheHardware);
    StateMachine rageAgainst = StateMachine(&myQueue, &myMotor);
    int x = 0;
    while(true){
        x++;
        x--;
    }

	return 1;

}
