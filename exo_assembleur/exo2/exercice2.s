.L1:
	ldr	r1,	.a        ; // r1 <- &a 
	ldr	r2,	.b        ;	// r2 <- &b 
	ldr	r3,	.c        ;	// r3 <- &c 
	ldr	r3,	[r3]      ;	// r3 <- c

	ldr	r4,	[r1]      ;	// r4 <- a
	add	r5,	[r4], [r3];	// r5 <- *a + *c
	str	r5,	[r4]      ;	// r5 -> *a

	ldr	r4,	[r2]      ; // r4 <- b
	add	r5,	[r4], [r3];	// r5 <- *b + *c
	str	r5,	[r4]      ; // r5 -> *b

.a:
	.word a_addr
.b:
	.word b_addr
.c:
	.word c_addr


