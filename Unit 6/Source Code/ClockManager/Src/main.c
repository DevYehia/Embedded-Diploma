/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Prof. Yehia
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

//Learn-in-depth
//Mastering_Embedded System online diploma
typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//Lab Selector
#define LAB_ONE 1
#define LAB_TWO 2
#define LAB_CHOICE LAB_TWO

//bitwise macros
#define SET_BIT(reg,bit) (reg |= (1 << bit))
#define CLR_BIT(reg,bit) (reg &= ~(1 << bit))


// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE 0x40021000
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR *(volatile uint32_t *)(RCC_BASE)
int main(void)
{
	//By Default SysClk is HSI

	#if LAB_CHOICE == LAB_ONE
	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	100: HCLK divided by 2 <---- Our Choice
	 */

	//APB1 ---> 4 MHz
	SET_BIT(RCC_CFGR,10);
	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	101: HCLK divided by 4 <-- Our Choice
	*/

	//APB2 ---> 2 MHz
	SET_BIT(RCC_CFGR,13);
	SET_BIT(RCC_CFGR,11);
	#elif LAB_CHOICE == LAB_TWO
	/*Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0110: PLL input clock x 8
	*/
	//Set PLL Freq to 32 MHz
	SET_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);

	//enable PLL
	SET_BIT(RCC_CR,24);
	/*Bits 1:0 SW: System clock switch
	10: PLL selected as system clock*/
	SET_BIT(RCC_CFGR,1);


	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	100: HCLK divided by 2
	*/
	//APB1 ---> 16 MHz
	SET_BIT(RCC_CFGR,10);
	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	101: HCLK divided by 4
	*/
	//APB2 ---> 8 MHz
	SET_BIT(RCC_CFGR,13);
	SET_BIT(RCC_CFGR,11);





	#endif
	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
	GPIOA_ODR |= 1<<13 ;
	for (int i = 0; i < 5000; i++); // arbitrary delay
	GPIOA_ODR &= ~(1<<13) ;
	for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
