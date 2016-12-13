CFLAGS = -std=gnu99 -Wall -Wextra -O1
OBJS   = t.o
EXE    = t

run: $(EXE)
	./$(EXE)
	
dump: $(EXE)
	@objdump -h $(EXE)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(EXE)
