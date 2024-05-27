/*
 * uart.c
 *
 * Created: 5/27/2024 7:54:10 PM
 *  Author: user
 */ 

#include "uart.h"

static uint8_t is_char_size_nine = 0;

void UART_init(UART_config_t* config){

    //select synchronization mode
	SET_BIT(UCSRC,7); //Set this bit to access UCSRC
	
	if(config->sync_mode == ASYNC_MODE){
		CLR_BIT(UCSRC, 6);	
	}
	else if(config->sync_mode == SYNC_MODE){
		SET_BIT(UCSRC, 6);	
	}
    //set up frame properties
	
	//Parity
	CLR_BIT(UCSRC,5);
	CLR_BIT(UCSRC,4);
	UCSRC |= ((config->parity_mode) << 4);	
	
	//Stop bits
	if(config->num_stop_bits == ONE_STOP){
		CLR_BIT(UCSRC,3);
	}
	else if(config->num_stop_bits == TWO_STOP){
		SET_BIT(UCSRC,3);
	}	
	
	//Character Size
	CLR_BIT(UCSRC,2);
	CLR_BIT(UCSRC,1);	
	if(config->char_size <= 8 && config->char_size >= 5){
		UCSRC |= (((config->char_size) - 5) << 1);
	}
	else if(config->char_size == 9){
		is_char_size_nine = 1;
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);		
		SET_BIT(UCSRB,2);
	}
	else{ // wrong configuration revert to reset value
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);		
	}
	
	
	//select Baud Rate
	
	//initially USART operates on normal speed not double speed
	//uint32_t denom = 16 * (config->baud_rate);


	//uint16_t ubrr_value = F_CPU / denom - 1;
	uint16_t ubrr_value = F_CPU / (16 * (uint32_t)(config->baud_rate)) - 1;
	UBRRL = (uint8_t)(ubrr_value & 0xFF);
	CLR_BIT(UCSRC,7); //clear this bit to access UBRRH
	UBRRH = (uint8_t)(ubrr_value & 0xF00);
	
	//Enable the Peripheral	
	SET_BIT(UCSRB,3); //enable TX
	SET_BIT(UCSRB,4); //enable RX
	
}

void UART_send(uint16_t data){
	while(GET_BIT(UCSRA,5) == 0); //wait till buffer is empty
	if(is_char_size_nine){
		if((data & (1 << 8)) == 1){
			SET_BIT(UCSRB, 0);
		}
		else{
			CLR_BIT(UCSRB, 0);
		}
	}
	UDR = (uint8_t)data;
	
	
}

uint16_t UART_receive(void){
	while(GET_BIT(UCSRA,7) == 0); //wait till buffer is full
	uint8_t ninth_bit = GET_BIT(UCSRB,1);
	return (ninth_bit << 8) | UDR;
}

void UART_send_string(uint8_t* str){
	while(*str != '\0'){
		UART_send(*str);
		str++;
	}
	
}