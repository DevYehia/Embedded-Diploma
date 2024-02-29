#ifndef P_SENSOR_DRIVER_H
#define P_SENSOR_DRIVER_H

#include "state.h"
#include "../DRIVER/driver.h"

typedef enum {
    P_SENSOR_READING
} PSensorStates;

//prototypes
//Description: Initialize the Pressure Sensor
void PSensorSetup(void);

//possible state functions
//Description: Read the value of pressure from the sensor
STATE_DEFINE(PSensorReading);

extern void (*PSensorCurrState)(void);


#endif