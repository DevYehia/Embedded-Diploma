#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include "gpio.h"

#define ROW_SIZE 4
#define COL_SIZE 4

#define ROW_PORT GPIOB
#define COL_PORT GPIOB



#define R0 PIN0
#define R1 PIN1
#define R2 PIN3
#define R3 PIN4

#define C0 PIN8
#define C1 PIN7
#define C2 PIN6
#define C3 PIN5



void KEYPAD_init(void);
uint8_t KEYPAD_read(void);

#endif