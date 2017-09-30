#include "tree.h"
#include <unistd.h>

int main(int argc, char const *argv[]){
  //char buffer[100];
  //char command[100];
  if(argc < 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  BinaryNode * root;
  char filePath[100];
  sprintf(filePath, "%s",argv[1]);
  root = readBinaryTreeFromFile(filePath);
  PrintTable(root);
  //freeBinaryTree(root);
  PrintTable(root);

}
