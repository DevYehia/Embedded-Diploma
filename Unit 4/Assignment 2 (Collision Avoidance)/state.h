#ifndef STATE_H
#define STATE_H

//includes section
#include <stdio.h>
#include <stdlib.h>

//defines section
#define STATE_DEFINE(state) void ST_##state()
#define STATE(state) ST_##state

//connections
void set_US_distance(int d);
void set_MOTOR_speed(int s);

#endif