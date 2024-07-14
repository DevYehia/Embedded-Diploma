#include "US.h"

static unsigned int US_distance;

//possible US states
enum {
    US_BUSY
} US_state;

//pointer to current state function
void (*curr_US_func)();

int generate_random(int low, int high){
    return (rand() % (high - low + 1) + low);
}


void US_init(void){
    printf("US initialized\n");
    curr_US_func = STATE(US_busy);
}

STATE_DEFINE(US_busy){

    //current state
    US_state = US_BUSY;

    US_distance = generate_random(45,55);
    printf("US BUSY: Mesaured Distance = %d cm\n",US_distance);
    set_US_distance(US_distance);

}