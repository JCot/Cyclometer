/*
 * Calculations.cpp
 *
 *  Created on: May 7, 2014
 *      Author: jdc9622
 */

#include "Calculations.h"
#include "global.h"
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

Calculations::Calculations() {
	currentSpeed = 0.0;
	averageSpeed = 0.0;
	tripDistance = 0.0;
	display = Display();
	tripTime.min = 0.0;
	tripTime.sec = 0.0;
//	startTripTimer();
}

Calculations::~Calculations() {
	// TODO Auto-generated destructor stub
}

double Calculations::roundWhole(double num){
	return round(num);
}

double Calculations::roundTenth(double num){
	return double(int(num * 10 + 0.5))/10;
}

void Calculations::calcCurrentSpeed(int wheelCirc, TIME timePassed){
	double tempTime = timePassed.sec;
	currentSpeed = (double)(wheelCirc/100000.0) * (3600/tempTime);

	if(currentSpeed >= 10){
		currentSpeed = roundWhole(currentSpeed);
	}

	else if(currentSpeed >= 1 && currentSpeed < 10){
		currentSpeed = roundTenth(currentSpeed);
	}

	else{
		currentSpeed = 0.0;
	}

	//For testing purposes. Remove before turning in
//	cout << "Current Speed: " << currentSpeed << "\n";

	if(tempTime < 7.92){
		speeds.push_back(currentSpeed);
	}
}

void Calculations::calcAverageSpeed(){
	double total = 0.0;
	double numSpeeds = 0.0;
	for(vector<double>::iterator iter = speeds.begin(); iter != speeds.end(); ++iter){
		numSpeeds++;
		total = total + (double)*iter;
	}

	averageSpeed = total/numSpeeds;

	if(averageSpeed >= 10){
		averageSpeed = roundWhole(averageSpeed);
	}

	else if(averageSpeed >= 1 && averageSpeed < 10){
		averageSpeed = roundTenth(averageSpeed);
	}

	else{
		averageSpeed = 0.0;
	}

	//For testing purposes. Remove before turning in
//	cout << "Average Speed: " << averageSpeed << "\n";
}

void Calculations::calcTripDistance(int wheelCirc){
	tripDistance = tripDistance + (double)(wheelCirc/100000.0);

	//For testing purposes. Remove before turning in
//	if(tripDistance >= 1){
//		cout << "Trip Distance: " << roundTenth(tripDistance) << "\n";
//	}
}

void Calculations::startTripTimer(){
	stopwatch.start();
}

void Calculations::stopTripTimer(){
	stopwatch.stop();
}

TIME Calculations::getTime(){
	TIME time = stopwatch.getTimeElapsed();

	if(time.sec >= 1){
		div_t result = std::div(time.sec, 60);

		tripTime.min += result.quot;
		tripTime.sec = result.rem;
	}

	return tripTime;
}

void Calculations::resetTrip(){
	tripDistance = 0.0;
	currentSpeed = 0.0;
	averageSpeed = 0.0;
	speeds.clear();
	tripTime.min = 0.0;
	tripTime.sec = 0.0;
	rawTime.min = 0.0;
	rawTime.sec = 0.0;
	stopwatch.reset();
}

void Calculations::toggleMode(){
	if(mode == AUTO){
		mode = MANUAL;
	}

	else{
		mode = AUTO;
	}
}

void Calculations::runCalculations(int wheelCirc, TIME timePassed){
	calcCurrentSpeed(wheelCirc, timePassed);

	if((mode == AUTO && timePassed.sec < 7.92) ||
			(mode == MANUAL && doCalculations)){
		calcAverageSpeed();
		calcTripDistance(wheelCirc);

		if(!stopwatch.isRunning()){
			startTripTimer();
		}
	}

	else{
		if(stopwatch.isRunning()){
			stopTripTimer();
		}
	}

	updateDisplay();
}

void Calculations::updateDisplay(){
	string state = "Time"; //Temporary variable until state machine implemented

	if(units == METRIC){
		if(state.compare("Speed") == 0){
			display.displaySpeeds(currentSpeed, averageSpeed);
		}

		else if(state.compare("Time") == 0){
			display.displayTime(getTime());
		}

		else if(state.compare("Distance") == 0){
			display.displayDistance(roundTenth(tripDistance));
		}
	}

	else if(units == ENGLISH){
		if(state.compare("Speed") == 0){
			display.displaySpeeds(roundTenth(currentSpeed * UNIT_CONVERSION_FACTOR),
					roundTenth(averageSpeed * UNIT_CONVERSION_FACTOR));
		}

		else if(state.compare("Time") == 0){
			display.displayTime(getTime());
		}

		else if(state.compare("Distance") == 0){
			display.displayDistance(roundTenth(tripDistance * UNIT_CONVERSION_FACTOR));
		}
	}
}
