CC = gcc
CFLAGS  = -Wall
TARGET = main

DEPS = example.o

all: $(TARGET)

example.o : example.c example.h
	$(CC) $(CFLAGS) -c example.c

$(TARGET): $(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) $(TARGET).c $(DEPS) -o $(TARGET).o
  
clean:
	$(RM) *.o *~
