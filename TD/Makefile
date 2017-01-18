.PHONY: start_debug

PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc
AS=$(PREFIX)as

CFLAGS= -std=gnu99 -Wall -Werror -g -O1 -mcpu=cortex-m0plus -mthumb 
LDFLAGS= -nostdlib -T ld_ram.lds
ASFLAGS= -g -mcpu=cortex-m0plus

CSOURCES= main.c init.c led.c bits.c uart.c matrix.c irq.c buttons.c
ASSOURCES = crt0.s flash.s
OBJ=$(CSOURCES:%.c=%.o) $(ASSOURCES:%.s=%.o) clocks.o image.o
PROG = main

$(PROG): $(OBJ) 

start_debug:
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean:
	mv image.o ../
	mv clocks.o ../
	rm -f $(OBJ)
	rm -f $(PROG)
	mv ../image.o .
	mv ../clocks.o .
