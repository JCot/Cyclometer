/*
 * Display.h
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Stopwatch.h"
#include <signal.h>
#include <stdint.h>

class Display {
public:
	Display();
	virtual ~Display();
	void displaySpeeds(double currentSpeed, double averageSpeed);
	void displayDistance(double distance);
	void displayTime(TIME time);
	struct sigaction sa;

private:
	uintptr_t portAHandle;
	uintptr_t portBHandle;
	uintptr_t directionHandle;
	void getDigitSignals(int digit, int * position, bool decimal);
	void updateDisplay();
	const static int NOTHING = 0xFF;
	const static int ZERO_NO_DECIMAL = 0x03;
	const static int ZERO_DECIMAL = 0x02;
	const static int ONE_NO_DECIMAL = 0x9F;
	const static int ONE_DECIMAL = 0x9E;
	const static int TWO_NO_DECIMAL = 0x25;
	const static int TWO_DECIMAL = 0x24;
	const static int THREE_NO_DECIMAL = 0x0D;
	const static int THREE_DECIMAL = 0x0C;
	const static int FOUR_NO_DECIMAL = 0x99;
	const static int FOUR_DECIMAL = 0x98;
	const static int FIVE_NO_DECIMAL = 0x49;
	const static int FIVE_DECIMAL = 0x48;
	const static int SIX_NO_DECIMAL = 0x41;
	const static int SIX_DECIMAL = 0x40;
	const static int SEVEN_NO_DECIMAL = 0x1F;
	const static int SEVEN_DECIMAL = 0x1E;
	const static int EIGHT_NO_DECIMAL = 0x01;
	const static int EIGHT_DECIMAL = 0x00;
	const static int NINE_NO_DECIMAL = 0x09;
	const static int NINE_DECIMAL = 0x08;
};

#endif /* DISPLAY_H_ */
