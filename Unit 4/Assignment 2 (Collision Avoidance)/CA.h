#ifndef CA_H
#define CA_H

//includes section
#include "state.h"

//defines section
//None




STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

//pointer to current CA state function
extern void (*curr_CA_func)();






#endif