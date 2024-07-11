#include "E2PROM.h"


void E2PROM_init(void){
    I2C_config_t conf;
    conf.ack_enable = I2C_ACK_ENABLE;
    conf.clk_speed = I2C_CLOCK_SM_100_KHZ;
    conf.clk_stretch_enable = I2C_STRETCHING_CLK_ENABLE;
    conf.general_call_detection_enable = I2C_GC_ENABLE;
    conf.irq_enable = I2C_NO_INT_ENABLE;
    conf.slave_addr_info = 0;
    I2C_init(I2C_USED, &conf);
    I2C_set_GPIO(I2C_USED);
}


void E2PROM_write_Nbytes(uint16_t memAddr, uint8_t* dataBuffer, uint16_t dataLen){

    //fill first two elements with memory Address
    uint8_t newBuff[MAX_BYTES_SENT] = {memAddr | 0xFF00, memAddr | 0x00FF};

    for(int i = 2,j = 0 ; j < dataLen ; i++,j++){
        newBuff[i] = dataBuffer[i-2];
    }  
    I2C_master_send(I2C_USED, E2PROM_SLAVE_ADDRESS, newBuff, dataLen + 2, STOP, NORMAL_START);
}

void E2PROM_read_Nbytes(uint16_t memAddr, uint8_t* recvBuffer, uint16_t dataLen){

    uint8_t memAddrAsBuffer[2] = {memAddr | 0xFF00, memAddr | 0x00FF};

    //send E2PROM address to read from 
    I2C_master_send(I2C_USED, E2PROM_SLAVE_ADDRESS,memAddrAsBuffer, 2, NO_STOP, NORMAL_START);

    //read the N Bytes
    I2C_master_recv(I2C_USED, E2PROM_SLAVE_ADDRESS, recvBuffer, dataLen, STOP, REP_START);


}