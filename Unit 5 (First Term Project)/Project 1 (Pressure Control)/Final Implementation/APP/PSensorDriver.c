#include "PSensorDriver.h"

PSensorStates PSensorStateID;
static uint32 PSensorPressure;
void (*PSensorCurrState)(void);

void PSensorSetup(void){
    PSensorCurrState = STATE(PSensorReading);
}

STATE_DEFINE(PSensorReading){
    PSensorStateID = P_SENSOR_READING;
    PSensorPressure = getPressureVal();
    setPressure(PSensorPressure);

    //next state
    PSensorCurrState = STATE(PSensorReading);
}

