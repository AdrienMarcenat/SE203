MEMORY {
    vtable       (w)  : ORIGIN = 0x0, LENGTH = 192
    flash_config (wx) : ORIGIN = 0x400, LENGTH = 32
    pgr          (wx) : ORIGIN = 0x1000, LENGTH = 254k
    ramL         (wx) : ORIGIN = 0x1fffe000, LENGTH = 8k
    ramH         (wx) : ORIGIN = 0x20000000, LENGTH = 24k
}

_stack = ORIGIN(ramH);

SECTIONS {
    .vtable : {
        _vtable_start = .;
        *(.vtable)
        _vtable_end = .;

    } > ramH AT > vtable

    .bootloader : {
        _bootloader_start = .;
        *(.bootloader)
        _bootloader_end = .;
    } > pgr

    .text : { 
        _text_start = .;
        *(.text)
        _text_end = .;
    } > ramH AT > pgr 

    .rodata : { 
        _rodata_start = .;
        *(.rodata) 
        _rodata_end = .;
    } > pgr

    .data :  { 
        _data_start = .;
        *(.data)
        _data_end = .;
    } > ramH AT > pgr

    .bss : { 
        _bss_start = .;
        *(.bss) *(COMMON)
        _bss_end = .;
    } > ramH

    .flash_config : {
        _flash_config_start = .;
        *(.flash_config)
        _flash_config_end = .;
    } > flash_config
}

ENTRY(_start)

