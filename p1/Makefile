CC = gcc
CFLAGS  = -Wall
TARGET = main

DEPS = tree.o

all: $(TARGET)

tree : src/tree.c src/tree.h
	$(CC) $(CFLAGS) -c src/tree.c

$(TARGET): $(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) $(TARGET).c $(DEPS) -o $(TARGET).o

clean:
	$(RM) *.o *~
