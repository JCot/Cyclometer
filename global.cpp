/*
 * global.cpp
 *
 *  Created on: May 9, 2014
 *      Author: jdc9622
 */

#include "global.h"

int units = METRIC;
int mode = MANUAL;
bool doCalculations = false;
int wheelCirc = 220;

//Yes this is a terrible place for these variables but it doesn't work
//for them to be defined in Display.h Or at least we don't
//have time to figure out a way aorund the problems.
int firstDigit = 0;
int secondDigit = 0;
int thirdDigit = 0;
int fourthDigit = 0;

int firstDigitSignals = NOTHING;
int secondDigitSignals = NOTHING;
int thirdDigitSignals = NOTHING;
int fourthDigitSignals = ONE_NO_DECIMAL;

int * firstSignalsPointer = &firstDigitSignals;
int * secondSignalsPointer = &secondDigitSignals;
int * thirdSignalsPointer = &thirdDigitSignals;
int * fourthSignalsPointer = &fourthDigitSignals;
