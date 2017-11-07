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
  printf("ola\n");
  printf("%d\n",hasCustomerCycles(G));
  printf("ola1\n");
  printf("%d\n",isComercialConnected(G));

  heap * h = new_heap(20);
  dijkstra(G,7);
  return 0;

}
