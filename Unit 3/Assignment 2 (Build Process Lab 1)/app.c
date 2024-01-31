#include "uart.h"
#include "types.h"

//should be in .data section
uint8 message[100] = "learn-in-depth:<Yehia>";
//should be in .bss section
uint8 message2[100];
//should be in .rodata section
const uint8 message3[100] = "Read-Only Message!";

void main(void){
    UART_Send_String(message);
}