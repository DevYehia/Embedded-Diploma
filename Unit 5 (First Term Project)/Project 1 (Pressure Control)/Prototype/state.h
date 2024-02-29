#ifndef STATE_H
#define STATE_H

//includes
#include <stdio.h>
#include <stdlib.h>

#define STATE_DEFINE(inpState) void inpState##State(void)
#define STATE(inpState) inpState##State

//Connection Prototypes
void setPressure(int inputPressure);
void startAlarm(void);



#endif