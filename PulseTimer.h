/*
 * PulseTimer.h
 *
 *  Created on: May 11, 2014
 *      Author: jdc9622
 */

#ifndef PULSETIMER_H_
#define PULSETIMER_H_

typedef struct{
	double sec;
}PULSE_TIME;

class PulseTimer {
public:
	PulseTimer();
	virtual ~PulseTimer();
	void start();
	PULSE_TIME stop();
	void reset();

private:
	double startTime;
	PULSE_TIME getTimeElapsed();
	double getTime();
	PULSE_TIME timeElapsed;
};

#endif /* PULSETIMER_H_ */
