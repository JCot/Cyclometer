/*
 * TripReset.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "TripReset.h"

TripReset::TripReset(std::string message, int id){

    this->message = message;
    this->id = id;

}

std::string TripReset::getMessage(){
    return this-> message;
}


int TripReset::getID(){
    return this-> id;
}
