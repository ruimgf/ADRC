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
  if(argc != 3){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  sprintf(filePath, "%s",argv[1]);

  G = loadFromFile(filePath);
  printf("%d\n",hasCustomerCycles(G));
  printf("%d\n",isComercialConnected(G));

  /*
  test heap

  heap* test_heap = createHeap(10);

  printf("----TESTING CREATION------\n");

  for(int i=0;i<10;i++){
    if(insertHeap(test_heap,i,i) == 0){
      printf("error inserting element: %d\n", i);
    }
  }

  printHeap(test_heap);

  printf("---------------------\n");

  removeHeap(test_heap);
  printHeap(test_heap);
  */
  for(int i=1;i<67000;i++){
      if(G->adj[i]->begin != NULL)
        dijkstra(G,atoi(argv[2]));
      //printf("%d\n",i);
  }

  return 0;
}
