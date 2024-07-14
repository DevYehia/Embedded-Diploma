#include "MOTOR.h"

static unsigned int MOTOR_speed;

//possible motor states
enum {
    MOTOR_IDLE,
    MOTOR_BUSY
} MOTOR_state;

//current state function
void (*curr_MOTOR_func)(void);

void MOTOR_init(void){

    printf("MOTOR initialized\n");
    curr_MOTOR_func = STATE(MOTOR_idle);
}

void set_MOTOR_speed(int s){
    MOTOR_speed = s;
    curr_MOTOR_func  = STATE(MOTOR_busy);
    printf("CA ------> DC set MOTOR_speed to %d\n",MOTOR_speed);
}

STATE_DEFINE(MOTOR_idle){
    //current state
    MOTOR_state = MOTOR_IDLE;

    printf("IDLE: MOTOR_speed = %d\n", MOTOR_speed);

}

STATE_DEFINE(MOTOR_busy){
    //current state
    MOTOR_state = MOTOR_BUSY;

    printf("BUSY: MOTOR_speed = %d\n", MOTOR_speed);
    curr_MOTOR_func = STATE(MOTOR_idle);
    
}

