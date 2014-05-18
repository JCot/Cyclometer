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

const static int NOTHING = 0xFF;
const static int ZERO_NO_DECIMAL = 0xC0;
const static int ZERO_DECIMAL = 0x40;
const static int ONE_NO_DECIMAL = 0xF9;
const static int ONE_DECIMAL = 0x79;
const static int TWO_NO_DECIMAL = 0xA4;
const static int TWO_DECIMAL = 0x24;
const static int THREE_NO_DECIMAL = 0xB0;
const static int THREE_DECIMAL = 0x30;
const static int FOUR_NO_DECIMAL = 0x99;
const static int FOUR_DECIMAL = 0x19;
const static int FIVE_NO_DECIMAL = 0x92;
const static int FIVE_DECIMAL = 0x12;
const static int SIX_NO_DECIMAL = 0x82;
const static int SIX_DECIMAL = 0x02;
const static int SEVEN_NO_DECIMAL = 0xF8;
const static int SEVEN_DECIMAL = 0x78;
const static int EIGHT_NO_DECIMAL = 0x80;
const static int EIGHT_DECIMAL = 0x00;
const static int NINE_NO_DECIMAL = 0x90;
const static int NINE_DECIMAL = 0x10;

const static int ANODE_ZERO = 0xFE;
const static int ANODE_ONE = 0xFD;
const static int ANODE_TWO = 0xFB;
const static int ANODE_THREE = 0xF7;

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
