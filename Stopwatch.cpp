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
 * Stopwatch.cpp - created based upon the software referenced in the copyright
 * notice above.
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#include "Stopwatch.h"
#include <sys/time.h>
#include <iomanip>
#include <stdlib.h>

Stopwatch::Stopwatch() {
	timeElapsed.min = 0;
	timeElapsed.sec = 0;
}

Stopwatch::~Stopwatch() {
	// TODO Auto-generated destructor stub
}

int Stopwatch::getTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);

	double measure = tv.tv_sec;

	return measure;
}

void Stopwatch::start(){
	startTime = getTime();
}

TIME Stopwatch::stop(){
	return getTimeElapsed();
}

TIME Stopwatch::getTimeElapsed(){
	int tempTime = getTime();
	int tempElapsed = tempTime - startTime;

	div_t result = std::div(tempElapsed, 60);

	timeElapsed.min = timeElapsed.min + result.quot;
	timeElapsed.sec = timeElapsed.sec + result.rem;

	if(timeElapsed.sec >= 60){
		div_t miniResult = std::div(timeElapsed.sec, 60);
		timeElapsed.min = timeElapsed.min + miniResult.quot;
		timeElapsed.sec = timeElapsed.sec + miniResult.rem;
	}

	return timeElapsed;
}

void Stopwatch::reset(){
	timeElapsed.min = 0;
	timeElapsed.sec = 0;
}
