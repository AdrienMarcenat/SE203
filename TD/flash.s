    /* Flash protection region, placed at 0x400 */
    .text
    .thumb
    .section .flash_config,"a",%progbits
    .long 0xffffffff
    .long 0xffffffff
    .long 0xffffffff
    .long 0xfffffbfe /* Disable security and NMI pin */
