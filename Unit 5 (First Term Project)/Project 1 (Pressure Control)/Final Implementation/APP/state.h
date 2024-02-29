#ifndef STATE_H
#define STATE_H

//includes
#include "../LIB/types.h"

#define STATE_DEFINE(inpState) void inpState##State(void)
#define STATE(inpState) inpState##State

//Connection Prototypes
void setPressure(uint32 inputPressure);
void startAlarm(void);



#endif