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


//bitwise macros
#define SET_BIT(reg,bit) (reg |= (1 << bit))
#define CLR_BIT(reg,bit) (reg &= ~(1 << bit))
#define TGL_BIT(reg,bit) (reg ^= (1 << bit))

#define EXTI_BASE 0x40010400

#define EXTI_IMR  *(volatile unsigned int *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile unsigned int *)(EXTI_BASE + 0x08)
#define EXTI_FTSR *(volatile unsigned int *)(EXTI_BASE + 0x0C)
#define EXTI_PR *(volatile unsigned int *)(EXTI_BASE + 0x14)

#define GPIOA_BASE 0x40010800

#define GPIOA_CRL *(volatile unsigned int *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH *(volatile unsigned int *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile unsigned int *)(GPIOA_BASE + 0x0C)

#define AFIO_BASE 0x40010000

#define AFIO_EXTICR1 *(volatile unsigned int *)(AFIO_BASE + 0x08)

#define RCC_BASE 0x40021000

#define RCC_ABP2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)

#define NVIC_ISER0 *(volatile unsigned int *)(0xE000E100)

void EXTI_init(void){
	SET_BIT(EXTI_RTSR,0); //Enable EXTI-0 Rising Edge Sense
	SET_BIT(EXTI_IMR,0); //Enable EXTI-0 Mask
	SET_BIT(NVIC_ISER0,6); //Enable NVIC Mask for Line 6 --> EXTI-0
}

void AFIO_init(void){
	CLR_BIT(AFIO_EXTICR1,0); //By default it is cleared, but this written for educational purposes
}

void GPIO_init(void){
	//Make Pin-A0 Floating Input
	SET_BIT(GPIOA_CRL,2); //By default it is set, but this written for educational purposes

	//Make Pin-A13 Output
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}

void clock_init(void){
	SET_BIT(RCC_ABP2ENR,0);
	SET_BIT(RCC_ABP2ENR,2);
}
int main(void)
{
	clock_init();
	GPIO_init();
	AFIO_init();
	EXTI_init();
	for(;;);
}

void EXTI0_IRQHandler(void){
	TGL_BIT(GPIOA_ODR,13);
	SET_BIT(EXTI_PR,0); //clear interrupt flag
}
