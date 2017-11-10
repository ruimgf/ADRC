#ifndef	HEAP
#define HEAP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ATENTION THIS IS A MINHEAP!!!

//Struct of each node
typedef struct {
  int v;//vertice that is corresponds
  int value;
}heapNode;

//each heap have a heapTable taht is the heap and a heapLocations that is where is each vertice
typedef struct {
  heapNode* heapTable;
  int* heapLocations;
  int size;
  int capacity;
}heap;

//retruns a empty heap with size size
heap* createHeap(int capacity);

//given a pair of a vertice and a value inserts it on the heap
int insertHeap(heap* heapToChange, int v, int value);

//returns the first element of the heap
int removeHeap(heap* heapToChange);

/* This funtion change the priority(value) of a given vertice to a new value
    return 1 if sucess 0 if fail*/
int modifyHeap(heap* heapToChange,int v,int value);

/* Function that check if the heap is empty
  return 1 if is empty, 0 otherwise*/
int isEmpty(heap* heapToChange);

void printHeap(heap* heapToChange);

void freeHeap(heap * h);
#endif
