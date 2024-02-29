#include "AlarmController.h"

AControllerStates AControllerStateID;
void (*AControllerCurrState)(void);

void startAlarm(void){
    AControllerCurrState = STATE(AControllerStarted);
}


void AControllerSetup(void){
    AControllerCurrState = STATE(AControllerNoAlarm);
    Set_Alarm_actuator(1);
}


STATE_DEFINE(AControllerNoAlarm){
    AControllerStateID = A_CONTROLLER_NO_ALARM;
    AControllerCurrState = STATE(AControllerNoAlarm);
}

STATE_DEFINE(AControllerStarted){
    AControllerStateID = A_CONTROLLER_STARTED;
    Set_Alarm_actuator(0);
    Delay(600000);
    Set_Alarm_actuator(1);
    AControllerCurrState = STATE(AControllerNoAlarm);
}