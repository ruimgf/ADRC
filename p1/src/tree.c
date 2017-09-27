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
  char nextAddress[17];
  if(root->nextHoop!=-1){
    printf("%16s %d\n",address,root->nextHoop);
  }
  for (int i = 0; i < 2; i++) {
    if(root->childs[i] != NULL){
      sprintf(nextAddress,"%s%d",address,i);
      PrintTable(root->childs[i],nextAddress);
    }
  }

}

BinaryNode * readBinaryTreeFromFile(char * filePath){
  return NULL;
}
