/*
 * main.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Yehia
 */


#include "bitwise.h"
#include "types.h"

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_ABP2ENR *((v_uint32 *)(RCC_BASE + 0x18))
#define GPIOA_CRH *((v_uint32 *) (GPIOA_BASE + 0x04))
#define GPIOA_ODR *((v_uint32*) (GPIOA_BASE + 0x0c))

/* bit fields*/

#define RCC_IOPAEN 2
#define GPIOA13 13


typedef union {
    v_uint32 ALL_fields;
    struct{
        v_uint32 reserved :13;
        v_uint32 P_13:1;
    } Pin;

} R_ODR_t;



int main(void){
    SET_BIT(RCC_ABP2ENR,RCC_IOPAEN);
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    CLR_BIT(GPIOA_ODR,GPIOA13);
    while(1){
        TOGGLE_BIT(GPIOA_ODR,GPIOA13);
        int i;
        for(i = 0; i < 500000; i++);
        TOGGLE_BIT(GPIOA_ODR,GPIOA13);
        for(i = 0; i < 500000; i++);
    }
}
