/*
 * Reset.cpp
 *
 *  Created on: May 14, 2014
 *      Author: ajl2612
 */

#include "Reset.h"

Reset::Reset(std::string message, int id){

    this->message = message;
    this->id = id;

}

std::string Reset::getMessage(){
    return this-> message;
}


int Reset::getID(){
    return this-> id;
}
