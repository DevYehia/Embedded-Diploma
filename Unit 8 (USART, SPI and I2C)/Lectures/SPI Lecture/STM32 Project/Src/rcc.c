#include "rcc.h"


#define APBconvertPreScaleBitsToShift(bits) ((bits) < 4 ? 0 : (bits) - 3)


const uint16_t AHBPreScales[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

uint32_t RCC_Get_SYSCLK_freq(void){
  
	if((((RCC->CFGR) >> 2) & 0x3) == 0){ 
        return HSI_CLK_FREQ;
    }

    //By default return
    return HSI_CLK_FREQ;
}

uint32_t RCC_Get_AHB_freq(void){
	uint8_t preScaleBits = ((RCC->CFGR) >> 4) & 0xF;
	uint8_t divisor = AHBPreScales[preScaleBits];
    uint32_t res = RCC_Get_SYSCLK_freq() / divisor;
	return res;

}



uint32_t RCC_Get_APB1_freq(void){
	uint8_t preScaleBits = ((RCC->CFGR) >> 8) & 0x7;
	uint8_t shift = APBconvertPreScaleBitsToShift(preScaleBits);
    uint32_t res = RCC_Get_AHB_freq() >> shift;
	return res;
}


uint32_t RCC_Get_APB2_freq(void){
	uint8_t preScaleBits = ((RCC->CFGR) >> 11) & 0x7;
	uint8_t shift = APBconvertPreScaleBitsToShift(preScaleBits);
    uint32_t res = RCC_Get_AHB_freq() >> shift;
	return res;
}