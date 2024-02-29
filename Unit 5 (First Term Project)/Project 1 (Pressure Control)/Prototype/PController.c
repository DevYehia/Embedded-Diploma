#include "PController.h"


PControllerStates PControllerStateID;
static int PControllerPressure;
void (*PControllerCurrState)(void);

void setPressure(int inputPressure){
    PControllerPressure = inputPressure;
    printf("PSensor ----> PCTRL : set pressure to %d\n",PControllerPressure);
    PControllerCurrState = 
    (PControllerPressure > P_THRESHOLD)
    ? STATE(PControllerHighP)
    : STATE(PControllerLowP);
}

void PControllerSetup(void){
    printf("PController: Initialized\n");
    PControllerCurrState = STATE(PControllerLowP);
}

STATE_DEFINE(PControllerLowP){
    PControllerStateID = P_CONTROLLER_LOW_P;
    printf("PCTRL: In Low Pressure State, Pressure = %d\n",PControllerPressure);
}


STATE_DEFINE(PControllerHighP){
    PControllerStateID = P_CONTROLLER_HIGH_P;
    printf("PCTRL: In High Pressure State, Pressure = %d\n",PControllerPressure);
    startAlarm();
}