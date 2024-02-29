#ifndef ALARM_CONTROLLER_H
#define ALARM_CONTROLLER_H

#include "state.h"
#include "../DRIVER/driver.h"

#define TIMEOUT 60


typedef enum {
    A_CONTROLLER_NO_ALARM,
    A_CONTROLLER_STARTED
} AControllerStates;

//prototypes
//Description: Initialize the Alarm Controller
void AControllerSetup(void);

//possible state functions
STATE_DEFINE(AControllerNoAlarm);
STATE_DEFINE(AControllerStarted);

extern void (*AControllerCurrState)(void);

#endif