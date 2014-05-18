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
#include <signal.h>
#include <stdint.h>
#include <pthread.h>

class MagnetSensor {
public:
	MagnetSensor();
	virtual ~MagnetSensor();
	void* pulseDetected();
	void watchSensor();

private:
	struct sigaction sa;
	uintptr_t portBHandle;
	uintptr_t directionHandle;
	bool firstPulse;
	PulseTimer timer;
	PULSE_TIME timeBetweenPulses;
	Calculations calcs;
	pthread_t pulseThread;
};

#endif /* MAGNETSENSOR_H_ */
