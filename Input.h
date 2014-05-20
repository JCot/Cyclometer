/*
 * Input.h
 *
 *  Created on: May 19, 2014
 *      Author: jdc9622
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include "EventGenerator.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <queue>

class Input: public EventGenerator {

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
	pthread_t input;

    void sendCMD(char c);
    void riaseSetEvent();
    void raiseModeEvent();
    void raiseFastModeEvent();
    void raiseStartStopEvent();
    void raiseTripEvent();
    void raiseResetEvent();

public:
    Input( EventQueue *queue);
    ~Input();
    void* runProcess (void* args);
    void shutDown();

};

#endif /* INPUT_H_ */
