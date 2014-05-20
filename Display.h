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
#include <pthread.h>

class Display {
public:
	Display();
	virtual ~Display();
	void displaySpeeds(double currentSpeed, double averageSpeed);
	void displayDistance(double distance);
	void displayTime(TIME time);
	void displayWheelCirc(int wheelCirc);
	void displayUnits(bool usingMetric);
	void* updateDisplay();
//	void updateDisplayHelper();

private:
	struct sigaction sa;
	uintptr_t portAHandle;
	uintptr_t portCHandle;
	uintptr_t directionHandle;
	pthread_t displayThread;
	void getDigitSignals(int digit, int * position, bool decimal);

//	int firstDigit;
//	int secondDigit;
//	int thirdDigit;
//	int fourthDigit;
//
//	int firstDigitSignals;
//	int secondDigitSignals;
//	int thirdDigitSignals;
//	int fourthDigitSignals;
//
//	int * firstSignalsPointer;
//	int * secondSignalsPointer;
//	int * thirdSignalsPointer;
//	int * fourthSignalsPointer;

//	const static int NOTHING = 0xFF;
//	const static int ZERO_NO_DECIMAL = 0xC0;
//	const static int ZERO_DECIMAL = 0x40;
//	const static int ONE_NO_DECIMAL = 0xF9;
//	const static int ONE_DECIMAL = 0x79;
//	const static int TWO_NO_DECIMAL = 0xA4;
//	const static int TWO_DECIMAL = 0x24;
//	const static int THREE_NO_DECIMAL = 0xB0;
//	const static int THREE_DECIMAL = 0x30;
//	const static int FOUR_NO_DECIMAL = 0x99;
//	const static int FOUR_DECIMAL = 0x19;
//	const static int FIVE_NO_DECIMAL = 0x92;
//	const static int FIVE_DECIMAL = 0x12;
//	const static int SIX_NO_DECIMAL = 0x82;
//	const static int SIX_DECIMAL = 0x02;
//	const static int SEVEN_NO_DECIMAL = 0xF8;
//	const static int SEVEN_DECIMAL = 0x78;
//	const static int EIGHT_NO_DECIMAL = 0x80;
//	const static int EIGHT_DECIMAL = 0x00;
//	const static int NINE_NO_DECIMAL = 0x90;
//	const static int NINE_DECIMAL = 0x10;
//
//	const static int ANODE_ZERO = 0xFE;
//	const static int ANODE_ONE = 0xFD;
//	const static int ANODE_TWO = 0xFB;
//	const static int ANODE_THREE = 0xF7;
};

#endif /* DISPLAY_H_ */
