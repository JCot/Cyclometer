/*
 * MagnetSensor.h
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#ifndef MAGNETSENSOR_H_
#define MAGNETSENSOR_H_

#include "PulseTimer.h"
#include "Calculations.h"

class MagnetSensor {
public:
	MagnetSensor();
	virtual ~MagnetSensor();
	void pulseDetected();

private:
	bool firstPulse;
	PulseTimer timer;
	PULSE_TIME timeBetweenPulses;
	Calculations calcs;
};

#endif /* MAGNETSENSOR_H_ */
