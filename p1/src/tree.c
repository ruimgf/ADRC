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
        if(root->childs[index]==NULL){
            root->childs[index] = createBinaryTree(nextHoop);
        }else{
          root->childs[index]->nextHoop = nextHoop;
        }
        return 1;
    }else{
      if(root->childs[index]==NULL){
        root->childs[index] = createBinaryTree(-1);
      }
      InsertPrefix(root->childs[index], address+1 , nextHoop);
    }
    return 0;
}



void PrintTableRec(BinaryNode * root,char * address){
  char nextAddress[17];
  if(root->nextHoop!=-1){
    if(strlen(address)==0){
        printf("e %d\n",root->nextHoop);
    }else{
        printf("%s %d\n",address,root->nextHoop);
    }

  }
  for (int i = 0; i < 2; i++) {
    if(root->childs[i] != NULL){
      sprintf(nextAddress,"%s%d",address,i);
      PrintTableRec(root->childs[i],nextAddress);
    }
  }
}

void PrintTable(BinaryNode * root){
    PrintTableRec(root,"");
}



BinaryNode * readBinaryTreeFromFile(char * filePath){

  char buffer[100];
  char address[17];
  int nextHoop;

  FILE *file = fopen(filePath, "r");
  BinaryNode * root = createBinaryTree(-1);

  while (fgets(buffer,100,file)!=NULL) {
    sscanf(buffer,"%s %d", address, &nextHoop);
    InsertPrefix(root,address,nextHoop);
  }
  return root;
}

int LookUp_rec(BinaryNode* root, char * address, int previus_hoop){
  int code_bit = address[0] - '0';
  if(root->nextHoop != -1){
    previus_hoop = root->nextHoop;
  }
  if(root->childs[code_bit] != NULL){
    previus_hoop = LookUp_rec(root->childs[code_bit], &address[1],previus_hoop);
  }
  return previus_hoop;
}

int LookUp(BinaryNode * root,char * address){
  int nextHoop;
  BinaryNode * aux;
  aux = root;
  int child;
  for (int i = 0; i < strlen(address); i++) {
    if(aux->nextHoop!=-1){
      nextHoop = aux->nextHoop;
    }
    child = address[i] - '0';
    aux = aux->childs[child];
    if(aux==NULL)
      break;
  }
  return nextHoop;
}

int freeBinaryTree(BinaryNode * root){
  for(int i = 0 ; i < 2 ; i++){
    if(root->childs[i]!= NULL){
      freeBinaryTree(root->childs[i]);
    }else{
      free(root->childs[i]);
    }
  }
  return 1;
}
