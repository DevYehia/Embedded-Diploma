/*
 * LCD.c
 *
 * Created: 5/3/2024 4:26:28 PM
 *  Author: Prof. Yehia
 */ 

#include "LCD.h"


static uint8_t count = 0;


static void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_init(void){
	ENABLE_GPIOA();
	#ifdef LCD_EIGHT_BIT_MODE
		GPIO_config_t conf;
        //OUTPUT CONFIGURATIONS
        conf.pinMode = O_PUSH_PULL;
        conf.pinSpeed = MAX_2_MHZ;
		//DATA PORT OUTPUT
        for(uint8_t i = D0_PIN ; i <= D7_PIN ; i++){
            conf.pinNo = i;
            GPIO_init(LCD_DATA_PORT, &conf);
        }
        //CONTROL PORT OUTPUT
        conf.pinNo = LCD_RS_PIN;
        GPIO_init(LCD_CTRL_PORT, &conf);

        conf.pinNo = LCD_RW_PIN;
        GPIO_init(LCD_CTRL_PORT, &conf);

        conf.pinNo = LCD_E_PIN;
        GPIO_init(LCD_CTRL_PORT, &conf);

		delay_ms(40);
		LCD_send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_send_command(LCD_CLEAR_SCREEN);
	LCD_send_command(LCD_ENTRY_MODE);

}

void LCD_send_command(uint8_t command){
	LCD_wait_till_free();
	#ifdef LCD_EIGHT_BIT_MODE
        GPIO_write_port(LCD_DATA_PORT,command);
        GPIO_write_pin(LCD_CTRL_PORT,LCD_RS_PIN,LOGIC_LOW);
        GPIO_write_pin(LCD_CTRL_PORT,LCD_RW_PIN,LOGIC_LOW);
        GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_HIGH);
		delay_ms(2);
        GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_LOW);
	#endif
}

void LCD_wait_till_free(){
	//LCD_DATA_DIR = 0;
    //INPUT CONFIGURATION
	GPIO_config_t conf;
    conf.pinMode = I_FLOATING;
    conf.pinSpeed = MAX_2_MHZ;
	//DATA PORT INPUT
    for(uint8_t i = D0_PIN ; i <= D7_PIN ; i++){
         conf.pinNo = i;
        GPIO_init(LCD_DATA_PORT, &conf);
    }
    GPIO_write_pin(LCD_CTRL_PORT,LCD_RS_PIN,LOGIC_LOW);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_RW_PIN,LOGIC_HIGH);
	delay_ms(1);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_HIGH);
	delay_ms(2);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_LOW);
	//while(GET_BIT(LCD_DATA_PIN,LCD_BF_PIN) == 1);
    //OUTPUT CONFIGURATIONS
    conf.pinMode = O_PUSH_PULL;
    conf.pinSpeed = MAX_2_MHZ;
	//DATA PORT OUTPUT
    for(uint8_t i = D0_PIN ; i <= D7_PIN ; i++){
        conf.pinNo = i;

        GPIO_init(LCD_DATA_PORT, &conf);
    }
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
    GPIO_write_port(LCD_DATA_PORT,chr);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_RS_PIN,LOGIC_HIGH);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_RW_PIN,LOGIC_LOW);
	delay_ms(1);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_HIGH);
	delay_ms(2);
    GPIO_write_pin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_LOW);
	#endif	
    count++;
}

void LCD_send_string(uint8_t* str){
	while(*str != '\0'){
		LCD_send_char(*str);
        str++;
	}
}

void LCD_GOTO_XY(uint8_t line, uint8_t position){
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
