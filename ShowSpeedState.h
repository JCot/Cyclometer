//
//  ShowSpeedState.h
//  StateMachine
//
//  Created by Andrew III Lyne on 3/19/14.
//  Copyright (c) 2014 Andrew III Lyne. All rights reserved.
//

#ifndef __StateMachine__ShowSpeedState__
#define __StateMachine__ShowSpeedState__

#include <iostream>
#include "State.h"

class ShowSpeedState : public State{
private:
    
public:
	ShowSpeedState();
    void onEntry();
    void onReEntry();
    void onExit();
    int transition( int event_id);

};
#endif /* defined(__StateMachine__ShowSpeedState__) */
