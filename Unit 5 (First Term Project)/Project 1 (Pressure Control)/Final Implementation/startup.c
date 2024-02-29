//Author: Prof. Yehia


#include "LIB/types.h"


//symbols from linker script
extern uint32 stack_top;
extern uint32 E_TEXT;
extern uint32 S_DATA;
extern uint32 E_DATA;
extern uint32 S_BSS;
extern uint32 E_BSS;

//prototypes
extern void main(void);
void defaultHandler(void);
void resetHandler(void);
void NMIHandler(void) __attribute__ ((weak,alias("defaultHandler")));
void hardFaultHandler(void) __attribute__ ((weak,alias("defaultHandler")));
void MMFaultHandler(void) __attribute__ ((weak,alias("defaultHandler")));
void busFaultHandler(void) __attribute__ ((weak,alias("defaultHandler")));
void usageFaultHandler(void) __attribute__ ((weak,alias("defaultHandler")));

uint32 * vectors[] __attribute__((section(".vectors"))) = {
    (uint32 *) &stack_top,
    (uint32 *) &resetHandler,
    (uint32 *) &NMIHandler,
    (uint32 *) &hardFaultHandler,
    (uint32 *) &MMFaultHandler,
    (uint32 *) &busFaultHandler,
    (uint32 *) &usageFaultHandler
};


void resetHandler(void){

    //copy data section from flash to sram
    uint32 dataSize = (uint8 *)&E_DATA - (uint8 *)&S_DATA;
    uint8 *src = (uint8 *)&E_TEXT; //start of .data in flash
    uint8 *dst = (uint8 *)&S_DATA; //start of .data in sram
    for(int i = 0  ; i < dataSize ; i++){
        *dst = *src;
        dst++;
        src++;
    }

    //initialize .bss section with 0
    uint32 bssSize = (uint8 *)&E_BSS - (uint8 *)&S_BSS;
    dst = (uint8 *)&S_BSS;
    for(int i = 0  ; i < bssSize ; i++){
        *dst = (uint8)0;
    }    

        main();
}

void defaultHandler(void){}