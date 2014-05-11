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
}

Calculations::~Calculations() {
	// TODO Auto-generated destructor stub
}

double Calculations::roundWhole(double num){
	//return round(num);
	return 0.0;
}

double Calculations::roundTenth(double num){
	return double(int(num * 10 + 0.5))/10;
}

void Calculations::calcCurrentSpeed(double wheelCirc, TIME timePassed){
	int tempTime = timePassed.sec + (timePassed.min * 60);
	currentSpeed = (wheelCirc/100000) * (3600/tempTime);

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
	cout << "Current Speed: " << currentSpeed << "\n";

	speeds.push_back(currentSpeed);
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
	cout << "Average Speed: " << averageSpeed << "\n";
}

void Calculations::calcTripDistance(double wheelCirc){
	tripDistance = tripDistance + (wheelCirc/100000);

	//For testing purposes. Remove before turning in
	if(tripDistance >= 1){
		cout << "Trip Distance: " << roundTenth(tripDistance) << "\n";
	}
}

void Calculations::startTripTimer(){
	stopwatch.start();
}

void Calculations::stopTripTimer(){
	stopwatch.stop();
}

TIME Calculations::getTime(){
	return stopwatch.getTimeElapsed();
}

void Calculations::resetTrip(){
	tripDistance = 0.0;
	currentSpeed = 0.0;
	averageSpeed = 0.0;
	tripTime = 0.0;
	stopwatch.reset();
}

void Calculations::runCalculations(double wheelCirc, TIME timePassed){
	calcCurrentSpeed(wheelCirc, timePassed);
	calcAverageSpeed();
	calcTripDistance(wheelCirc);
}

void Calculations::updateDisplay(){
	string state = "Speed"; //Temporary variable until state machine implemented
	units = ENGLISH;

	if(units == METRIC){
		if(state == "Speed"){
			display.displaySpeeds(currentSpeed, averageSpeed);
		}

		else if(state == "Time"){
			display.displayTime(getTime());
		}

		else if(state == "Distance"){
			display.displayDistance(roundTenth(tripDistance));
		}
	}

	else if(units == ENGLISH){
		if(state == "Speed"){
			display.displaySpeeds(roundTenth(currentSpeed * UNIT_CONVERSION_FACTOR),
					roundTenth(averageSpeed * UNIT_CONVERSION_FACTOR));
		}

		else if(state == "Time"){
			display.displayTime(getTime());
		}

		else if(state == "Distance"){
			display.displayDistance(roundTenth(tripDistance * UNIT_CONVERSION_FACTOR));
		}
	}
}
