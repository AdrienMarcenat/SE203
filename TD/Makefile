.PHONY: start_debug

PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc
AS=$(PREFIX)as

CFLAGS= -Wall -g -O0 -mcpu=cortex-m0plus -mthumb 
LDFLAGS= -nostdlib -T ld_ram.lds
ASFLAGS= -g -mcpu=cortex-m0plus

CSOURCES= main.c init.c
ASSOURCES = crt0.s
OBJ=$(CSOURCES:%.c=%.o) $(ASSOURCES:%.s=%.o)
PROG = main


$(PROG): $(OBJ)

start_debug:
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean:
	rm -f $(OBJ)
	rm -f $(PROG)
