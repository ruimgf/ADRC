\CC = gcc
CFLAGS  = -Wall -g -std=c99
TARGET = main

DEPS = digraphs.o staticAnalises.o list.o heap.o

all: $(TARGET)

list.o : src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

digraphs.o : src/digraphs.c src/digraphs.h
	$(CC) $(CFLAGS) -c src/digraphs.c -o obj/digraphs.o

staticAnalises.o : src/staticAnalises.c src/staticAnalises.h
	$(CC) $(CFLAGS) -c src/staticAnalises.c -o obj/staticAnalises.o

heap.o : src/heap.c src/heap.h
	$(CC) $(CFLAGS) -c src/heap.c -o obj/heap.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c  obj/staticAnalises.o obj/digraphs.o obj/list.o obj/heap.o -o $(TARGET).o

clean:
	$(RM) *.o *~ obj/*.o
