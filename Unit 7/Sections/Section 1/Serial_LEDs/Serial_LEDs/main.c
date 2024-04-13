/*
 * main.c
 *
 * Created: 4/13/2024 3:51:51 PM
 *  Author: user
 */ 
#include <util/delay.h>

//bitwise Macros
#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TGL_BIT(reg,bit) (reg ^= (1<<bit))


#define DDRD   *(volatile unsigned char *)0x31
#define PORTD  *(volatile unsigned char *)0x32

void setDirection(void){
	for(char i = 5 ; i < 8 ; i++){
		SET_BIT(DDRD,i);
	}
}

int main(void)
{
	setDirection(); //configure all Port D pins to be output
    while(1)
    {
        for(unsigned char i = 5 ; i < 8 ; i++){
			SET_BIT(PORTD,i);
			_delay_ms(200);
		}
		
		for(unsigned char i = 7 ; i >= 5 ; i--){
			  CLR_BIT(PORTD,i);
			  _delay_ms(200);
		}
    }
}