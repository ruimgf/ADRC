#include "staticAnalises.h"
#include "list.h"
#include <stdio.h>


void printTest(void* item){
  printf("%d\n",*(int*)item);
}

int main(int argc, char const *argv[]) {

  char filePath[100];
  Graph G;
  myList * test_list;
  if(argc != 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }
  test_list = createmyList();
  int * j = malloc(sizeof(int));
  int * k = malloc(sizeof(int));
  *j = 10;
  *k = 20;
  insertmyListEnd(test_list,j);
  insertmyListEnd(test_list,k);
  printmyList(test_list,&printTest);
  sprintf(filePath, "%s",argv[1]);

  //G = loadFromFile(filePath);

  return 0;
}
