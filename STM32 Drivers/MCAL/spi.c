#include "spi.h"

uint16_t g_SPI_CR1_config;
uint16_t g_SPI_CR2_config;

void SPI_init(SPI_t* spi ,SPI_config_t* conf){
    uint16_t tmp_SPI_CR1_config = 0x0000;
    uint16_t tmp_SPI_CR2_config = 0x0000;

    //Enable the SPI
    if(spi == SPI1){
        CLK_ENABLE_SPI1();
    }
    else if(spi == SPI2){
        CLK_ENABLE_SPI2();
    }
    tmp_SPI_CR1_config |= SPI_ENABLE;

    //Select Master or Slave
    tmp_SPI_CR1_config |= conf->master_slave_mode;

    //Select Communication Mode
    tmp_SPI_CR1_config |= conf->comm_mode;

    //Select Starting Bit (LSB or MSB)
    tmp_SPI_CR1_config |= conf->frame_format;

    //Select Frame Size
    tmp_SPI_CR1_config |= conf->frame_size;

    //Select Clock Polarity
    tmp_SPI_CR1_config |= conf->clk_polarity;

    //Select Clock Phase
    tmp_SPI_CR1_config |= conf->clk_phase;

    //Select Slave Select Mode

    //SW Mode
    if(conf->slave_select_mode == SPI_SS_SW_MODE_HIGH || conf->slave_select_mode == SPI_SS_SW_MODE_LOW){
        tmp_SPI_CR1_config |= conf->slave_select_mode;
    }
    //HW Mode
    else if(conf->slave_select_mode == SPI_SS_HW_MASTER_OUTPUT_ENABLED){
        tmp_SPI_CR2_config |= conf->slave_select_mode;
    }

    //Select BR PreScaler
    tmp_SPI_CR1_config |= conf->baud_rate_prescaler;

    //Todo: Interrupt Enabling

    //Copy Temp Configurations to physical register
    spi->CR1 = tmp_SPI_CR1_config;
    spi->CR2 = tmp_SPI_CR2_config;                    

}

void SPI_deInit(SPI_t* spi){
    if(spi == SPI1){
        RESET_SPI1();
    }
    else if(spi == SPI2){
        RESET_SPI2();
    }
}

