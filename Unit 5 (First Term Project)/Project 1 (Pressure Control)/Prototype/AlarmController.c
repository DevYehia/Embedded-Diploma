#include "AlarmController.h"

AControllerStates AControllerStateID;
void (*AControllerCurrState)(void);

void startAlarm(void){
    AControllerCurrState = STATE(AControllerStarted);
    printf("PCTRL ----> ACTRL : Alarm Started\n");
}


void AControllerSetup(void){
    printf("ACTRL: Initialized\n");
    AControllerCurrState = STATE(AControllerNoAlarm);
}


STATE_DEFINE(AControllerNoAlarm){
    AControllerStateID = A_CONTROLLER_NO_ALARM;
    printf("ACTRL ----> NO ALARM\n");
    AControllerCurrState = STATE(AControllerNoAlarm);
}

STATE_DEFINE(AControllerStarted){
    AControllerStateID = A_CONTROLLER_STARTED; 
    printf("ACTRL ----> ALARM STARTED\n");
    AControllerCurrState = STATE(AControllerNoAlarm);
}