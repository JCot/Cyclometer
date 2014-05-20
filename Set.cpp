//
//  Set.cpp
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#include "Set.h"

Set::Set(std::string message, int id){
    
    this->message = message;
    this->id = id;
    
}

std::string Set::getMessage(){
    return this-> message;
}


int Set::getID(){
    return this-> id;
}
