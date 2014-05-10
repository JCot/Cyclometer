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

using namespace std;

static void sigintHandler(int sig){
	//TODO
}

int firstDigit = 1;
int secondDigit = 5;
int thirdDigit = 3;
int fourthDigit = 0;

int * firstDigitSignals;
int * secondDigitSignals;
int * thirdDigitSignals;
int * fourthDigitSignals;

void Display::getDigitSignals(int digit, int * position, bool decimal){
	if(decimal){
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
	int csDecimalPosition = -1;
	int asDecimalPosition = -1;

	if(currentSpeed >= 10){
		firstDigit = (int)(currentSpeed/10);
		secondDigit = ((int)currentSpeed % 10);
		csDecimalPosition = -1;
	}

	else if(currentSpeed >= 0 && currentSpeed < 10){
		firstDigit = (int)currentSpeed;
		secondDigit = ((int)(currentSpeed * 10)) % 10;
		csDecimalPosition = 3;
	}

	if(averageSpeed >= 10){
		thirdDigit = (int)(averageSpeed/10);
		fourthDigit = ((int)averageSpeed % 10);
		asDecimalPosition = -1;
	}

	else if(averageSpeed >= 0 && averageSpeed < 10){
		thirdDigit = (int)averageSpeed;
		fourthDigit = ((int)(averageSpeed * 10)) % 10;
		asDecimalPosition = 1;
	}

	updateDisplay(csDecimalPosition, asDecimalPosition);
}

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
		fourthDigit = (int)(distance * 10) % 10;
	}

	else if(distance >= 100){
		firstDigit = (int)(distance/100);
		secondDigit = (int)(distance); //TODO make this correct
		thirdDigit = (int)distance % 10;
		fourthDigit = (int)(distance * 10) % 10;
	}

	updateDisplay(1, -1);
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

	updateDisplay(2, -1);
}

//decimalPositionOne, decimalPositionTwo - which decimal points
//need to be turned on, number corresponds to which anode it is on
void Display::updateDisplay(int decimalPositionOne, int decimalPositionTwo){
	getDigitSignals(firstDigit, firstDigitSignals, false);
	getDigitSignals(secondDigit, secondDigitSignals, false);
	getDigitSignals(thirdDigit, thirdDigitSignals, false);
	getDigitSignals(fourthDigit, fourthDigitSignals, false);
	//TODO magical bullshit to make display the digits fast enough
}
