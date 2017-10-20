\CC = gcc
CFLAGS  = -Wall -g
TARGET = main

DEPS = graphs.o staticAnalises.o

all: $(TARGET)

graphs.o : src/graphs.c src/graphs.h
	$(CC) $(CFLAGS) -c src/graphs.c -o obj/graphs.o

staticAnalises.o : src/staticAnalises.c src/staticAnalises.h
	$(CC) $(CFLAGS) -c src/staticAnalises.c obj/graphs.o -o obj/staticAnalises.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c obj/graphs.o obj/staticAnalises.o -o $(TARGET).o

clean:
	$(RM) *.o *~ obj/*.o
