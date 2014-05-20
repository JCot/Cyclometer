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
#include "State.h"

class Calculations {
public:
	Calculations(Display* myDisplay);
	virtual ~Calculations();
	void startTripTimer();
	void stopTripTimer();
	TIME getTime();
	void resetTrip();
	void runCalculations(int wheelCirc, TIME timePassed);
	void setState(int myState);
	void fullReset();

	//Move to private once testing complete
	void calcCurrentSpeed(int wheelCirc, TIME timePassed);
	void calcAverageSpeed();
	void calcTripDistance(int wheelCirc);
	void updateDisplay();
	void toggleMode();
	void toggleCalcs();

private:
	double roundWhole(double num);
	double roundTenth(double num);

	Stopwatch stopwatch;
	double currentSpeed;
	double averageSpeed;
	double tripDistance;
	Display* display;
	TIME tripTime;
	std::vector<double> speeds;
	int state;
	bool doCalculations;
};

#endif /* CALCULATIONS_H_ */
