\CC = gcc
CFLAGS  = -Wall -std=c99 -g
TARGET = main

DEPS = tree.o quaternary_tree.o

all: $(TARGET)

tree.o : src/tree.c src/tree.h
	$(CC) $(CFLAGS) -c src/tree.c -o obj/tree.o

quaternary_tree.o : src/quaternary_tree.c src/quaternary_tree.h
	$(CC) $(CFLAGS) -c src/quaternary_tree.c -o obj/quaternary_tree.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c obj/tree.o obj/quaternary_tree.o -o $(TARGET).o

clean:
	$(RM) *.o *~ obj/*.o
