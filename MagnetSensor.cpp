/*
 * MagnetSensor.cpp
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#include "MagnetSensor.h"
#include "global.h"

MagnetSensor::MagnetSensor() {
	timer = PulseTimer();
	firstPulse = true;
	calcs = Calculations();
}

MagnetSensor::~MagnetSensor() {
	// TODO Auto-generated destructor stub
}

void MagnetSensor::pulseDetected(){
	if(firstPulse){
		timer.start();
		firstPulse = false;
	}

	else{
		timeBetweenPulses = timer.stop();

		calcs.runCalculations(wheelCirc, timeBetweenPulses);
	}
}
