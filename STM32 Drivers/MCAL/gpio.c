#include "gpio.h"

#define SET_BIT(reg,bit) ((reg) |= (1 << (bit)))
#define CLR_BIT(reg,bit) ((reg) &= ~(1 << (bit)))
#define TGL_BIT(reg,bit) ((reg) ^= (1 << (bit)))
#define GET_BIT(reg,bit) (((reg) >> (bit)) & 1)
#define GET_CR_LSB(pin) (((pin) < 8) ? (pin) * 4 : ((pin) - 8) * 4) //gets the least significant bit for the pin in the config register (CRL or CRH)
#define GET_CR(pin,GPIO) (((pin) < 8) ? &(GPIO->CRL) : &(GPIO->CRH)) //Determines whether to use CRL or CRH 

#define MAX_PIN 15


void GPIO_init(GPIO_t* GPIOx,GPIO_config_t* config){

    if(config->pinNo > MAX_PIN){ //Invalid Pin No.
        return;
    }

    //Enable GPIO Clock
    if(GPIOx == GPIOA){
        ENABLE_GPIOA();
    }
    else if(GPIOx == GPIOB){
        ENABLE_GPIOB();
    } 
    else if(GPIOx == GPIOC){
        ENABLE_GPIOC();
    }    
    else if(GPIOx == GPIOD){
        ENABLE_GPIOD();
    }    
    else if(GPIOx == GPIOE){
        ENABLE_GPIOE();
    }       
    
    volatile uint32_t* CR_reg = GET_CR(config->pinNo,GPIOx);
    for(int i = 0 ; i < 4 ; i++){ //Clear the 4-bits of the pin configuration
        CLR_BIT(*CR_reg, GET_CR_LSB(config->pinNo) + i);
    }
    if(config->pinMode >= O_PUSH_PULL && config -> pinMode <= O_ALT_OPEN_DRAIN){ //pin is output
        *CR_reg |= (config->pinSpeed << GET_CR_LSB(config->pinNo)); //set o/p speed in mode bits 
        *CR_reg |= ((config->pinMode << GET_CR_LSB(config->pinNo)) << 2); //set CNF bits
    }
    
    else if (config->pinMode == I_ANALOG || config -> pinMode == I_FLOATING){
        *CR_reg |= (((config->pinMode - 4) << GET_CR_LSB(config->pinNo)) << 2); //set CNF bits
    }

    else if (config->pinMode == I_PULL_DOWN || config -> pinMode == I_PULL_UP){
        *CR_reg |= ((0b10 << GET_CR_LSB(config->pinNo)) << 2); //set CNF bits
        if(config->pinMode == I_PULL_DOWN){
            CLR_BIT(GPIOx->ODR,config->pinNo);
        }
        else{
            SET_BIT(GPIOx->ODR,config->pinNo);            
        }        
    }    
}

void GPIO_deInit(GPIO_t* GPIOx){
    if(GPIOx == GPIOA){
            SET_BIT(RCC->APB2RSTR,2);
            CLR_BIT(RCC->APB2RSTR,2);
    }
    else if(GPIOx == GPIOB){
            SET_BIT(RCC->APB2RSTR,3);
            CLR_BIT(RCC->APB2RSTR,3);
    }
    else if(GPIOx == GPIOC){
            SET_BIT(RCC->APB2RSTR,4);
            CLR_BIT(RCC->APB2RSTR,4);
    }
    else if(GPIOx == GPIOD){
            SET_BIT(RCC->APB2RSTR,5);
            CLR_BIT(RCC->APB2RSTR,5);
    }
    else if(GPIOx == GPIOE){
            SET_BIT(RCC->APB2RSTR,6);
            CLR_BIT(RCC->APB2RSTR,6);
    }
}

uint8_t GPIO_read_pin(GPIO_t* GPIOx, uint8_t pinNo){
    return GET_BIT(GPIOx->IDR,pinNo);
}

uint16_t GPIO_read_port(GPIO_t* GPIOx){
    return GPIOx->IDR;
}

void GPIO_write_pin(GPIO_t* GPIOx, uint8_t pinNo, uint8_t value){
    if(value == LOGIC_LOW){
        CLR_BIT(GPIOx->ODR,pinNo);
    }
    else if(value == LOGIC_HIGH){
        SET_BIT(GPIOx->ODR,pinNo);
    }
}

void GPIO_write_port(GPIO_t* GPIOx, uint16_t value){
    GPIOx->ODR = value;
}

void GPIO_toggle_pin(GPIO_t* GPIOx, uint8_t pinNo){
    TGL_BIT(GPIOx->ODR,pinNo);
}

void GPIO_lock_pin(GPIO_t* GPIOx, uint8_t pinNo){
    SET_BIT(GPIOx->LCKR,pinNo);
    SET_BIT(GPIOx->LCKR,16);
    CLR_BIT(GPIOx->LCKR,16);
    SET_BIT(GPIOx->LCKR,16);
    GET_BIT(GPIOx->LCKR,16);
}