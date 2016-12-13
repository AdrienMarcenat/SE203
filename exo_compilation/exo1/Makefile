CC = arm-none-eabi-gcc
CFLAGS = -std=gnu99 -Wall -Wextra -O1
LDFLAGS = --specs=nosys.specs
OBJS = t.o
EXE = t

t: t.o

dump: t.o 
	@objdump -t t.o

clean:
	@rm -rf $(OBJS)
	@rm -rf $(EXE)
