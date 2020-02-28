CFLAGS += -Wall -O1
LDFLAGS += -lm
EXEC = test
OBJS = test.o simpleregexp.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBM) $(LDLIBS) $(LIBGCC)

clean:
	-rm -f $(EXEC) *.elf *.gdb *.o

.PHONY: all clean
