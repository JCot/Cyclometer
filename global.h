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
const static int DATA_DIRECTION = DATA_BASE_ADDRESS + 0xb;
const static double UNIT_CONVERSION_FACTOR = 0.621371192;
const static std::string ENGLISH = "english";
const static std::string METRIC = "metric";

extern std::string units;

#endif /* GLOBAL_H_ */
