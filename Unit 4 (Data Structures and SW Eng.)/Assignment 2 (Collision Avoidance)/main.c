#include "state.h"
#include "US.h"
#include "MOTOR.h"
#include "CA.h"

void setup(void){
    US_init();
    MOTOR_init();
}

int main(void){
    setup();
    char dummy[1];
    while(1){
        curr_US_func();
        for(int i = 0 ; i < 100000 ; i++);
        curr_CA_func();
        for(int i = 0 ; i < 100000 ; i++);
        curr_MOTOR_func(); 
        printf("Press Enter to continue: ");    
        gets(dummy);
    }
}