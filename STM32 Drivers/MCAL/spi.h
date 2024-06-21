#ifndef SPI_H
#define SPI_H

#include "../Device Header/stm32f103x8.h"

//Configuration Struct
typedef struct{
    uint16_t master_slave_mode; //select to be master or slave @ref SPI_MSTR_SLAVE_MODES
    uint16_t comm_mode; //select full-duplex or simplex @ref SPI_COMM_MODES
    uint16_t frame_format; //specifies whether to start with LSB or MSB @ref SPI_FRAME_FORMATS
    uint16_t frame_size;   //8 or 16 bits frame @ref SPI_FRAME_SIZES
    uint16_t clk_polarity; //select idle state of clock @ref SPI_CLK_POLARITIES
    uint16_t clk_phase;    //select whether to start on first edge or second edge from idle state @ref SPI_CLK_PHASES
    uint16_t slave_select_mode; //specifies hardware mode or software mode for slave select @ref SPI_SS_MODES
    uint16_t baud_rate_prescaler; //@ref SPI_BR_PRESCALERS

    uint8_t IRQ_enable;


} SPI_config_t;

#define SPI_ENABLE (1U << 6)

//MSTR_SLAVE_MODES

#define SPI_SLAVE_MODE  0x0000
#define SPI_MASTER_MODE (1U << 2)

//SPI_COMM_MODES
#define SPI_FULL_DUPLEX  0x0000
#define SPI_2_LINES_RX_ONLY (1U << 10)
#define SPI_1_LINE_TX (1U << 14 | 1U << 15)
#define SPI_1_LINE_RX (1U << 15)

//SPI_FRAME_FORMATS
#define SPI_LSB_FIRST (1U << 7)
#define SPI_MSB_FIRST 0x0000

//SPI_FRAME_SIZES
#define SPI_8_BIT_FRAME 0x0000
#define SPI_16_BIT_FRAME (1U << 11)

//SPI_CLK_POLARITIES
#define LOW_LEVEL_IDLE 0x0000
#define HIGH_LEVEL_IDLE (1U << 1)

//SPI_CLK_PHASES
#define SPI_FIRST_EDGE 0x0000
#define SPI_SECOND_EDGE 1U

//SPI_SS_MODES
#define SPI_SS_SW_MODE_HIGH (1U << 9 | 1U << 8)
#define SPI_SS_SW_MODE_LOW (1U << 9)

#define SPI_SS_HW_SLAVE 0x0000
#define SPI_SS_HW_MASTER_OUTPUT_ENABLED (1 << 2)
#define SPI_SS_HW_MASTER_OUTPUT_DISABLED 0x0000

//SPI_BR_PRESCALERS
#define SPI_DIV_BY_2    0x0000
#define SPI_DIV_BY_4    (0b001 << 3)
#define SPI_DIV_BY_8    (0b010 << 3)
#define SPI_DIV_BY_16   (0b011 << 3)
#define SPI_DIV_BY_32   (0b100 << 3)
#define SPI_DIV_BY_64   (0b101 << 3)
#define SPI_DIV_BY_128  (0b110 << 3)
#define SPI_DIV_BY_256  (0b111 << 3)


//Initializes the SPI
//Inputs:
//1) spi: pointer to the SPI being used, Ex: SPI1
//2) conf: pointer to SPI configuration struct 
//Outputs: None
void SPI_init(SPI_t* spi ,SPI_config_t* conf);


//Resets the SPI Registers to reset value
//Inputs:
//1) spi: pointer to the SPI being used, Ex: SPI1
//Outputs: None
void SPI_deInit(SPI_t* spi);






#endif