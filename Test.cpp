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

Calculations calcs = Calculations();

Test::Test() {
	// TODO Auto-generated constructor stub

}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void testSpeedCalculation(double wheelCirc, TIME timePassed){
	calcs.calcCurrentSpeed(wheelCirc, timePassed);
}

void testAverageSpeed(){
	calcs.calcAverageSpeed();
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

	return EXIT_SUCCESS;
}
