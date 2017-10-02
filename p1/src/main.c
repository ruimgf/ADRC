#include "tree.h"
#include <unistd.h>

void Help() {
  printf("Invalid command!\n");
}

int main(int argc, char const *argv[]){
  //char buffer[100];
  //char command[100];


  if(argc != 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  char arg0, arg1[17], args[100];
  int arg2, quit = 1;

  BinaryNode * root;
  char filePath[100];
  sprintf(filePath, "%s",argv[1]);
  root = readBinaryTreeFromFile(filePath);

  while(quit){

    printf(">> ");
    fgets(args, 100, stdin);

    if(sscanf(args, "%c", &arg0) == 1) {
      switch(arg0) {

        case 'p':
          PrintTable(root);
          break;
        case 'i':
          if(sscanf(args, "%c %s %d", &arg0, arg1, &arg2) == 3) {
            InsertPrefix(root, arg1, arg2);
            printf("Prefix %s with nextHop %d was inserted!\n", arg1, arg2);
          } else {
            Help();
          }
          break;
        case 'd':
          if(sscanf(args, "%c %s", &arg0, arg1) == 2) {
            //DeletePrefix(root, arg1);
            printf("Prefix %s was deleted!", arg1);
          } else {
            Help();
          }
          break;
        case 'l':
          if(sscanf(args, "%c %s", &arg0, arg1) == 2) {
            printf("Next hop for address %s is %d.\n", arg1, LookUp(root, arg1));
          } else {
            Help();
          }
          break;
        case 'e':
          //PrintTableEven(root);
          break;
        case 'q':
          quit = 0;
          freeBinaryTree(root);
          printf("Exiting...\n");
          break;
        default:
          Help();
      }
    }
  }
}
