//
//  State.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/18/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__State__
#define __StateMachine__State__

#define STATE_FULLRESET 0
#define STATE_SETUNITS 1
#define STATE_SETTIRE 2
#define STATE_SHOWDISTANCE 3
#define STATE_SHOWSPEED 4
#define STATE_SHOWTIME 5

#define EVENT_SET 's'
#define EVENT_MODE 'm'
#define EVENT_FASTMODE 'f'
#define EVENT_TRIPRESET 't'
#define EVENT_RESET 'r'
#define EVENT_STARTSTOP 'x'

#include <iostream>
#include <stdio.h>

class State{
protected:
    
    int stateID;
    std::string name;
    
public:
    int NOP();
    std::string getName();
    int getID();

    virtual int transition( int event_id ) = 0;
    virtual void onEntry() = 0;
    virtual void onReEntry() = 0;
    virtual void onExit() = 0;
};

#endif /* defined(__StateMachine__State__) */
