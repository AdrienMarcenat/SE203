// LDSCRIPT

MEMORY {
    rom  (rx)  : ORIGIN = 0x00000000, LENGTH = 256k
    raml (!rx) : ORIGIN = 0x1fffe000, LENGTH = 8k
    ramh (!rx) : ORIGIN = 0x20000000, LENGTH = 24k
}

SECTION {
    .text : { 
        *(.text)
    } > ramH 

    .rodata : { 
        *(.rodata)
    } > ramH

    .data :  { 
        *(.data)
    } > ramH

    .bss : { 
        *(.bss) *(COMMON) 
    } > ramH
}
