/*
Copyright (c) 2010-2013 Tommaso Urli

Tommaso Urli    tommaso.urli@uniud.it   University of Udine

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
*/


/*
 * PulseTimer.cpp - created based upon the software referenced in the copyright
 * notice above. Used to calculate the time between pulses of the magnet sensor.
 * Similar to stop watch except it uses double's for seconds.
 *
 *  Created on: May 11, 2014
 *      Author: jdc9622
 */

#include "Stopwatch.h"
#include <sys/time.h>
#include <stdlib.h>

Stopwatch::Stopwatch() {
	timeElapsed.sec = 0;
	prevTimeElapsed = 0;
//	running = false;
}

Stopwatch::~Stopwatch() {
	// TODO Auto-generated destructor stub
}

double Stopwatch::getTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);

	long double measure = tv.tv_usec;
	measure /= 1000000.0;
	measure += tv.tv_sec;

	return measure;
}

void Stopwatch::start(){
	startTime = getTime();
	running = true;
}

TIME Stopwatch::stop(){
	running = false;
	endTime = getTime();
	prevTimeElapsed = getTimeElapsed().sec;
	return getTimeElapsed();
}

bool Stopwatch::isRunning(){
	return running;
}

TIME Stopwatch::getTimeElapsed(){

	if(running){
		double tempTime = getTime();

		timeElapsed.sec = (tempTime - startTime) + prevTimeElapsed;
	}

	else{
		timeElapsed.sec = (endTime - startTime);
	}

	return timeElapsed;
}

void Stopwatch::reset(){
	timeElapsed.sec = 0;
	startTime = getTime();
	endTime = getTime();
	prevTimeElapsed = 0;
}
