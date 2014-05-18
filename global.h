/*
 * global.h
 *
 *  Created on: May 9, 2014
 *      Author: jdc9622
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <string>

const static int DATA_BASE_ADDRESS = 0x280;
const static int DATA_PORT_A = DATA_BASE_ADDRESS + 0x08;
const static int DATA_PORT_B = DATA_BASE_ADDRESS + 0x09;
const static int DATA_PORT_C = DATA_BASE_ADDRESS + 0x0A;
const static int DATA_DIRECTION = DATA_BASE_ADDRESS + 0x0B;
const static double UNIT_CONVERSION_FACTOR = 0.621371192;
const static int ENGLISH = 1;
const static int METRIC = 0;
const static int AUTO = 1;
const static int MANUAL = 0;

extern int units;
extern int mode;
extern bool doCalculations;
extern int wheelCirc;

extern int firstDigit;
extern int secondDigit;
extern int thirdDigit;
extern int fourthDigit;

extern int firstDigitSignals;
extern int secondDigitSignals;
extern int thirdDigitSignals;
extern int fourthDigitSignals;

extern int * firstSignalsPointer;
extern int * secondSignalsPointer;
extern int * thirdSignalsPointer;
extern int * fourthSignalsPointer;

#endif /* GLOBAL_H_ */
