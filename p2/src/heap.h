#ifndef	HEAP
#define HEAP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct heapNode_{
    int id;
    int prior;
}heapNode;

typedef struct heap_{
    int freePos; // first free position on elements
    heapNode * elements; // array of elements in heap order
    int * indexes; // indexes[i] is the index of the element with id i on element array
}heap;


heap * new_heap(int maxSize);
void heap_print(heap * h);
int heap_pop(heap * h);
void heap_insert(heap * h,int id, int prior);
void increase_prior(heap * h,int id, int newPrior);
#endif
