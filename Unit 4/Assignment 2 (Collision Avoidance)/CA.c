#include "CA.h"

unsigned int CA_distance;
unsigned int CA_speed;
int threshold = 50;

//possible CA states
enum{
    CA_WAITING,
    CA_DRIVING
} CA_state;

//pointer to current CA state function
void (*curr_CA_func)();

void set_US_distance(int d){
    CA_distance = d;
    curr_CA_func = (CA_distance >= threshold) ? STATE(CA_driving): STATE(CA_waiting);
    printf("US ------> CA : distance = %d\n",d);
}
STATE_DEFINE(CA_waiting){
    CA_state = CA_WAITING;
    CA_speed = 0;
    printf("CA Waiting: distance =  %d || speed = %d\n",CA_distance, CA_speed);
    set_MOTOR_speed(CA_speed);

}

STATE_DEFINE(CA_driving){
    CA_state = CA_DRIVING;
    CA_speed = 30;
    printf("CA Driving: distance =  %d || speed = %d\n",CA_distance, CA_speed);
    set_MOTOR_speed(CA_speed);
}