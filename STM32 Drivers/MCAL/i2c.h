#ifndef I2C_H
#define I2C_H

#include "../Device Header/stm32f103x8.h"
#include "rcc.h"
#include "gpio.h"

//Slave Address Struct
typedef struct{
    uint16_t dual_addr_enable; //@ref I2C_DUAL_ADDR_ENABLE_MODES
    uint16_t primary_slave_addr;
    uint16_t secondary_slave_addr;
    uint16_t addr_size; //select 7-bit or 10-bit addr size @ref I2C_ADDR_SIZE
}I2C_slave_addr_t;

//Configuration Struct
typedef struct{
    uint32_t clk_speed; //set clock speed @ref I2C_CLOCK_SPEEDS
    uint16_t clk_stretch_enable; //enable/disable clock stretching @ref I2C_CLOCK_STRETCHING_MODES 
    uint16_t ack_enable; //enable/disable acks @ref I2C_ACK_MODES
    I2C_slave_addr_t *slave_addr_info;
    uint16_t general_call_detection_enable; //@ref I2C_GC_MODES
    uint16_t irq_enable; //Select which interrupt to enable, to enable multiple interrupt types at the same time, use bitwise or between them
                         //Example: I2C_EV_INT_ENABLE | I2C_ERR_INT_ENABLE, @ref I2C_INTERRUPT_ENABLE_MODES
                         //to disable an interrupt don't select it as it will be automatically disabled
}I2C_config_t;

#define I2C_ENABLE 1UL
#define I2C_TXE_RXNE_INT_ENABLE (1UL << 10)

//I2C_CLOCK_SPEEDS
#define I2C_CLOCK_SM_50_KHZ   50000UL
#define I2C_CLOCK_SM_100_KHZ  100000UL
#define I2C_CLOCK_FM_200_KHZ  200000UL  //Not Supported Yet
#define I2C_CLOCK_FM_400_KHZ  400000UL  //Not Supported Yet


//I2C_CLOCK_STRETCHING_MODES
#define I2C_STRETCHING_CLK_ENABLE   0x0000UL
#define I2C_STRETCHING_CLK_DISABLE  (1UL << 7)

//I2C_ACK_MODES
#define I2C_ACK_ENABLE (1UL << 10)
#define I2C_ACK_DISABLE 0x0000UL

//I2C_DUAL_ADDR_ENABLE_MODES
#define I2C_DUAL_ADDR_ENABLE   1UL
#define I2C_DUAL_ADDR_DISABLE  0x0000UL

//I2C_ADDR_SIZE
#define I2C_ADDR_7_BITS   0x0000UL
#define I2C_ADDR_10_BITS  (1UL << 15)

//I2C_GC_MODES
#define I2C_GC_ENABLE   0x0000UL 
#define I2C_GC_DISABLE  (1UL << 6)

//I2C_INTERRUPT_ENABLE_MODES
#define I2C_NO_INT_ENABLE
#define I2C_EV_INT_ENABLE   (1UL << 9)
#define I2C_ERR_INT_ENABLE  (1UL << 8)


//Initializes the I2C
//Inputs
//1) pointer to i2c to be configured
//2) pointer to configuration struct
//Outputs: None
void I2C_init(I2C_t* i2c, I2C_config_t* conf);

//Resets the I2C
//Inputs
//1) pointer to i2c to be configured
//Outputs: None
void I2C_deInit(I2C_t* i2c);

//Sets GPIO Pins to work as I2C lines
//Inputs
//1) pointer to i2c to be configured
//Outputs: None
void I2C_set_GPIO(I2C_t* i2c);

#endif
