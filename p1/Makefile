CC = gcc
CFLAGS  = -Wall
TARGET = main

DEPS = tree.o

all: $(TARGET)

tree.o : src/tree.c src/tree.h
	$(CC) $(CFLAGS) -c src/tree.c -o obj/tree.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c obj/$(DEPS) -o $(TARGET).o

clean:
	$(RM) *.o *~ obj/*.o
