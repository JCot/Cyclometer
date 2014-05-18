/*
 * MagnetSensor.cpp
 *
 *  Created on: May 8, 2014
 *      Author: jdc9622
 */

#include "MagnetSensor.h"
#include "global.h"
#include <time.h>
#include <unistd.h>
#include <hw/inout.h>
#include <sys/neutrino.h>
#include <sys/mman.h>
#include <iostream>
#include <stdio.h>

using namespace std;

static void sigintHandler(int sig){
	//TODO
}

MagnetSensor::MagnetSensor() {
	timer = PulseTimer();
	firstPulse = true;
	calcs = Calculations();

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigintHandler;
	signal(SIGUSR1, sigintHandler);

	ThreadCtl(_NTO_TCTL_IO, NULL);

	portBHandle = mmap_device_io(1, DATA_PORT_B);
	directionHandle = mmap_device_io(1, DATA_DIRECTION);

	if(portBHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	if(directionHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	out8(directionHandle, 0x02);
}

MagnetSensor::~MagnetSensor() {
	// TODO Auto-generated destructor stub
}

void* pulseDetectedHelper(void* param){
	return static_cast<MagnetSensor*>(param)->pulseDetected();
}

void* MagnetSensor::pulseDetected(){
	if(firstPulse){
		timer.start();
		firstPulse = false;
	}

	else{
		timeBetweenPulses = timer.stop();
		timer.start();

		calcs.runCalculations(wheelCirc, timeBetweenPulses);

	}

	return NULL;
}

void MagnetSensor::watchSensor(){
	//Need to make sure sleep time is slower than calculation speed
	//Calculations should finish in under 100 nanoseconds
	struct timespec tim;
	tim.tv_sec = 0;
	tim.tv_nsec = 500;

	int magnetValue = 0x80;
	int oldValue = 0x80;
	int temp;
	int mask = 0x80;

	while(true){
		temp = in8(portBHandle);
		magnetValue = temp & mask;

		if(magnetValue != oldValue){
			pthread_create(&pulseThread, NULL, &pulseDetectedHelper, this);
		}

		oldValue = magnetValue;

		nanosleep(&tim, NULL);
	}
}
