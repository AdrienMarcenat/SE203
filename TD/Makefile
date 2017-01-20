.PHONY: start_server debug clean 

PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc
AS=$(PREFIX)as

CFLAGS= -std=gnu99 -Wall -Werror -g -O1 -mcpu=cortex-m0plus -mthumb 
LDFLAGS= -nostdlib -T ld_ram.lds
ASFLAGS= -g -mcpu=cortex-m0plus

OBJ= main.o init.o led.o bits.o uart.o matrix.o irq.o buttons.o crt0.o flash.o
EXE = main

VPATH = src/

$(EXE): $(OBJ) image.o clocks.o 
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

debug:
	$(PREFIX)gdb $(EXE)

start_server:
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean:
	rm -f $(OBJ)
	rm -f $(EXE)
	rm -f *.d

# Manage dependencies
-include $(subst .o,.d,$(OBJ))

%.d : %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -MM -MF $@ \
-MP $<
