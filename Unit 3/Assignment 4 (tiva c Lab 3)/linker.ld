
MEMORY{
    flash(RX) : ORIGIN = 0x00000000, LENGTH = 128K
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS{
    .text : {
        *(.vectors)
        *(.text)
        *(.rodata)
        E_TEXT = .;
    }> flash
    .data :{
        S_DATA = .;
        *(.data)
        . = ALIGN(4);
        E_DATA = .;
    }> sram AT> flash
    .bss :{
        S_BSS = .;
        *(.bss)
        *(COMMON)
        E_BSS = .;
    }> sram

}