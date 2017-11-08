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


  dijkstra(G,atoi(argv[2]));
  return 0;

}
