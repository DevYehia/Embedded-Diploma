#include "types.h"

#ifndef UART_H
#define UART_H


// DEFINES SECTION
#define UART0_DR *((v_uint32 *)0x101f1000)


// FUNCTION PROTOTYPES

/*
Description: This function writes data to the UART_DR register
Input: A String
Output: None
*/
void UART_Send_String(uint8* str);



#endif