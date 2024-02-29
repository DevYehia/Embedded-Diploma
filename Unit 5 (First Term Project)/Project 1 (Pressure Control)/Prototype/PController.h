#ifndef P_CONTROLLER_H
#define P_CONTROLLER_H

#include "state.h"

#define P_THRESHOLD  20

typedef enum {
    P_CONTROLLER_LOW_P,
    P_CONTROLLER_HIGH_P    
} PControllerStates;

//prototypes
//Description: Initialize the Pressure Sensor
void PControllerSetup(void);

//possible state functions
//Description: Pressure is below the threshold so do nothing
STATE_DEFINE(PControllerLowP);

//Description: Pressure is above the threshold so start the alarm
STATE_DEFINE(PControllerHighP);

extern void (*PControllerCurrState)(void);









#endif