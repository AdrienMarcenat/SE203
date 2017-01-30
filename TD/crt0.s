.thumb
.global _start
.type _start, %function
.type _main,  %function

.section .bootloader
_start:
    ldr r0, =_stack
    mov sp, r0 
    bl init_memory
    ldr r0, =_main
    bx r0

.section .text
_main:
    bl main
_end: 
    b _end
