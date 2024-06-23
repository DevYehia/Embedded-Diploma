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

#include "usart.h"
#include "spi.h"

//#define MASTER_CODE
#define SLAVE_CODE

#define LAB2

void USART_receive_callback(void){
    char ch = UART_receive_data(USART1,NO_POLL);
    GPIO_write_pin(GPIOA, PIN4, LOGIC_LOW); //write ss to low
    SPI_send_data(SPI1,ch,POLL);
    GPIO_write_pin(GPIOA, PIN4, LOGIC_HIGH); //write ss back to idle (high)
}

void SPI_receive_callback(SPI_int_src* src){
    if(src->RXNE){
        char ch = SPI_receive_data(SPI1,NO_POLL);
        UART_send_data(USART1,ch,NO_POLL);
    }
}



int main(void)
{
    /* Loop forever */

    #ifdef LAB1
    //usart configure
	UART_config_t USARTconf;
	USARTconf.sync_mode = SYNC_MODE;
    USARTconf.parity_mode = NO_PARITY;
    USARTconf.char_size = EIGHT_BIT_CHAR;
    USARTconf.num_stop_bits = ONE_STOP;
    USARTconf.baud_rate = 115200;
    USARTconf.enable_sel = ENABLE_RX;
    USARTconf.enable_irq = RXNE_ENABLE;
    UART_init(USART1, &USARTconf);
    UART_set_GPIO(USART1);
    UART_set_callback(USART_receive_callback, USART1);

    //SPI Configure
    SPI_config_t SPIconf;
    SPIconf.clk_phase = SPI_FIRST_EDGE;
    SPIconf.clk_polarity = HIGH_LEVEL_IDLE;
    SPIconf.frame_format = SPI_MSB_FIRST;
    SPIconf.frame_size = SPI_8_BIT_FRAME;
    SPIconf.comm_mode = SPI_FULL_DUPLEX;
    SPIconf.master_slave_mode = SPI_MASTER_MODE;
    SPIconf.slave_select_mode = SPI_SS_SW_MODE_HIGH;
    SPIconf.baud_rate_prescaler = SPI_DIV_BY_8;
    SPIconf.IRQ_enable = SPI_NO_INT_ENABLE;
    SPIconf.callback = 0;
    SPI_init(SPI1,&SPIconf);
    SPI_set_GPIO(SPI1);

    //Set SS Pin A4 to be controlled manually
    GPIO_config_t xGPIOconf;
    xGPIOconf.pinMode = O_PUSH_PULL;
    xGPIOconf.pinSpeed = MAX_10_MHZ;
    xGPIOconf.pinNo = PIN4;
    GPIO_init(GPIOA,&xGPIOconf);
    GPIO_write_pin(GPIOA,PIN4,LOGIC_HIGH);
    #endif


    #ifdef LAB2
    //usart configure
	UART_config_t USARTconf;
	USARTconf.sync_mode = SYNC_MODE;
    USARTconf.parity_mode = NO_PARITY;
    USARTconf.char_size = EIGHT_BIT_CHAR;
    USARTconf.num_stop_bits = ONE_STOP;
    USARTconf.baud_rate = 115200;
    USARTconf.enable_irq = RXNE_ENABLE;
    #ifdef MASTER_CODE
        USARTconf.enable_sel = ENABLE_RX;
    #endif
    #ifdef SLAVE_CODE
        USARTconf.enable_sel = ENABLE_TX;
    #endif
    UART_init(USART1, &USARTconf);
    UART_set_GPIO(USART1);
    UART_set_callback(USART_receive_callback, USART1);

    //SPI Configure
    SPI_config_t SPIconf;
    SPIconf.clk_phase = SPI_FIRST_EDGE;
    SPIconf.clk_polarity = HIGH_LEVEL_IDLE;
    SPIconf.frame_format = SPI_MSB_FIRST;
    SPIconf.frame_size = SPI_8_BIT_FRAME;
    SPIconf.comm_mode = SPI_FULL_DUPLEX;
    SPIconf.baud_rate_prescaler = SPI_DIV_BY_8;

    #ifdef MASTER_CODE
        SPIconf.master_slave_mode = SPI_MASTER_MODE;
        SPIconf.slave_select_mode = SPI_SS_SW_MODE_HIGH;

        SPIconf.IRQ_enable = SPI_NO_INT_ENABLE;
        SPIconf.callback = 0;
    #endif

    #ifdef SLAVE_CODE
        SPIconf.master_slave_mode = SPI_SLAVE_MODE;
        SPIconf.slave_select_mode = SPI_SS_HW_SLAVE;

        SPIconf.IRQ_enable = SPI_RXNE_INT_ENABLE;
        SPIconf.callback = SPI_receive_callback;
    #endif    

    SPI_init(SPI1,&SPIconf);
    SPI_set_GPIO(SPI1);

    //Set SS Pin A4 to be controlled manually
    #ifdef MASTER_CODE
        GPIO_config_t xGPIOconf;
        xGPIOconf.pinMode = O_PUSH_PULL;
        xGPIOconf.pinSpeed = MAX_10_MHZ;
        xGPIOconf.pinNo = PIN4;
        GPIO_init(GPIOA,&xGPIOconf);
        GPIO_write_pin(GPIOA,PIN4,LOGIC_HIGH);
    #endif






    #endif





	for(;;);
}
