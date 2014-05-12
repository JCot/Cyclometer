/*
 * Display.cpp
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#include "Display.h"
#include "global.h"
#include <string>
#include <unistd.h>
#include <hw/inout.h>
#include <sys/neutrino.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

int firstDigit;
int secondDigit;
int thirdDigit;
int fourthDigit;

int firstDigitSignals;
int secondDigitSignals;
int thirdDigitSignals;
int fourthDigitSignals;

int * firstSignalsPointer = &firstDigitSignals;
int * secondSignalsPointer = &secondDigitSignals;
int * thirdSignalsPointer = &thirdDigitSignals;
int * fourthSignalsPointer = &fourthDigitSignals;

static void sigintHandler(int sig){
	//TODO
}

void Display::getDigitSignals(int digit, int * position, bool decimal){
	if(!decimal){
		switch(digit){
		case 0:
			*position = ZERO_NO_DECIMAL;
			break;
		case 1:
			*position = ONE_NO_DECIMAL;
			break;
		case 2:
			*position = TWO_NO_DECIMAL;
			break;
		case 3:
			*position = THREE_NO_DECIMAL;
			break;
		case 4:
			*position = FOUR_NO_DECIMAL;
			break;
		case 5:
			*position = FIVE_NO_DECIMAL;
			break;
		case 6:
			*position = SIX_NO_DECIMAL;
			break;
		case 7:
			*position = SEVEN_NO_DECIMAL;
			break;
		case 8:
			*position = EIGHT_NO_DECIMAL;
			break;
		case 9:
			*position = NINE_NO_DECIMAL;
			break;
		default:
			*position = NOTHING;
			break;
		}
	}

	else{
		switch(digit){
		case 0:
			*position = ZERO_DECIMAL;
			break;
		case 1:
			*position = ONE_DECIMAL;
			break;
		case 2:
			*position = TWO_DECIMAL;
			break;
		case 3:
			*position = THREE_DECIMAL;
			break;
		case 4:
			*position = FOUR_DECIMAL;
			break;
		case 5:
			*position = FIVE_DECIMAL;
			break;
		case 6:
			*position = SIX_DECIMAL;
			break;
		case 7:
			*position = SEVEN_DECIMAL;
			break;
		case 8:
			*position = EIGHT_DECIMAL;
			break;
		case 9:
			*position = NINE_DECIMAL;
			break;
		default:
			*position = NOTHING;
			break;
		}
	}
}

Display::Display() {

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigintHandler;
	signal(SIGUSR1, sigintHandler);

	ThreadCtl(_NTO_TCTL_IO, NULL);

	portAHandle = mmap_device_io(1, DATA_PORT_A);
	portBHandle = mmap_device_io(1, DATA_PORT_B);
	directionHandle = mmap_device_io(1, DATA_DIRECTION);

	if(portAHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	if(portBHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	if(directionHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

}

Display::~Display() {
	// TODO Auto-generated destructor stub
}

void Display::displaySpeeds(double currentSpeed, double averageSpeed){
	bool csDecimal = false;
	bool asDecimal = false;

	if(currentSpeed >= 10){
		firstDigit = (int)(currentSpeed/10);
		secondDigit = ((int)currentSpeed % 10);
		csDecimal = false;
	}

	else if(currentSpeed >= 1 && currentSpeed < 10){
		firstDigit = (int)currentSpeed;
		secondDigit = ((int)(currentSpeed * 10)) % 10;
		csDecimal = true;
	}

	else if(currentSpeed >= 0 && currentSpeed < 1){
		firstDigit = 0;
		secondDigit = 0;
		csDecimal = true;
	}

	else if(currentSpeed > 99){
		firstDigit = 9;
		secondDigit = 9;
		csDecimal = false;
	}

	if(averageSpeed >= 10){
		thirdDigit = (int)(averageSpeed/10);
		fourthDigit = ((int)averageSpeed % 10);
		asDecimal = false;
	}

	else if(averageSpeed >= 1 && averageSpeed < 10){
		thirdDigit = (int)averageSpeed;
		fourthDigit = ((int)(averageSpeed * 10)) % 10;
		asDecimal = true;
	}

	else if(averageSpeed >= 0 && averageSpeed < 1){
		thirdDigit = 0;
		fourthDigit = 0;
		asDecimal = true;
	}

	else if(averageSpeed > 99){
		thirdDigit = 9;
		fourthDigit = 9;
		asDecimal = false;
	}

	if(csDecimal && !asDecimal){
		getDigitSignals(firstDigit, firstSignalsPointer, true);
		getDigitSignals(secondDigit, secondSignalsPointer, false);
		getDigitSignals(thirdDigit, thirdSignalsPointer, false);
		getDigitSignals(fourthDigit, fourthSignalsPointer, false);
	}

	else if(!csDecimal && asDecimal){
		getDigitSignals(firstDigit, firstSignalsPointer, false);
		getDigitSignals(secondDigit, secondSignalsPointer, false);
		getDigitSignals(thirdDigit, thirdSignalsPointer, true);
		getDigitSignals(fourthDigit, fourthSignalsPointer, false);
	}

	else if(csDecimal && asDecimal){
		getDigitSignals(firstDigit, firstSignalsPointer, true);
		getDigitSignals(secondDigit, secondSignalsPointer, false);
		getDigitSignals(thirdDigit, thirdSignalsPointer, true);
		getDigitSignals(fourthDigit, fourthSignalsPointer, false);
	}

	else{
		getDigitSignals(firstDigit, firstSignalsPointer, false);
		getDigitSignals(secondDigit, secondSignalsPointer, false);
		getDigitSignals(thirdDigit, thirdSignalsPointer, false);
		getDigitSignals(fourthDigit, fourthSignalsPointer, false);
	}

	updateDisplay();
}

//TODO Solve double precision errors ex. 17.2 = 17.1999999999999. So 17.1 is displayed
void Display::displayDistance(double distance){

	if(distance < 1){
		firstDigit = -1;
		secondDigit = -1;
		thirdDigit = 0;
		fourthDigit = (int)(distance * 10);
	}

	else if(distance >= 1 && distance < 10){
		firstDigit = -1;
		secondDigit = -1;
		thirdDigit = (int)(distance);
		fourthDigit = ((int)(distance * 10) % 10);
	}

	else if(distance >= 10 && distance < 100){
		firstDigit = -1;
		secondDigit = (int)(distance/10);
		thirdDigit = (int)distance % 10;
		fourthDigit = ((int)(distance * 10)) % 10;
	}

	else if(distance >= 100){
		firstDigit = (int)(distance/100);
		secondDigit = ((int)(distance/10)) % 10;
		thirdDigit = (int)distance % 10;
		fourthDigit = ((int)(distance * 10)) % 10;
	}

	getDigitSignals(firstDigit, firstSignalsPointer, false);
	getDigitSignals(secondDigit, secondSignalsPointer, false);
	getDigitSignals(thirdDigit, thirdSignalsPointer, true);
	getDigitSignals(fourthDigit, fourthSignalsPointer, false);

	updateDisplay();
}

void Display::displayTime(TIME time){

	int min = time.min;
	int sec = time.sec;

	if(min < 10){
		firstDigit = 0;
		secondDigit = min;
	}

	else if(min >= 10){
		firstDigit = (int)(min/10);
		secondDigit = min % 10;
	}

	if(sec < 10){
		thirdDigit = 0;
		fourthDigit = sec;
	}

	else{
		thirdDigit = (int)(sec/10);
		fourthDigit = sec % 10;
	}

	getDigitSignals(firstDigit, firstSignalsPointer, false);
	getDigitSignals(secondDigit, secondSignalsPointer, true);
	getDigitSignals(thirdDigit, thirdSignalsPointer, false);
	getDigitSignals(fourthDigit, fourthSignalsPointer, false);

	updateDisplay();
}

void Display::updateDisplay(){
	//TODO magical bullshit to display the digits fast enough

	//For Testing
	cout << "First Digit: " << firstDigit << "\n";
	cout << "First Digit Signal: " << *firstSignalsPointer << "\n";
	cout << "Second Digit: " << secondDigit << "\n";
	cout << "Second Digit Signal: " << *secondSignalsPointer << "\n";
	cout << "Third Digit: " << thirdDigit << "\n";
	cout << "Third Digit Signal: " << *thirdSignalsPointer << "\n";
	cout << "Fourth Digit: " << fourthDigit << "\n";
	cout << "Fourth Digit Signal: " << *fourthSignalsPointer << "\n";
}
