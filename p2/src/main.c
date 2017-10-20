#include "staticAnalises.h"
#include <stdio.h>

int int main(int argc, char const *argv[]) {

  char filePath[100];
  Graph G;

  if(argc != 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  sprintf(filePath, "%s",argv[1]);

  G = loadFromFile(filePath);

  return 0;
}
