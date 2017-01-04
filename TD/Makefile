.PHONY: start_debug

PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc

CFLAGS= -Wall -Werror -g -O1 -mcpu=cortex-m0plus -mthumb 
LDFLAGS= -nostdlib -T ld_ram.lds

CSOURCE= main.c
OBJ=$(CSOURCES:%.c=%.o)
PROG = main


$(PROG): $(OBJ)

start_debug:
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean:
	rm -f $(OBJ)
	rm -f $(PROG)
