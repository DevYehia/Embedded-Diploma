#include "HAL/E2PROM.h"


int main(void){
	uint8_t data[4] = {1,2,3,4};
	uint8_t recvData[4];
	E2PROM_init();
	E2PROM_write_Nbytes((uint16_t)0x1234, data, 4);
	E2PROM_read_Nbytes((uint16_t)0x1234, recvData, 4);		
	
	
}