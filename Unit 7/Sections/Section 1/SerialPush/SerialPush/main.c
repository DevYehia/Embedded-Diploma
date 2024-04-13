/*
 * main.c
 *
 * Created: 4/13/2024 4:44:33 PM
 *  Author: user
 */ 
#include <util/delay.h>

//bitwise Macros
#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TGL_BIT(reg,bit) (reg ^= (1<<bit))
#define GET_BIT(reg,bit) ((reg >> bit) & 1)

#define DDRD   *(volatile unsigned char *)0x31
#define PORTD  *(volatile unsigned char *)0x32
#define PIND  *(volatile unsigned char *)0x30

#define DDRC   *(volatile unsigned char *)0x34
#define PORTC  *(volatile unsigned char *)0x35
#define PINC  *(volatile unsigned char *)0x33

void setDirection(void){
	CLR_BIT(DDRD,0);
	CLR_BIT(PORTD,0);
	
	for(char i = 5 ; i < 8 ; i++){
		SET_BIT(DDRD,i);
	}
}


int main(void)
{
	char currLED = 5;
	char currIndex = 0;
	setDirection(); //All PortD Pins as output and Pin D0 as Floating input
    while(1)
    {
		if(GET_BIT(PIND,0) == 1){
			_delay_ms(100); //to counter debouncing
			if(GET_BIT(PIND,0) == 1){
				SET_BIT(PORTD,currLED);
				currIndex = (currIndex + 1) % 3;
				currLED = 5 + currIndex;
				while(GET_BIT(PIND,0) == 1);
			}
		}
    }
}