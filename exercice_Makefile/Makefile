CC = arm-none-eabi-gcc
CFLAGS = -Wall -Werror -g -O2
TARGET_ARCH = -mthumb
LDLIBS = -lm
LDFLAGS = -L/opt/mylibs
vpath %.c libs
OBJS = main.o t1.o t2.o stubs.o
EXE = hello

$(EXE): $(OBJS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

stubs.o: CFLAGS = -g -O2

-include $(subst .o,.d,$(OBJS))

%.d : %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -MM -MF $@\
-MP $<

clean:
	rm -rf $(OBJS)
	rm -rf *.d-MP
	rm -rf $(EXE)
