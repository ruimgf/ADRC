#include "staticAnalises.h"
#include "list.h"
#include <stdio.h>
#include "heap.h"

void printTest(void* item){
  printf("%d\n",*(int*)item);
}

int main(int argc, char const *argv[]) {

  char filePath[100];
  Graph  * G;
  //myList * test_list;
  if(argc != 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  sprintf(filePath, "%s",argv[1]);

  G = loadFromFile(filePath);
  printf("%d\n",hasCustomerCycles(G));
  printf("%d\n",isComercialConnected(G));

  heap * h = new_heap(20);
  heap_insert(h,2,20);
  heap_insert(h,1,10);
  heap_insert(h,3,40);
  heap_insert(h,4,50);
  heap_print(h);
  increase_prior(h,1,60);
  printf("change prior\n");
  heap_print(h);
  printf("heap pop : %d\n",heap_pop(h));
  heap_print(h);
  printf("heap pop : %d\n",heap_pop(h));
  heap_print(h);
  return 0;
}
