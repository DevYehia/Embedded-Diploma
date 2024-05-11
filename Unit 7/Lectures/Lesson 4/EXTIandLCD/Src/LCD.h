/*
 * LCD.h
 *
 * Created: 5/3/2024 4:26:38 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "bitwise.h"
#include "gpio.h"

#define LCD_EIGHT_BIT_MODE

#define LCD_DATA_PORT GPIOA
#define LCD_CTRL_PORT GPIOA

#define D0_PIN PIN0

#define D7_PIN PIN7

#define LCD_RS_PIN PIN8
#define LCD_RW_PIN PIN9
#define LCD_E_PIN  PIN10


/* LCD Commands */
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

//APIs
void LCD_init(void);
void LCD_send_command(uint8_t command);
void LCD_send_char(uint8_t chr);
void LCD_send_string(uint8_t* str);
void LCD_wait_till_free(void);
void LCD_GOTO_XY(uint8_t line, uint8_t position);

#endif /* LCD_H_ */
