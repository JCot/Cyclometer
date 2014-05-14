//
//  Exit.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__Set__
#define __StateMachine__Set__

#include <iostream>
#include "Event.h"
class Set : public Event{
    
public:
    Set(std::string m, int id);
    std::string getMessage();
    int getID();
    
};
#endif /* defined(__StateMachine__Set__) */
