#include "exti.h"
#define EXTI_HANDLER(lineNo)    void EXTI##lineNo##_IRQHandler(void){ \
                                    if(EXTI_callBacks[lineNo] != 0){ \
                                        EXTI_callBacks[lineNo](); \
                                    } \
                                    SET_BIT(EXTI->PR,lineNo); \
                                }

#define CHECK_PR_AND_CALL_ISR(lineNo)   if(GET_BIT(EXTI->PR,lineNo)){ \
                                            if(EXTI_callBacks[lineNo] != 0){ \
                                                EXTI_callBacks[lineNo](); \
                                            } \
                                            SET_BIT(EXTI->PR,lineNo); \
                                        }

#define GET_GPIO_STRUCT(port)   (port == EXTI_GPIOA ? GPIOA :   \
                                 port == EXTI_GPIOB ? GPIOB :   \
                                 port == EXTI_GPIOC ? GPIOC :   \
                                 port == EXTI_GPIOD ? GPIOD :   \
                                 port == EXTI_GPIOE ? GPIOE : 0)

 void (* EXTI_callBacks[16])(void);



static uint8_t get_NVIC_IRQ(uint8_t EXTI_pin_number){
    if(EXTI_pin_number >= 0 && EXTI_pin_number <= 4){
        return 6 + EXTI_pin_number;
    }
    else if(EXTI_pin_number >= 5 && EXTI_pin_number <= 9){
        return 23;
    }
    else if(EXTI_pin_number >= 10){
        return 40;
    }
	return -1;
}

/*Steps:
1- Select Appropriate AFIO
2- Select Edge Sense
3- Enable/Disable Mask
4- Enable/Disable NVIC
5- Set CallBack Function

*/
void EXTI_update(EXTI_config_t* config){

    //Step 1
    AFIO->EXTICR[config->pinNo/4] &= ~(0xF << (config->pinNo % 4)*4); //clear the bits that control the corresponding EXTI pin
    AFIO->EXTICR[config->pinNo/4] |= (config->port << (config->pinNo % 4)*4); //Select the port required for EXTI

	GPIO_config_t conf = {config->pinNo,I_FLOATING,0};
    GPIO_init(GET_GPIO_STRUCT(config->port),&conf);
    //Step 2
    switch(config->edgeSense){
        case FALLING_EDGE:
        {
            SET_BIT(EXTI->FTSR,config->pinNo);
            CLR_BIT(EXTI->RTSR,config->pinNo);
        }
        break;
        case RISING_EDGE:
        {
            CLR_BIT(EXTI->FTSR,config->pinNo);
            SET_BIT(EXTI->RTSR,config->pinNo);
        }
        break;
        case BOTH_EDGES:
        {
            SET_BIT(EXTI->FTSR,config->pinNo);
            SET_BIT(EXTI->RTSR,config->pinNo);
        }
        break;
        case RESET_EDGES:
        {
            CLR_BIT(EXTI->FTSR,config->pinNo);
            CLR_BIT(EXTI->RTSR,config->pinNo);
        }
        break;
    }

    //Step 3 & 4
    uint8_t irq = get_NVIC_IRQ(config->pinNo);
    if(config->enable == ENABLE){
        SET_BIT(EXTI->IMR,config->pinNo);
        SET_BIT(NVIC->ISER[irq/32],irq%32);
    }
    else{
        CLR_BIT(EXTI->IMR,config->pinNo);    
        SET_BIT(NVIC->ICER[irq/32],irq%32);    
    }

    //Step 5
    EXTI_callBacks[config->pinNo] = config->callBack;

}

void EXTI_deInit(void){
    EXTI->IMR = 0;
    EXTI->EMR = 0;   
    EXTI -> RTSR = 0; 
    EXTI -> FTSR = 0;  
    EXTI -> SWIER = 0; 
    EXTI -> PR = 0xFFFFFFFF;    
}

void EXTI_init(EXTI_config_t* config){
    EXTI_update(config);
}

EXTI_HANDLER(0)
EXTI_HANDLER(1)
EXTI_HANDLER(2)
EXTI_HANDLER(3)
EXTI_HANDLER(4)

void EXTI9_5_IRQHandler(void){
    CHECK_PR_AND_CALL_ISR(5)
    else CHECK_PR_AND_CALL_ISR(6)
    else CHECK_PR_AND_CALL_ISR(7)
    else CHECK_PR_AND_CALL_ISR(8)
    else CHECK_PR_AND_CALL_ISR(9)
}

void EXTI15_10_IRQHandler(void){
    CHECK_PR_AND_CALL_ISR(10)
    else CHECK_PR_AND_CALL_ISR(11)
    else CHECK_PR_AND_CALL_ISR(12)
    else CHECK_PR_AND_CALL_ISR(13)
    else CHECK_PR_AND_CALL_ISR(14)
    else CHECK_PR_AND_CALL_ISR(15)
}