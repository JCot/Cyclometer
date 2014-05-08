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

class Calculations {
public:
	Calculations();
	virtual ~Calculations();
	void calcCurrentSpeed(double wheelCirc, double timePassed);
	void calcAverageSpeed();
	void calcTripDistance(double wheelCirc);
	void calcTotalDistance(double wheelCirc);
	bool startTotalTimer();
	bool stopTotalTimer();
	bool startTripTimer();
	bool stopTripTimer();
	bool reset();

private:
	int roundWhole(double num);
	double roundTenth(double num);
	double currentSpeed;
	double averageSpeed;
	double tripDistance;
	double totalDistance;
	time_t tripTime;
	time_t totalTime;
	std::vector<int> speeds;
};

#endif /* CALCULATIONS_H_ */
