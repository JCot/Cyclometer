/*
 * Test.cpp
 *
 *  Created on: May 10, 2014
 *      Author: jdc9622
 */

#include "Test.h"
#include "Calculations.h"
#include "Stopwatch.h"
#include "Display.h"
#include "global.h"
#include <iostream>
#include <unistd.h>

using namespace std;

Calculations calcs = Calculations();
Display display = Display();
pthread_t dummyThread;

Test::Test() {}

Test::~Test() {}

void testSpeedCalculation(int wheelCirc, PULSE_TIME timePassed){
	calcs.calcCurrentSpeed(wheelCirc, timePassed);
}

void testAverageSpeed(){
	calcs.calcAverageSpeed();
}

void testTripDistance(int wheelCirc){
	for(int i = 0; i <= 455; i++){
		calcs.calcTripDistance(wheelCirc);
	}
}

void testTripTimer(){
	calcs.startTripTimer();
	sleep(5);
	TIME time = calcs.getTime();
	cout << "Min: " << time.min << " Sec: " << time.sec << "\n";
	cout.flush();
}

void testDisplaySpeed(){
	cout << "Test Speeds < 10\n";
	display.displaySpeeds(7.9, 8.5);
//	cout << "Test Speeds > 10\n";
//	display.displaySpeeds(29, 35);
//	cout << "Test Speeds < 1\n";
//	display.displaySpeeds(.5, .6);
}

void testDisplayTime(){
	TIME time;
	time.min = 45;
	time.sec = 23;
	cout << "Test Display Time\n";
	display.displayTime(time);
}

void testDisplayDistance(){
	display.displayDistance(101.4);
}

void* sleepyTime(void* param){
	sleep(5);
	return NULL;
}

int main(int argc, char *argv[]){
	PULSE_TIME time1;
	PULSE_TIME time2;
	time1.sec = .13;
	time2.sec = .2;

	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);

//	testSpeedCalculation(wheelCirc, time1);
//	cout.flush();
//	testSpeedCalculation(wheelCirc, time2);
//	cout.flush();
//	testAverageSpeed();
//	cout.flush();
//	testTripDistance(wheelCirc);
//	cout.flush();
//	testDisplayTime();
//	cout.flush();
	pthread_join(dummyThread, NULL);
	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);
	testDisplaySpeed();
	pthread_join(dummyThread, NULL);
	testDisplayDistance();
	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);
	pthread_join(dummyThread, NULL);
//	testDisplayDistance();
//	cout.flush();
//	testTripTimer();
//	testTripTimer();

	return EXIT_SUCCESS;
}
