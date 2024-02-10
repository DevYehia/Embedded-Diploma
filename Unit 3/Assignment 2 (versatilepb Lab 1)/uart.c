#include "uart.h"

void UART_Send_String(uint8* str){
    while(*str != '\0'){
        UART0_DR = *str;
        str++;
    }
}