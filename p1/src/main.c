#include "tree.h"
#include <unistd.h>
#include "two_tree.h"

int main(int argc, char const *argv[]){
  //char buffer[100];
  //char command[100];
  if(argc < 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  BinaryNode * root;
  Node * root_twobit = createTwoTree(-1);
  char filePath[100];
  sprintf(filePath, "%s",argv[1]);
  root = readBinaryTreeFromFile(filePath);
  PrintTable(root);
  
  binaryToTwoBit(root,root_twobit,"");
  printf("======\n");
  printTableEven(root_twobit,"");

}
