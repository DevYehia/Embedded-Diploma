//-----------------------------
//Includes
#include <stdint.h>
//-----------------------------
#ifndef STM32F103X8_H
#define STM32F103X8_H

//-----------------------------
//Base addresses for Memories
#define FLASH_START                          0x08000000UL
#define SYSTEM_MEMORY_START                  0x1FFFF000UL
#define SRAM_START                           0x20000000UL
#define PERIPHRALS_START                     0x40000000UL
#define CORTEX_M_INTERNAL_PERIPHRALS_START   0xE0000000UL
//-----------------------------


//-----------------------------
//Base addresses for BUS Peripherals

//AHB Periphrals
#define RCC_BASE   0x40021000UL

//APB1 Periphrals

//APB2 Periphrals

//GPIO
//A and B are fully included in LQFP48 Package
#define GPIOA_BASE    (PERIPHRALS_START + 0x00010800UL)
#define GPIOB_BASE    (PERIPHRALS_START + 0x00010C00UL)

//C and D are not fully included in LQFP48 Package
#define GPIOC_BASE    (PERIPHRALS_START + 0x00011000UL)
#define GPIOD_BASE    (PERIPHRALS_START + 0x00011400UL)

//E is not included in LQFP48 Package
#define GPIOE_BASE    (PERIPHRALS_START + 0x00011800UL)

#define AFIO_BASE     (PERIPHRALS_START + 0x00010000UL)
#define EXTI_BASE     (PERIPHRALS_START + 0x00010400UL)

//End of BUS Periphrals
//-----------------------------

///--------------------------------
//Start of Periphrals Registers

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t CR;          
    volatile uint32_t CFGR;          
    volatile uint32_t CIR;    
    volatile uint32_t APB2RSTR;          
    volatile uint32_t APB1RSTR;        
    volatile uint32_t AHBENR;          
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;   
    volatile uint32_t CSR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t CFGR2;         
} RCC_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t CRL;          //rw
    volatile uint32_t CRH;          //rw
    volatile const uint32_t IDR;    //r
    volatile uint32_t ODR;          //rw
    volatile uint32_t BSRR;         //rw
    volatile uint32_t BRR;          //rw
    volatile uint32_t LCKR;         //rw
} GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t EVCR;    //rw
    volatile uint32_t MAPR;    //rw
    volatile uint32_t EXTICR1; //rw
    volatile uint32_t EXTICR2; //rw
    volatile uint32_t EXTICR3; //rw
    volatile uint32_t EXTICR4; //rw
    uint32_t RESERVED;
    volatile uint32_t MAPR2;   //rw
} AFIO_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t IMR;   //rw
    volatile uint32_t EMR;   //rw
    volatile uint32_t RTSR;  //rw
    volatile uint32_t FTSR;  //rw
    volatile uint32_t SWIER; //rw
    volatile uint32_t PR;    //w1c
} EXTI_t;

//End of Periphrals Registers
//---------------------------------

//---------------------------------
//Start of Periphrals Instants

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: RCC
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC ((RCC_t *)(RCC_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA ((GPIO_t *)(GPIOA_BASE))
#define GPIOB ((GPIO_t *)(GPIOB_BASE))
#define GPIOC ((GPIO_t *)(GPIOC_BASE))
#define GPIOD ((GPIO_t *)(GPIOD_BASE))
#define GPIOE ((GPIO_t *)(GPIOE_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO ((AFIO_t *)(AFIO_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI ((EXTI_t *)(EXTI_BASE))

//End of Periphrals Instants
//---------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define  ENABLE_AFIO()  (RCC->APB2ENR |= (1 << 0))
#define  ENABLE_GPIOA() (RCC->APB2ENR |= (1 << 2))
#define  ENABLE_GPIOB() (RCC->APB2ENR |= (1 << 3))
#define  ENABLE_GPIOC() (RCC->APB2ENR |= (1 << 4))
#define  ENABLE_GPIOD() (RCC->APB2ENR |= (1 << 5))
#define  ENABLE_GPIOE() (RCC->APB2ENR |= (1 << 6))
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif