#include "usart.h"

#define getUsartNo(usart)    usart == USART1 ? 1 : \
							 usart == USART2 ? 2 : \
							 usart == USART3 ? 3 : -1

#define getUsartIRQ(usart)   usart == USART1 ? USART1_IRQ : \
							 usart == USART2 ? USART2_IRQ : \
							 usart == USART3 ? USART3_IRQ : -1

void (*USART_callbacks[3]) (void);
static uint8_t payload_length = -1;
static uint8_t isParityEnabled = 0;

void UART_init(USART_t* usart ,UART_config_t* config){


	uint8_t usart_no = getUsartNo(usart);
	ENABLE_USART(usart_no);


	//enable the UART
	SET_BIT(usart->CR1,13);


	//set character size
	payload_length = config->char_size;
	if(config->char_size == EIGHT_BIT_CHAR){
		CLR_BIT(usart->CR1,12);
	}
	else if(config->char_size == NINE_BIT_CHAR){
		SET_BIT(usart->CR1,12);		
	}

	//set stop bits number
	CLR_BIT(usart->CR2,12);
	CLR_BIT(usart->CR2,13);
	(usart->CR2) |= (config->num_stop_bits);

    //set parity
    if(config->parity_mode != NO_PARITY){
    	isParityEnabled = 1;
    }
    else{
    	isParityEnabled = 0;
    }
	CLR_BIT(usart->CR1,10);
	CLR_BIT(usart->CR1,9);

	(usart->CR1) |= ((config->parity_mode) << 9);

	//select baud rate
	uint16_t int_part;
	uint8_t  fraction_part;
	if(usart == USART1){
		uint32_t APB2_freq = RCC_Get_APB2_freq();
		int_part = INTEGER_PART(APB2_freq,config->baud_rate);
		fraction_part = FRACTIONAL_PART(APB2_freq,config->baud_rate);
	}
	else{
		uint32_t APB1_freq = RCC_Get_APB1_freq();
		int_part = INTEGER_PART(APB1_freq,config->baud_rate);
		fraction_part = FRACTIONAL_PART(APB1_freq,config->baud_rate);
	}

	if(fraction_part == 0x10){ //overflow of fractional part
		int_part++;
	}
	usart->BRR = 0; //clear before modification
	usart->BRR = (int_part << 4) | (fraction_part & 0xF);

    //enable/disable selected TX and RX
	switch(config->enable_sel){
		case ENABLE_TX:
		{
			SET_BIT(usart->CR1, 3);
		} 
		break;
		case ENABLE_RX:
		{
			SET_BIT(usart->CR1, 2);
		} 
		break;
		case ENABLE_RX_TX:
		{
			SET_BIT(usart->CR1, 2);
			SET_BIT(usart->CR1, 3);
		} 
		break;
		case DISABLE_TX:
		{
			CLR_BIT(usart->CR1, 3);
		} 
		break;
		case DISABLE_RX:
		{
			CLR_BIT(usart->CR1, 2);
		} 
		break;
		case DISABLE_RX_TX:
		{
			CLR_BIT(usart->CR1, 2);
			CLR_BIT(usart->CR1, 3);
		} 
		break;		
	}

    //Enable/Disable selected interrupt
    uint8_t irq = getUsartIRQ(usart);
	if(config->enable_irq <= TXE_ENABLE && config->enable_irq >= RXNE_ENABLE){
		(usart->CR1) |= (config->enable_irq);
		SET_BIT(NVIC->ISER[irq / 32],irq % 32);
	}
	else if(config->enable_irq <= RXNE_DISABLE && config->enable_irq >= TXE_DISABLE){
		(usart->CR1) &= (config->enable_irq);
		SET_BIT(NVIC->ICER[irq / 32],irq % 32);
	}

}

void UART_set_GPIO(USART_t* usart){
    GPIO_config_t conf;
    if(usart == USART1){
        //TX on Pin B6
        conf.pinNo = PIN6; 
        conf.pinMode = O_ALT_PUSH_PULL;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOB, &conf);

        //RX on B7
        conf.pinNo = PIN7; 
        conf.pinMode = I_FLOATING;
        GPIO_init(GPIOB, &conf);
    }
    else if(usart == USART2){
        //TX on Pin D5
        conf.pinNo = PIN5; 
        conf.pinMode = O_ALT_PUSH_PULL;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOD, &conf);

        //RX on D6
        conf.pinNo = PIN6; 
        conf.pinMode = I_FLOATING;
        GPIO_init(GPIOD, &conf);        
    }
    else if(usart == USART3){
        //TX on Pin C10
        conf.pinNo = PIN10; 
        conf.pinMode = O_ALT_PUSH_PULL;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOC, &conf);

        //RX on C11
        conf.pinNo = PIN11; 
        conf.pinMode = I_FLOATING;
        GPIO_init(GPIOC, &conf);        
    }

}

void UART_set_callback(void (*func)(void),USART_t* usart){
    uint8_t usartNo = getUsartNo(usart);
	USART_callbacks[usartNo-1] = func;
}



void UART_send_data(USART_t* usart, uint16_t data, uint8_t poll){
	if(poll != USART_NO_POLL){
		while(GET_BIT(usart->SR,7) == 0);
	}
	usart->DR = data;
}
uint16_t UART_receive_data(USART_t* usart, uint8_t poll){
	if(poll != USART_NO_POLL){
		while(GET_BIT(usart->SR,5) == 0);
	}	
	if(isParityEnabled){
		if(payload_length == EIGHT_BIT_CHAR){
			return (usart->DR) & 0x7F;
		}
		else if(payload_length == NINE_BIT_CHAR){
			return (usart->DR) & 0xFF;		
		}
		else{
			return -1;
		}
	}
	else{
		return usart->DR;
	}


}




void USART1_IRQHandler(){ 
	USART_callbacks[0]();
}  

void USART2_IRQHandler(){ 
	USART_callbacks[1]();
}  

void USART3_IRQHandler(){ 
	USART_callbacks[2]();
}  
