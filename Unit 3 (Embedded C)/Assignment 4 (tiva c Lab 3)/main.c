//Made by Prof. yehia

#include "types.h"
#include "bitwise.h"


#define SYSCTL_RCGC2_R     *((v_uint32 *)0x400FE108)
#define GPIO_PORTF_DATA_R  *((v_uint32 *)0x400253FC)
#define GPIO_PORTF_DIR_R   *((v_uint32 *)0x40025400)
#define GPIO_PORTF_DEN_R   *((v_uint32 *)0x4002551C)

int main(void){
    v_uint32 delay;
    SET_BIT(SYSCTL_RCGC2_R, 5); //enable clock for port F
    for(delay = 0 ; delay < 200; delay++); //wait till clock is enabled
    SET_BIT(GPIO_PORTF_DIR_R, 3); //pin 3 is output
    SET_BIT(GPIO_PORTF_DEN_R, 3);
    CLR_BIT(GPIO_PORTF_DATA_R, 3); //led is OFF
    while(1){
        TOGGLE_BIT(GPIO_PORTF_DATA_R, 3);
        for(delay = 0 ; delay < 200000; delay++);
        TOGGLE_BIT(GPIO_PORTF_DATA_R, 3);
        for(delay = 0 ; delay < 200000; delay++);        
    }
    return 0;
}