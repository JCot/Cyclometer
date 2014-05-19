/*
 * FastMode.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ajl2612
 */

#include "FastMode.h"

FastMode::FastMode(std::string message, int id){

    this->message = message;
    this->id = id;

}

std::string FastMode::getMessage(){
    return this-> message;
}


int FastMode::getID(){
    return this-> id;
}
