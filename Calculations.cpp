/*
 * Calculations.cpp
 *
 *  Created on: May 7, 2014
 *      Author: jdc9622
 */

#include "Calculations.h"
#include <string>
#include <math.h>

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

void Calculations::calcCurrentSpeed(double wheelCirc, double timePassed){
	currentSpeed = (wheelCirc/100000) * (3600/timePassed);

	if(currentSpeed >= 10){
		currentSpeed = roundWhole(currentSpeed);
	}

	else if(currentSpeed >= 1 && currentSpeed < 10){
		currentSpeed = roundTenth(currentSpeed);
	}

	else{
		currentSpeed = 0.0;
	}

	speeds.push_back(currentSpeed);
}

void Calculations::calcAverageSpeed(){
	double total = 0.0;
	double numSpeeds = 0.0;
	for(std::vector<double>::iterator iter = speeds.begin(); iter != speeds.end(); ++iter){
		numSpeeds++;
		total = total + (double)*iter;
	}

	averageSpeed = total/numSpeeds;
}

void Calculations::calcTripDistance(double wheelCirc){
	tripDistance = tripDistance + wheelCirc;
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

void Calculations::resetAll(){
	tripDistance = 0.0;
	currentSpeed = 0.0;
	averageSpeed = 0.0;
	tripTime = 0.0;
}
