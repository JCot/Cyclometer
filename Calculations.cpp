/*
 * Calculations.cpp
 *
 *  Created on: May 7, 2014
 *      Author: jdc9622
 */

#include "Calculations.h"
#include <string>

Calculations::Calculations() {
	currentSpeed = 0.0;
	averageSpeed = 0.0;
	tripDistance = 0.0;
	totalDistance = 0.0;

}

Calculations::~Calculations() {
	// TODO Auto-generated destructor stub
}

int Calculations::roundWhole(double num){
	if((num + .5) >= ((int)num + 1)){
		return (int)num + 1;
	}

	else{
		return (int)num;
	}
}

double Calculations::roundTenth(double num){
	string numString = std::to_string(num);
	string rounded;

	if(std::stoi(numString.at(3), 10) > 5){

	}
}

void Calculations::calcCurrentSpeed(double wheelCirc, double timePassed){
	currentSpeed = (wheelCirc/100000) * (3600/timePassed);

	if(currentSpeed > 10){
		currentSpeed = roundWhole(currentSpeed);
	}
}

void Calculations::calcAverageSpeed(){
	//TODO Fill in calculation
}

void Calculations::calcTripDistance(double wheelCirc){
	//TODO Fill in calculation
}

void Calculations::calcTotalDistance(double wheelCirc){
	//TODO Fill in calculation
}

bool Calculations::startTotalTimer(){
	return false;
}

bool Calculations::stopTotalTimer(){
	return false;
}

bool Calculations::startTripTimer(){
	return false;
}

bool Calculations::stopTripTimer(){
	return false;
}
