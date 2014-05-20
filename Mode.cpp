/*
 * Mode.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "Mode.h"

Mode::Mode(std::string message, int id){

    this->message = message;
    this->id = id;

}

std::string Mode::getMessage(){
    return this-> message;
}


int Mode::getID(){
    return this-> id;
}
