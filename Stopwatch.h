/*
 * PulseTimer.h
 *
 *  Created on: May 11, 2014
 *      Author: jdc9622
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

typedef struct{
	double min;
	double sec;
}TIME;

class Stopwatch {
public:
	Stopwatch();
	virtual ~Stopwatch();
	void start();
	TIME stop();
	void reset();
	TIME getTimeElapsed();
	bool isRunning();

private:
	double startTime;
	double endTime;
	double prevTimeElapsed;
	double getTime();
	TIME timeElapsed;
	bool running;
};

#endif /* STOPWATCH_H_ */
