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
const static std::string ENGLISH = "imperial";
const static std::string METRIC = "metric";
const static std::string AUTO = "automatic";
const static std::string MANUAL = "manual";

extern std::string units;
extern std::string mode;
extern bool doCalculations;
extern int wheelCirc;

#endif /* GLOBAL_H_ */
