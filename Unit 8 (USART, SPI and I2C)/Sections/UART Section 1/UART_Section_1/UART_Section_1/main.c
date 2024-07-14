/*
 * UART_Section_1.c
 *
 * Created: 5/27/2024 7:51:50 PM
 * Author : user
 */ 

#include <avr/io.h>
#include "uart.h"

int main(void)
{
	UART_config_t conf = {ASYNC_MODE, NO_PARITY, ONE_STOP, 8, 9600};
	UART_init(&conf);
	
	UART_send_string("ABCDEFG");
    /* Replace with your application code */
    while (1) 
    {
    }
}

