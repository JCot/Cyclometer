/*
 * StartStop.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "StartStop.h"

StartStop::StartStop(std::string message, int id){

    this->message = message;
    this->id = id;

}

std::string StartStop::getMessage(){
    return this-> message;
}


int StartStop::getID(){
    return this-> id;
}
