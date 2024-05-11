/*
 * main.c
 *
 * Created: 5/3/2024 4:25:31 PM
 *  Author: user
 */ 

#include <xc.h>
#include "LCD.h"
int main(void)
{
	char str[] = "Hel";
	LCD_init();
	//LCD_send_string(str);
    while(1)
    {
		LCD_send_string(str);
		_delay_ms(300);
        //TODO:: Please write your application code 
    }
}