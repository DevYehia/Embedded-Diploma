/*
 * LCD.c
 *
 * Created: 5/3/2024 4:26:28 PM
 *  Author: Prof. Yehia
 */ 

#include "LCD.h"


static uint8_t count = 0;

void LCD_init(void){
	#ifdef LCD_EIGHT_BIT_MODE
		LCD_DATA_DIR = 0xFF;
		LCD_CTRL_DIR |= (1 << LCD_RS_PIN | 1 << LCD_RW_PIN | 1 << LCD_E_PIN);
		_delay_ms(40);
		LCD_send_command(LCD_FUNCTION_8BIT_2LINES);
		LCD_send_command(LCD_FUNCTION_8BIT_2LINES);		
	#endif
	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_send_command(LCD_CLEAR_SCREEN);
	LCD_send_command(LCD_ENTRY_MODE);
}

void LCD_send_command(uint8_t command){
	LCD_wait_till_free();
	#ifdef LCD_EIGHT_BIT_MODE
		LCD_DATA_PORT = command;
		CLR_BIT(LCD_CTRL_PORT,LCD_RS_PIN);
		CLR_BIT(LCD_CTRL_PORT,LCD_RW_PIN);
		SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
		_delay_ms(2);
		CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	#endif
}

void LCD_wait_till_free(){
	LCD_DATA_DIR = 0;
	CLR_BIT(LCD_CTRL_PORT, LCD_RS_PIN);
	SET_BIT(LCD_CTRL_PORT, LCD_RW_PIN);
	SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	_delay_ms(2);
	CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	//while(GET_BIT(LCD_DATA_PIN,LCD_BF_PIN) == 1);
	LCD_DATA_DIR = 0xFF;
}

void LCD_send_char(uint8_t chr){
	if(count == 16){
		LCD_GOTO_XY(2,0);
	}
	else if(count == 32){
		LCD_send_command(LCD_CLEAR_SCREEN);
		LCD_GOTO_XY(1,0);
		count = 0;
	}
	#ifdef LCD_EIGHT_BIT_MODE
	LCD_DATA_PORT = chr;
	SET_BIT(LCD_CTRL_PORT,LCD_RS_PIN);
	CLR_BIT(LCD_CTRL_PORT,LCD_RW_PIN);
	SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	_delay_ms(2);
	CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	#endif	
    count++;
}

void LCD_send_string(uint8_t* str){
	while(*str != '\0'){
		LCD_send_char(*str);
		str++;
	}
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_send_command(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_send_command(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}