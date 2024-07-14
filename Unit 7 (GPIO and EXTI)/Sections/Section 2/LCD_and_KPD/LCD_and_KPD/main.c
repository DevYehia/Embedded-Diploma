/*
 * main.c
 *
 * Created: 5/3/2024 4:25:31 PM
 *  Author: user
 */ 

#include <xc.h>
#include "LCD.h"
#include "KEYPAD.h"
int main(void)
{
	char str[] = "Hel";
	LCD_init();
	KEYPAD_init();
	//LCD_send_string(str);
    while(1)
    {
		uint8_t c = KEYPAD_read();
		if(c != '?'){
			LCD_send_char(c);	
		}
        //TODO:: Please write your application code 
    }
}