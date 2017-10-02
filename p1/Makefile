CC = gcc
CFLAGS  = -Wall -std=c99 -g
TARGET = main

DEPS = tree.o two_tree.o

all: $(TARGET)

tree.o : src/tree.c src/tree.h
	$(CC) $(CFLAGS) -c src/tree.c -o obj/tree.o

two_tree.o : src/two_tree.c src/two_tree.h
	$(CC) $(CFLAGS) -c src/two_tree.c -o obj/two_tree.o

$(TARGET): src/$(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) src/$(TARGET).c obj/$(DEPS) -o $(TARGET).o

clean:
	$(RM) *.o *~ obj/*.o
