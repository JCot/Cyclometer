/*
 * Stopwatch.h
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

typedef struct{
	int min;
	int sec;
}TIME;

class Stopwatch {

public:
	Stopwatch();
	virtual ~Stopwatch();
	void start();
	TIME stop();
	void reset();
	int getTime();
	TIME getTimeElapsed();

private:
	double startTime;
	TIME timeElapsed;
};

#endif /* STOPWATCH_H_ */
