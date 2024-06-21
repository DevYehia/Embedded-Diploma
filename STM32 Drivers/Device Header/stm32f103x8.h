#ifndef STM32F103X8_H
#define STM32F103X8_H

#include <stdint.h>

//-----------------------------
//Base addresses for Memories
#define FLASH_START                          0x08000000UL
#define SYSTEM_MEMORY_START                  0x1FFFF000UL
#define SRAM_START                           0x20000000UL
#define PERIPHRALS_START                     0x40000000UL
#define CORTEX_M_INTERNAL_PERIPHRALS_START   0xE0000000UL
//-----------------------------


//IRQs
#define USART1_IRQ  37
#define USART2_IRQ  38
#define USART3_IRQ  39
#define UART4_IRQ   52
#define UART5_IRQ   53

#define SPI1_IRQ    35
#define SPI2_IRQ    36

//Base Addresses for Cortex-M Periphrals
#define NVIC_BASE  0xE000E100

//-----------------------------
//Base addresses for BUS Peripherals

//AHB Periphrals
#define RCC_BASE   0x40021000UL

//APB1 Periphrals
#define USART2_BASE   0x40004400UL
#define USART3_BASE   0x40004800UL
#define UART4_BASE    0x40004C00UL
#define UART5_BASE    0x40005000UL

#define SPI2_BASE      0x40003800


//APB2 Periphrals



#define USART1_BASE   0x40013800UL
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

#define SPI1_BASE      0x40013000

//End of BUS Periphrals
//---------------------------------

//---------------------------------
//Cortex-M Periphrals Registers

typedef struct{
    volatile uint32_t ISER[8];
    uint8_t RESERVED[96];
    volatile uint32_t ICER[8];    
    volatile uint32_t ISPR[8];    
    uint8_t RESERVED2[96];
    volatile uint32_t ICPR[8];
    volatile uint32_t IABR[8];
    uint8_t RESERVED3[224];
    volatile uint32_t IPRIO[60];        
} NVIC_t;



//---------------------------------

///--------------------------------
//Bus Periphrals Registers

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
    volatile uint32_t EXTICR[4]; //rw
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

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: UART / USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t SR; 
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;      
    volatile uint32_t GTPR;     
} USART_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct 
{
    volatile uint32_t CR1; 
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;      
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;         
} SPI_t;


//End of Bus Periphrals Registers
//---------------------------------

//---------------------------------
//Periphrals Instants

#define NVIC (((NVIC_t *)(NVIC_BASE)))

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

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: USART / UART
//-*-*-*-*-*-*-*-*-*-*-*
#define USART1  ((USART_t *)(USART1_BASE))
#define USART2  ((USART_t *)(USART2_BASE))
#define USART3  ((USART_t *)(USART3_BASE))
#define UART4   ((USART_t *)(UART4_BASE))
#define UART5   ((USART_t *)(UART5_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: SPI
//-*-*-*-*-*-*-*-*-*-*-*
#define SPI1 ((SPI_t *)(SPI1_BASE))
#define SPI2 ((SPI_t *)(SPI2_BASE))


//End of Periphrals Instants
//---------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define ENABLE_AFIO()  (RCC->APB2ENR |= (1 << 0))
#define ENABLE_GPIOA() (RCC->APB2ENR |= (1 << 2))
#define ENABLE_GPIOB() (RCC->APB2ENR |= (1 << 3))
#define ENABLE_GPIOC() (RCC->APB2ENR |= (1 << 4))
#define ENABLE_GPIOD() (RCC->APB2ENR |= (1 << 5))
#define ENABLE_GPIOE() (RCC->APB2ENR |= (1 << 6))
#define ENABLE_USART(usartNo)  if(usartNo == 1) RCC->APB2ENR |= (1 << 14); \
                                else if(usartNo <= 5 && usartNo >= 2) RCC->APB1ENR |= (1 << (usartNo + 15));
#define CLK_ENABLE_SPI1() RCC->APB2ENR |= (1 << 12)
#define CLK_ENABLE_SPI2() RCC->APB1ENR |= (1 << 14)

#define RESET_SPI1() RCC->APB2RSTR |=  (1 << 12); \
                     RCC->APB2RSTR &=  ~(1 << 12)

#define RESET_SPI2() RCC->APB1RSTR |=  (1 << 14); \
                     RCC->APB1RSTR &=  ~(1 << 14) 

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC interrupt Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define ENABLE_SPI1_IRQ()   NVIC->ISER[1] |= (1 <<(SPI1_IRQ - 32))
#define ENABLE_SPI2_IRQ()   NVIC->ISER[1] |= (1 << (SPI2_IRQ - 32))
#define DISABLE_SPI1_IRQ()  NVIC->ICER[1] |= (1 <<(SPI1_IRQ - 32))
#define DISABLE_SPI2_IRQ()  NVIC->ICER[1] |= (1 << (SPI2_IRQ - 32))
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif
