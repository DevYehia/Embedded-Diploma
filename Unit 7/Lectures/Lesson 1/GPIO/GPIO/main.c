/*
 * main.c
 *
 * Created: 4/10/2024 11:59:56 PM
 *  Author: Prof Yehia
 */ 

//bitwise Macros
#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TGL_BIT(reg,bit) (reg ^= (1<<bit))


#define DDRD   *(volatile unsigned char *)0x31
#define PORTD  *(volatile unsigned char *)0x32

int x;

void setDirection(void){
	SET_BIT(DDRD,4);
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
}

void delay(void){
	for(unsigned int i = 0 ; i < 60000 ; i++); //Note: int size is 2 bytes
}
int main(void)
{
	x = sizeof(long);
	setDirection();
    while(1)
    {
		SET_BIT(PORTD,5);
		delay();
		CLR_BIT(PORTD,5);

		SET_BIT(PORTD,6);
		delay();
		CLR_BIT(PORTD,6);
		
		SET_BIT(PORTD,7);
		delay();
		CLR_BIT(PORTD,7);
				
		SET_BIT(PORTD,4);
		delay();
		CLR_BIT(PORTD,4);		

    }
}