/*
 * uart.h
 *
 * Created: 5/27/2024 7:54:23 PM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_


#define F_CPU 8000000UL
#include "bitwise.h"
#include <avr/io.h>


typedef struct{
	uint8_t sync_mode; //takes values from UART_SYNC_MODES
	uint8_t parity_mode; //takes values from UART_PARITY_MODES
	uint8_t  num_stop_bits; //takes values from UART_STOP_BITS_NUMBER
	uint8_t  char_size; //must be between 5 or 9 else it will default to 8
	uint16_t baud_rate;
	} UART_config_t;


//UART_SYNC_MODES
#define ASYNC_MODE 0
#define SYNC_MODE  1


//UART_PARITY_MODES
#define NO_PARITY   0
#define EVEN_PARITY 2
#define ODD_PARITY  3

//UART_STOP_BITS_NUMBER
#define ONE_STOP    0
#define TWO_STOP    1

void UART_init(UART_config_t* config);
void UART_send(uint16_t data);
uint16_t UART_receive(void);
void UART_send_string(uint8_t* str);


#endif /* UART_H_ */