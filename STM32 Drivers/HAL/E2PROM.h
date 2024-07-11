#ifndef E2PROM_H
#define E2PROM_H

#include "../MCAL/i2c.h"

#define E2PROM_SLAVE_ADDRESS 0x2A
#define I2C_USED I2C1
#define MAX_BYTES_SENT 100

//initializes the I2C and GPIO that will communicate with the E2PROM
void E2PROM_init(void);

//Send N Bytes to E2PROM
//Inputs:
//1) Address in E2PROM to begin writing at
//2) data buffer to write in the E2PROM
//3) Length of data to be written in bytes
//Note: E2PROM automatically increments address after each byte written
//Note: dataLen shouldn't exceed MAX_BYTES_SENT
void E2PROM_write_Nbytes(uint16_t memAddr, uint8_t* dataBuffer, uint16_t dataLen);


void E2PROM_write_Nbytes(uint16_t memAddr, uint8_t* recvBuffer, uint16_t dataLen);

#endif




