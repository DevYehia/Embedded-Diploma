#ifndef MOTOR_H
#define MOTOR_H

//includes section
#include "state.h"

//defines section
//None



//prototypes
void MOTOR_init(void);
STATE_DEFINE(MOTOR_idle);
STATE_DEFINE(MOTOR_busy);

//current state function
extern void (*curr_MOTOR_func)(void);


#endif