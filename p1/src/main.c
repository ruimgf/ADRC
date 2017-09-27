#include "tree.h"
#include <unistd.h>

int main(int argc, char const *argv[]){
  char buffer[100];
  char command[100];
  if(argc < 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  BinaryNode * root;
  char filePath[100];
  sprintf(filePath, "%s",argv[1]);
  root = readBinaryTreeFromFile(filePath);
  PrintTable(root);
  printf("%d\n",LookUp_rec(root,"1001101010101010",0));
  printf("%d\n",LookUp(root,"1001101010101010"));
}
