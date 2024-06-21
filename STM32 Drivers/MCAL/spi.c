#include "spi.h"

void (* SPI1_callback)(SPI_int_src *);
void (* SPI2_callback)(SPI_int_src *);

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

    //Interrupt Enabling
    tmp_SPI_CR2_config |= conf->IRQ_enable;

    //set ISRs
    if(spi == SPI1){
        SPI1_callback = conf->callback;
    }
    else if(spi == SPI2){
        SPI2_callback = conf->callback;;
    }

    //enable NVIC
    if(conf->IRQ_enable != SPI_NO_INT_ENABLE){
        if(spi == SPI1){
            ENABLE_SPI1_IRQ();
        }
        else if(spi == SPI2){
            ENABLE_SPI2_IRQ();
        }        
    }


    //Copy Temp Configurations to physical register
    spi->CR1 = tmp_SPI_CR1_config;
    spi->CR2 = tmp_SPI_CR2_config;                    

}

void SPI_deInit(SPI_t* spi){
    if(spi == SPI1){
        RESET_SPI1();
        DISABLE_SPI1_IRQ();
    }
    else if(spi == SPI2){
        RESET_SPI2();
        DISABLE_SPI2_IRQ();
    }
}

void SPI_send_data(SPI_t* spi, uint16_t data,poll_mode poll_choice){
    if(poll_choice == POLL){
        while(GET_BIT(spi->SR,1) == 0);
        spi->DR = data;
    }
    else if(poll_choice = NO_POLL){
        if(GET_BIT(spi->SR,1) == 1){
            spi->DR = data;            
        }
    }
}

uint16_t SPI_receive_data(SPI_t* spi, poll_mode poll_choice){
    if(poll_choice == POLL){
        while(GET_BIT(spi->SR,0) == 0);
        return spi->DR;
    }
    return spi->DR;           
}

//ISRs
void SPI1_IRQHandler(void){
    SPI_int_src src;
    if(SPI1->SR & 0x2){ //TXE
        src.TXE = 1;
    }
    else if(SPI1->SR & 0x1){ //RXNE
        src.RXNE = 1;
    }
    SPI1_callback(&src);

}

void SPI2_IRQHandler(void){
    SPI_int_src src;
    if(SPI2->SR & 0x2){ //TXE
        src.TXE = 1;
    }
    else if(SPI2->SR & 0x1){ //RXNE
        src.RXNE = 1;
    }
    SPI2_callback(&src);    
}