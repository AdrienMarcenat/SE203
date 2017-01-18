MEMORY {
    rom  (rx)  : ORIGIN = 2k, LENGTH = 254k
    ramL (!rx) : ORIGIN = 0x1fffe000, LENGTH = 8k
    ramH (!rx) : ORIGIN = 0x20000000, LENGTH = 24k
    flash_config (!rx) : ORIGIN = 0x400, LENGTH = 32
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
        _bss_start = .;
        *(.bss) *(COMMON)
        _bss_end = .;
    } > ramH

    .flash_config : {
        *(.flash_config)
    } > flash_config
}

ENTRY(_start)

