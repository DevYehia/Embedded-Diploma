#include "PSensorDriver.h"
#include <time.h>

PSensorStates PSensorStateID;
static int PSensorPressure;
void (*PSensorCurrState)(void);

//helper function
int generate_random(int low, int high){
    srand(time(0));
    return (rand() % (high - low + 1) + low);
}


void PSensorSetup(void){
    printf("PSensor: initialized\n");
    PSensorCurrState = STATE(PSensorReading);
}

STATE_DEFINE(PSensorReading){
    PSensorStateID = P_SENSOR_READING;
    PSensorPressure = generate_random(0,40);
    printf("PSensor: Preesure Reading = %d\n",PSensorPressure);
    setPressure(PSensorPressure);

    //next state
    PSensorCurrState = STATE(PSensorReading);
}

