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
#include <iostream>
#include <unistd.h>

using namespace std;

Calculations calcs = Calculations();
Display display = Display();

Test::Test() {}

Test::~Test() {}

void testSpeedCalculation(double wheelCirc, TIME timePassed){
	calcs.calcCurrentSpeed(wheelCirc, timePassed);
}

void testAverageSpeed(){
	calcs.calcAverageSpeed();
}

void testTripDistance(double wheelCirc){
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

void testDisplay(){
	TIME time;
	time.min = 45;
	time.sec = 23;
	display.displayTime(time);
}

int main(int argc, char *argv[]){
	TIME time1;
	TIME time2;
	time1.min = 0;
	time1.sec = 1;
	time2.min = 0;
	time2.sec = 2;
	double wheel = 220;

	testSpeedCalculation(wheel, time1);
	testSpeedCalculation(wheel, time2);
	testAverageSpeed();
	testTripDistance(wheel);
	testDisplay();
	testTripTimer();
	testTripTimer();

	return EXIT_SUCCESS;
}
