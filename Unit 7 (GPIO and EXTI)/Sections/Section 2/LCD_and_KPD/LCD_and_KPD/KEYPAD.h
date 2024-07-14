#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include <avr/io.h>
#include "bitwise.h"

#define ROW_SIZE 4
#define COL_SIZE 4

#define ROW_PORT PORTD
#define ROW_DIR  DDRD
#define ROW_PIN  PIND	
#define COL_PORT PORTD	
#define COL_DIR  DDRD	


#define R0 0
#define R1 1
#define R2 2
#define R3 3

#define C0 4
#define C1 5
#define C2 6
#define C3 7



void KEYPAD_init(void);
uint8_t KEYPAD_read(void);

#endif