CC=arm-none-eabi-gcc
CFLAGS= -Wall -Werror -g -O1 -mcpu=cortex-m0plus -mthumb 
LDFLAGS= -T ld_ram.lds
SOURCE= main.c
PROG = main

$(PROG): main.o


.PHONY: start_debug

start_debug:
	JlinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean:
	rm -f *.o
	rm -f $(PROPG)
