\CC = gcc
CFLAGS  = -Wall -O3 -std=c99
TARGET = main
DEPS = digraphs.o staticAnalises.o list.o heap.o menu.o

all: $(TARGET)

list.o : src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

digraphs.o : src/digraphs.c src/digraphs.h
	$(CC) $(CFLAGS) -c src/digraphs.c -o obj/digraphs.o

staticAnalises.o : src/staticAnalises.c src/staticAnalises.h
	$(CC) $(CFLAGS) -c src/staticAnalises.c -o obj/staticAnalises.o

heap.o : src/heap.c src/heap.h
	$(CC) $(CFLAGS) -c src/heap.c -o obj/heap.o

menu.o : src/menu.c src/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o obj/menu.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c  obj/staticAnalises.o obj/digraphs.o obj/list.o obj/heap.o obj/menu.o -o $(TARGET).o -lpthread

clean:
	$(RM) *.o *~ obj/*.o
