#include "tree.h"

BinaryNode * createBinaryTree(int nextHoop){
  BinaryNode * root;
  root = (BinaryNode*) malloc(sizeof(BinaryNode));

  root->nextHoop = nextHoop; // TODO : confirmar com o professor
  root->childs[0] = NULL;
  root->childs[1] = NULL;
  return root;
}



int InsertPrefix(BinaryNode * root , char * address , int nextHoop){
    int index = address[0] - '0';
    if(address[1]=='\0'){

        root->childs[index] = createBinaryTree(nextHoop);
        return 1;
    }else{
      if(root->childs[index]==NULL){
        root->childs[index] = createBinaryTree(-1);
      }
      InsertPrefix(root->childs[index], address+1 , nextHoop);
    }
    return 0;
}

void PrintTable(BinaryNode * root,char * address){
  if(root->nextHoop!=-1){
    printf("%16s %d\n",address,root->nextHoop);
  }
  char nextAddress[17];
  strcpy(nextAddress, address);
  int len = strlen(nextAddress);
  if(root->childs[0] != NULL){
    nextAddress[len] = '0';
    nextAddress[len+1] = '\0';
    PrintTable(root->childs[0],nextAddress);
  }
  if(root->childs[1] != NULL){
    nextAddress[len] = '1';
    nextAddress[len+1] = '\0';
    PrintTable(root->childs[1],nextAddress);
  }

}

BinaryNode * readBinaryTreeFromFile(char * filePath){
  return NULL;
}
