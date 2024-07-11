#include "i2c.h"

I2C_config_t g_I2C1_config;
I2C_config_t g_I2C2_config;

void I2C_init(I2C_t* i2c, I2C_config_t* conf){

    //Clock Enable
    if(i2c == I2C1){
        CLK_ENABLE_I2C1();
        g_I2C1_config = *conf;
    }
    else if(i2c == I2C2){
        CLK_ENABLE_I2C2();
        g_I2C2_config = *conf;
    }

    //Disable the Periphral (Neccessary For Clock Cofiguration)
    i2c->CR1 &= ~(I2C_ENABLE);

    //CR2 Configuration
    uint16_t temp_CR2 = 0x0000;

    //enable selected interrupts and disable unselected interrupts
    temp_CR2 |= (conf->irq_enable);
    
    //ALso, Enable TXE and RXNE to generate EV Interrupt
    if(conf->irq_enable & I2C_EV_INT_ENABLE){
        temp_CR2 |= I2C_TXE_RXNE_INT_ENABLE;
    }

    //NVIC interrupt enable
    if(i2c == I2C1){
        if(conf->irq_enable & I2C_EV_INT_ENABLE){
            NVIC_ENABLE_I2C1_EV_IRQ();
        }
        if(conf->irq_enable & I2C_ERR_INT_ENABLE){
            NVIC_ENABLE_I2C1_ER_IRQ();       
        }
    }
    else if(i2c == I2C2){
        if(conf->irq_enable & I2C_EV_INT_ENABLE){
            NVIC_ENABLE_I2C2_EV_IRQ();
        }
        if(conf->irq_enable & I2C_ERR_INT_ENABLE){
            NVIC_ENABLE_I2C2_ER_IRQ();       
        }        
    }

    //get APB1 clock 
    uint32_t APB1_clk = RCC_Get_APB1_freq();

    //set FREQ bits with APB1 Bus
    uint8_t FREQ_value = APB1_clk / 1000000UL;
    temp_CR2 |= FREQ_value;

    i2c->CR2 = temp_CR2;

    //End of CR2 Configuration

    //CCR Configuration

    //T(desired) / 2 = CCR * T(APB1_clk)
    //f(desired) = f(APB1_clk) / (2 * CCR)
    //CCR = f(APB1_clk) / (2 * f(desired))

    uint16_t temp_CCR = 0x0000;

    //Standard Mode
    if(conf->clk_speed == I2C_CLOCK_SM_50_KHZ || conf->clk_speed == I2C_CLOCK_SM_100_KHZ){
        temp_CCR |= (APB1_clk / ((conf->clk_speed) << 1));
    }
    else{
        //fast mode not supported yet
    }

    i2c->CCR = temp_CCR;

    //End of CCR Configuration

    //TRISE Configuration
    i2c->TRISE = FREQ_value + 1;


    //user wants to modify slave address info
    if(conf->slave_addr_info != 0){

        //OAR1 Configuration
        uint16_t temp_OAR1 = 0x0000;

        //bit 14 should always be kept at 1
        temp_OAR1 |= (1 << 14);

        temp_OAR1 |= (conf->slave_addr_info->addr_size);

        if(conf->slave_addr_info->addr_size == I2C_ADDR_7_BITS){
            temp_OAR1 |= (conf->slave_addr_info->primary_slave_addr << 1);
        }
        else{
            temp_OAR1 |= (conf->slave_addr_info->primary_slave_addr);
        }

        i2c->OAR1 = temp_OAR1;


        //OAR2 Configuration
        uint16_t temp_OAR2 = 0x0000;

        temp_OAR2 |= (conf->slave_addr_info->dual_addr_enable);

        if(conf->slave_addr_info->dual_addr_enable != I2C_DUAL_ADDR_DISABLE){
            temp_OAR2 |= (conf->slave_addr_info->secondary_slave_addr << 1);
        }

        i2c->OAR2 = temp_OAR2;
    }

    //CR1 Configuration

    uint16_t temp_CR1 = 0x0000;


    //Enable I2C 
    temp_CR1 |= I2C_ENABLE;    

    //Enable / Disable Acks
    temp_CR1 |= (conf -> ack_enable);

    //Enable / Disable Clock Stretching
    temp_CR1 |= (conf -> clk_stretch_enable);    

    //Enable / Disable General Call
    temp_CR1 |= (conf -> general_call_detection_enable);

    i2c->CR1 = temp_CR1;


}

void I2C_deInit(I2C_t* i2c){
    if(i2c == I2C1){
        RESET_I2C1();
        NVIC_DISABLE_I2C1_ER_IRQ();
        NVIC_DISABLE_I2C1_EV_IRQ();
    }
    else if(i2c == I2C2){
        RESET_I2C2();
        NVIC_DISABLE_I2C2_ER_IRQ();
        NVIC_DISABLE_I2C2_EV_IRQ();
    }   
}


void I2C_set_GPIO(I2C_t* i2c){
    if(i2c == I2C1){ 
        //SCL: B6
        //SDA: B7
        GPIO_config_t conf;

        //SCL Config
        conf.pinNo = PIN6;
        conf.pinMode = O_ALT_OPEN_DRAIN;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOB,&conf);

        //SDA Config
        conf.pinNo = PIN7;
        conf.pinMode = O_ALT_OPEN_DRAIN;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOB,&conf);
    }
    else if(i2c == I2C2){
        //SCL: B10
        //SDA: B11
        GPIO_config_t conf;

        //SCL Config
        conf.pinNo = PIN10;
        conf.pinMode = O_ALT_OPEN_DRAIN;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOB,&conf);

        //SDA Config
        conf.pinNo = PIN11;
        conf.pinMode = O_ALT_OPEN_DRAIN;
        conf.pinSpeed = MAX_10_MHZ;
        GPIO_init(GPIOB,&conf);

    }
}

I2C_flag_status_t I2C_check_flag(I2C_t* i2c, I2C_flag_type_t flagType){
    switch(flagType){
        case I2C_BUSY:
        {
            return GET_BIT(i2c->SR2,1);
        }
        break;
        case I2C_START_DONE:
        {
            return GET_BIT(i2c->SR1, 0);
        }
        break;
        case I2C_ADDR_ACKED:
        {
            return GET_BIT(i2c->SR1, 1);
        }
        break;
        case I2C_DR_EMPTY:
        {
            return GET_BIT(i2c->SR1, 7);            
        }
        break;
        case I2C_BYTE_SENT:
        {
            return GET_BIT(i2c->SR1, 2);            
        }
        break;
        case I2C_RECV_NOT_EMPTY:
        {
            return GET_BIT(i2c->SR1, 6);            
        }
        break;                        
    }
}

void I2C_send_address(I2C_t* i2c,uint16_t slaveAddr, I2C_rw_t rwChoice){
    if(i2c == I2C1){
        if(g_I2C1_config.slave_addr_info->addr_size == I2C_ADDR_7_BITS){
            slaveAddr = (slaveAddr << 1) | rwChoice;
            i2c->DR = slaveAddr;
        }
        else{
            //Not Supported
        }
    }
    else{
        if(g_I2C2_config.slave_addr_info->addr_size == I2C_ADDR_7_BITS){
            slaveAddr = (slaveAddr << 1) | rwChoice;
            i2c->DR = slaveAddr;
        }
        else{
            //Not Supported
        }
    }
}

void I2C_master_send(I2C_t* i2c, uint16_t slaveAddr, uint8_t* dataToSend, uint16_t dataLen, I2C_stop_choice_t stopChoice, I2C_start_choice_t startChoice){

    uint16_t dummyRead;
    if(startChoice == NORMAL_START){ //wait till bus is idle
        while(GET_BIT(i2c->SR2,1) == 1);
    }

    //Generate Start Condition
    SET_BIT(i2c->CR1,8);

    //Wait till Start Condition Generated
    while(I2C_check_flag(i2c, I2C_START_DONE) == RESET);

    //Clear SB Flag: cleared by reading SR1 register followed by writing DR register with Address.
    //No Need since check_flag reads SR1

    I2C_send_address(i2c, slaveAddr, I2C_WRITE);

    //Wait till address ACKed
    //todo: handle NACK
    while(I2C_check_flag(i2c, I2C_ADDR_ACKED) == RESET);

    //clear ADDR Flag
    //cleared by reading SR1 register followed by reading SR2.
    //No need to read SR1 since check_flag reads it
    dummyRead = i2c->SR2;

    //Send the data
    for(int i = 0 ; i < dataLen ; i++){
        i2c->DR = dataToSend[i];
        //wait till DR Empty
        while(I2C_check_flag(i2c, I2C_DR_EMPTY) == RESET);
    }

    if(stopChoice == STOP){
        SET_BIT(i2c->CR1, 9);
    }    

}

void I2C_master_recv(I2C_t* i2c, uint16_t slaveAddr, uint8_t* dataRecvBuffer, uint16_t dataLen, I2C_stop_choice_t stopChoice, I2C_start_choice_t startChoice){

    uint16_t dummyRead;

    if(startChoice == NORMAL_START){ //wait till bus is idle
        while(GET_BIT(i2c->SR2,1) == 1);
    }

    //Generate Start Condition
    SET_BIT(i2c->CR1,8);

    //Wait till Start Condition Generated
    while(I2C_check_flag(i2c, I2C_START_DONE) == RESET);

    //Clear SB Flag: cleared by reading SR1 register followed by writing DR register with Address.
    //No Need since check_flag reads SR1

    I2C_send_address(i2c, slaveAddr, I2C_READ);

    //Wait till address ACKed
    //todo: handle NACK
    while(I2C_check_flag(i2c, I2C_ADDR_ACKED) == RESET);

    //clear ADDR Flag
    //cleared by reading SR1 register followed by reading SR2.
    //No need to read SR1 since check_flag reads it
    dummyRead = i2c->SR2;

    //Receive the data
    int i = 0;
    for( ; i < dataLen - 1 ; i++){
        //wait till there is data to read
        while(I2C_check_flag(i2c, I2C_RECV_NOT_EMPTY) == RESET);

        dataRecvBuffer[i] = i2c->DR;
    }

    //For last data byte disable ACK to send NACK
    //Also Prepare the Stop generation
    CLR_BIT(i2c->CR1, 10);
    if(stopChoice == STOP){
        SET_BIT(i2c->CR1, 9);
    }        
    //wait till there is data to read
    while(I2C_check_flag(i2c, I2C_RECV_NOT_EMPTY) == RESET);
    dataRecvBuffer[i] = i2c->DR;

    //return ACK to be enabled
    SET_BIT(i2c->CR1, 10);    
}