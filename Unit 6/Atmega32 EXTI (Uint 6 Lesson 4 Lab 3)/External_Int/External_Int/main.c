/*
 * main.c
 *
 * Created: 3/25/2024 4:22:26 PM
 *  Author: user
 */ 

//#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//Vectors 2 --> 4 : EXTI-0 --> EXTI-2

//bitwise Macros
#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TGL_BIT(reg,bit) (reg ^= (1<<bit))

//reset value = 0x00
#define MCUCR *(volatile unsigned char *)0x55
/* Bits 3-2
0 0 The low level of INT1 generates an interrupt request.
0 1 Any logical change on INT1 generates an interrupt request.
1 0 The falling edge of INT1 generates an interrupt request.
1 1 The rising edge of INT1 generates an interrupt request. <--- Our Choice
*/
/* Bits 1-0
0 0 The low level of INT0 generates an interrupt request.
0 1 Any logical change on INT0 generates an interrupt request. <--- Our Choice
1 0 The falling edge of INT0 generates an interrupt request.
1 1 The rising edge of INT0 generates an interrupt request.
*/
#define MCUCSR *(volatile unsigned char *)0x54
#define GICR   *(volatile unsigned char *)0x5B
#define SREG   *(volatile unsigned char *)0x5F
#define DDRD   *(volatile unsigned char *)0x31
#define DDRB   *(volatile unsigned char *)0x37
#define PORTD  *(volatile unsigned char *)0x32

void EXTI_init(){
	SET_BIT(MCUCR,2); SET_BIT(MCUCR,3); //Rising Edge sense on INT1
	SET_BIT(MCUCR,0); //both edges sense on INT0
	CLR_BIT(MCUCSR,6); //Falling Edge sense on INT2
	//It is by default zero, but this line is written for educational purposes
	
	//enable mask in GIC
	SET_BIT(GICR,7);
	SET_BIT(GICR,6);
	SET_BIT(GICR,5);
	
	//enable global interrupts
	SET_BIT(SREG,7);
}

void DIO_init(void){
	
	//set all EXTI pins as input
	CLR_BIT(DDRD,2); //INT-0
	CLR_BIT(DDRD,3); //INT-1
	CLR_BIT(DDRB,2); //INT-2
	
	//set LED pins as output
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
}

int main(void)
{
	DIO_init();
	EXTI_init();
    while(1)
    {
       
    }
}

ISR(INT0_vect){
	SET_BIT(PORTD,5);
	_delay_ms(1000);
	CLR_BIT(PORTD,5);
}

ISR(INT1_vect){
	SET_BIT(PORTD,6);
	_delay_ms(1000);
	CLR_BIT(PORTD,6);
}

ISR(INT2_vect){
	SET_BIT(PORTD,7);
	_delay_ms(1000);
	CLR_BIT(PORTD,7);
}