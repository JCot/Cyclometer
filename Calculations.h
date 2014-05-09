/*
 * Calculations.h
 *
 *  Created on: May 7, 2014
 *      Author: jdc9622
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

#include <time.h>
#include <vector>
#include "Stopwatch.h"

class Calculations {
public:
	Calculations();
	virtual ~Calculations();
	void calcCurrentSpeed(double wheelCirc, double timePassed);
	void calcAverageSpeed();
	void calcTripDistance(double wheelCirc);
	void startTripTimer();
	void stopTripTimer();
	TIME getTime();
	void resetAll();
	void resetTrip();
	void updateDisplay();

private:
	double roundWhole(double num);
	double roundTenth(double num);
	Stopwatch stopwatch;
	double currentSpeed;
	double averageSpeed;
	double tripDistance;
	double startTime;
	double endTime;
	time_t tripTime;
	std::vector<double> speeds;
};

#endif /* CALCULATIONS_H_ */
