#include "PController.h"


PControllerStates PControllerStateID;
static uint32 PControllerPressure;
void (*PControllerCurrState)(void);

void setPressure(uint32 inputPressure){
    PControllerPressure = inputPressure;
    PControllerCurrState = 
    (PControllerPressure > P_THRESHOLD)
    ? STATE(PControllerHighP)
    : STATE(PControllerLowP);
}

void PControllerSetup(void){
    PControllerCurrState = STATE(PControllerLowP);
}

STATE_DEFINE(PControllerLowP){
    PControllerStateID = P_CONTROLLER_LOW_P;
}


STATE_DEFINE(PControllerHighP){
    PControllerStateID = P_CONTROLLER_HIGH_P;
    startAlarm();
}