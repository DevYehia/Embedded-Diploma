#ifndef RCC_H
#define RCC_H

#include "stm32f103x8.h"

#define HSI_CLK_FREQ 8000000UL 


uint32_t RCC_Get_SYSCLK_freq(void);
uint32_t RCC_Get_AHB_freq(void);
uint32_t RCC_Get_APB1_freq(void);
uint32_t RCC_Get_APB2_freq(void);



#endif