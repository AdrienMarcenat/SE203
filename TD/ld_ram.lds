MEMORY {
    rom  (rx)  : ORIGIN = 0x00000000, LENGTH = 256k
    ramL (!rx) : ORIGIN = 0x1fffe000, LENGTH = 8k
    ramH (!rx) : ORIGIN = 0x20000000, LENGTH = 24k
}

_stack = ORIGIN(ramH);

SECTIONS {
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

ENTRY(_start)

