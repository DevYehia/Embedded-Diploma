#ifndef USART_H
#define USART_H

#include "../Device Header/stm32f103x8.h"
#include "rcc.h"
#include "gpio.h"
#include "../UTIL/bitwise.h"
typedef struct{
	uint32_t baud_rate;
	uint8_t  sync_mode;     //takes values from UART_SYNC_MODES
	uint8_t  parity_mode;   //takes values from UART_PARITY_MODES
	uint8_t  num_stop_bits; //takes values from UART_STOP_BITS_NUMBER
	uint8_t  char_size;     //takes values from UART_CHAR_LENGTH
	uint8_t  enable_sel;     //takes values from UART_ENABLE_MODES
	uint8_t  enable_irq;     //takes values from UART_INTERRUPT_ENABLE_MODES
} UART_config_t;


//UART_SYNC_MODES
#define ASYNC_MODE 0
#define SYNC_MODE  1


//UART_PARITY_MODES
#define NO_PARITY   0
#define EVEN_PARITY 2
#define ODD_PARITY  3

//UART_STOP_BITS_NUMBER
#define ONE_STOP            0
#define HALF_STOP           1
#define TWO_STOP            2
#define ONE_AND_HALF_STOP   3

//UART_ENABLE_MODES
#define ENABLE_TX     0
#define ENABLE_RX     1
#define ENABLE_RX_TX  2
#define DISABLE_TX    3
#define DISABLE_RX    4
#define DISABLE_RX_TX 5

//UART_CHAR_LENGTH
#define EIGHT_BIT_CHAR 0
#define NINE_BIT_CHAR 1

//UART_INTERRUPT_ENABLE_MODES
#define TXE_ENABLE     (1 << 7) //Transmit Data Register Empty
#define TC_ENABLE      (1 << 6) //Transmission Complete
#define RXNE_ENABLE    (1 << 5) //Recieve Data Register Not Empty
#define TXE_DISABLE   ~(1 << 7) //Transmit Data Register Empty
#define TC_DISABLE    ~(1 << 6) //Transmission Complete
#define RXNE_DISABLE  ~(1 << 5) //Recieve Data Register Not Empty

//POLL_MODES
#define USART_NO_POLL 0
#define USART_POLL 1


//Baud Rate Calculations
#define USARTDIV(fclk,baudRate) ((fclk)/(16 * (baudRate)))
#define USARTDIV_MUL100(fclk,baudRate) (25 * (fclk)/(4 * (baudRate)))
#define INTEGER_PART_MUL100(fclk,baudRate) (USARTDIV(fclk,baudRate) * 100)
#define INTEGER_PART(fclk,baudRate) (USARTDIV(fclk,baudRate))
#define FRACTIONAL_PART(fclk,baudRate) ((((USARTDIV_MUL100(fclk,baudRate)-INTEGER_PART_MUL100(fclk,baudRate)) * 16) + 50) / 100)
//Example
//Fclk = 36Mhz, baudRate = 115200
//Actual USARTDIV = 19.53
//USARTDIV = 36000000/(16*115200) = 19 (Same as Integer Part)
//USARTDIV_MUL100 = 36000000/(16*115200) = 1953
//FRACTIONAL_PART = (((1953-19*100)*16) + 50)/100 = 8





void UART_init(USART_t* usart ,UART_config_t* config);
void UART_set_GPIO(USART_t* usart);
void UART_send_data(USART_t* usart, uint16_t data, uint8_t poll);
uint16_t UART_receive_data(USART_t* usart, uint8_t poll);
void UART_set_callback(void (*func) (void),USART_t* usart);
#endif