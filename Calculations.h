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
	void runCalculations(int wheelCirc, TIME timePassed);

	//Move to private once testing complete
	void calcCurrentSpeed(int wheelCirc, TIME timePassed);
	void calcAverageSpeed();
	void calcTripDistance(int wheelCirc);
	void updateDisplay();
	void toggleMode();

private:
	double roundWhole(double num);
	double roundTenth(double num);

	Stopwatch stopwatch;
	double currentSpeed;
	double averageSpeed;
	double tripDistance;
	Display display;
	TIME tripTime;
	TIME rawTime;
	std::vector<double> speeds;
};

#endif /* CALCULATIONS_H_ */
