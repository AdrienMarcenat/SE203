.L1:
    mov r0, #0      ; // i = 0

.L2:
    ldr r1, L4      ; // r1 <- &a
    ldr r2, [r1]    ; // r2 <- a
    cmp r0, r2      ; // i<=a?
    bhi L3          ;  
    add r4, r4, #1  ; // i++
    and r4, r4, #255; // i est un uint8_t, donc on ne garde que les 8 premiers bits, à enlever si i est un unsigned int
    bl .g           ; // g()
    b  .L2          ;

.L3:

.g:

.L4: .word a;  // addresse de a
