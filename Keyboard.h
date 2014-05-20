//
//  Keyboard.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__Keyboard__
#define __StateMachine__Keyboard__

#include <iostream>
#include "EventGenerator.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "mutex.h"
#include <queue>

class Keyboard: public EventGenerator{

private:

    EventQueue* myQueue;
	char command;
	bool newCmds;
	bool alreadyRead;
	bool done;
	int modeCount;
	int tripCount;
	int resetCount;

	PThreads::Mutex mtx;
	pthread_t keyboard;
	pthread_t monitor;

    void sendCMD(char c);
    void riaseSetEvent();
    void raiseModeEvent();
    void raiseFastModeEvent();
    void raiseStartStopEvent();
    void raiseTripEvent();
    void raiseResetEvent();

public:
    Keyboard( EventQueue* queue, bool useHardware);
    void* runProcess (void* args);
    void* runProcessH (void* args);
    void* monitorBlocking (void* args);
    void shutDown();

};

#endif /* defined(__StateMachine__Keyboard__) */
