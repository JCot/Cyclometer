/*
 * Test.cpp
 *
 *  Created on: May 10, 2014
 *      Author: jdc9622
 */

#include "Test.h"
#include "Calculations.h"
#include "Stopwatch.h"
#include "Display.h"
#include "MagnetSensor.h"
#include "EventQueue.h"
#include "StateMachine.h"
#include "Keyboard.h"
#include "Input.h"
#include "global.h"
#include <iostream>
#include <unistd.h>


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <string>
#include <queue>


#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>

uintptr_t dirHandle;
uintptr_t ctrlMBHandle;
uint8_t val3 = 0x02;
uint8_t Mcurrent;

using namespace std;

Display display = Display();
Calculations calcs = Calculations(&display);
MagnetSensor sensor = MagnetSensor(&calcs);
pthread_t dummyThread;

Test::Test() {}

Test::~Test() {}

void testSpeedCalculation(int wheelCirc, TIME timePassed){
	calcs.calcCurrentSpeed(wheelCirc, timePassed);
}

void testAverageSpeed(){
	calcs.calcAverageSpeed();
}

void testTripDistance(int wheelCirc){
	for(int i = 0; i <= 455; i++){
		calcs.calcTripDistance(wheelCirc);
	}
}

void testTripTimer(){
	calcs.startTripTimer();
	sleep(5);
	TIME time = calcs.getTime();
	cout << "Min: " << time.min << " Sec: " << time.sec << "\n";
	cout.flush();
}

void testDisplaySpeed(){
	cout << "Test Speeds < 10\n";
	display.displaySpeeds(7.9, 8.5);
//	cout << "Test Speeds > 10\n";
//	display.displaySpeeds(29, 35);
//	cout << "Test Speeds < 1\n";
//	display.displaySpeeds(.5, .6);
}

void testDisplayTime(){
	TIME time;
	time.min = 45;
	time.sec = 23;
	cout << "Test Display Time\n";
	display.displayTime(time);
}

void testDisplayDistance(){
	display.displayDistance(101.4);
}

void* sleepyTime(void* param){
	sleep(5);
	return NULL;
}

void* runMagnetSensor(void* param){
	MagnetSensor* sensor = (MagnetSensor*)param;
	sensor->watchSensor();
}

int main(int argc, char *argv[]){
	bool useTheHardware = false;

	EventQueue myQueue = EventQueue();
	Display display = Display();
	Calculations calc = Calculations(&display);
	MagnetSensor* sensor = new MagnetSensor(&calc);
	Input input = Input(&myQueue);
    StateMachine rageAgainst = StateMachine(&myQueue, &calc, &display);

    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_t sensorThread;
    pthread_create(&sensorThread, NULL, &runMagnetSensor, (void*)sensor);

    int x = 0;
    while(true){
        x++;
        x--;
    }

	return 1;
}

//int main3( int argc, char *argv[]){
//
//	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
//	{
//
//		perror("Failed to get I/O access permission");
//		return 1;
//	}
//
//	dirHandle = mmap_device_io(1, DATA_DIRECTION);
//	ctrlMBHandle = mmap_device_io(1, DATA_PORT_B);
//	out8(dirHandle, val3);
//
//	EventQueue myQueue = EventQueue();
//	Input input = Input(&myQueue);
//	Calculations myCalc = Calculations();
//    StateMachine rageAgainst = StateMachine(&myQueue, &myCalc);
//    MagnetSensor* sensor = new MagnetSensor(&myCalc);
//
//    pthread_attr_t attr;
//
//    pthread_attr_init(&attr);
//    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
//
//    pthread_t magnetSensorThread;
//
//    pthread_create(&magnetSensorThread, NULL, &runMagnetSensor, (void*)sensor);
//
//    int x = 0;
//    while(true){
//        x++;
//        x--;
//    }
//
//	return 1;
//
//}

int main2(int argc, char *argv[]){
	TIME time1;
	TIME time2;
	time1.sec = .13;
	time2.sec = .2;

	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

//	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);

//	testSpeedCalculation(wheelCirc, time1);
//	cout.flush();
//	testSpeedCalculation(wheelCirc, time2);
//	cout.flush();
//	testAverageSpeed();
//	cout.flush();
//	testTripDistance(wheelCirc);
//	cout.flush();
//	testDisplayTime();
//	cout.flush();
//	pthread_join(dummyThread, NULL);
//	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);
//	testDisplaySpeed();
//	pthread_join(dummyThread, NULL);
//	testDisplayDistance();
//	pthread_create(&dummyThread, NULL, &sleepyTime, (void*)1);
//	pthread_join(dummyThread, NULL);
	units = METRIC;
	mode = AUTO;
	sensor.watchSensor();
//	testDisplayDistance();
//	cout.flush();
//	testTripTimer();
//	testTripTimer();

	return EXIT_SUCCESS;
}
