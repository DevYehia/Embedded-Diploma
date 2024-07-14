#ifndef US_H
#define US_H

//includes section
#include "state.h"

//defines section
//None



//Description: initialize the ultrasonic 
void US_init(void);
//Description: Function describes the busy state of the US
STATE_DEFINE(US_busy);

//pointer to current state function
extern void (*curr_US_func)();


#endif