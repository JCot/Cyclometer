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
#include "Display.h"

class Calculations {
public:
	Calculations();
	virtual ~Calculations();
	void startTripTimer();
	void stopTripTimer();
	TIME getTime();
	void resetTrip();
	void runCalculations(double wheelCirc, TIME timePassed);

private:
	double roundWhole(double num);
	double roundTenth(double num);
	void calcCurrentSpeed(double wheelCirc, TIME timePassed);
	void calcAverageSpeed();
	void calcTripDistance(double wheelCirc);
	void updateDisplay();
	Stopwatch stopwatch;
	double currentSpeed;
	double averageSpeed;
	double tripDistance;
	double startTime;
	double endTime;
	Display display;
	time_t tripTime;
	std::vector<double> speeds;
};

#endif /* CALCULATIONS_H_ */
