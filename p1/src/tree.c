#include "tree.h"

BinaryNode * createBinaryTree(int nextHop){
  BinaryNode * root;
  root = (BinaryNode*) malloc(sizeof(BinaryNode));

  root->nextHop = nextHop; // TODO : confirmar com o professor
  root->childs[0] = NULL;
  root->childs[1] = NULL;
  return root;
}

int HasChilds(BinaryNode * node){
  for(int i = 0;i<2;i++){
    if(node->childs[i]!= NULL){
      return 1;
    }
  }
  return 0;
}

int InsertPrefix(BinaryNode * root , char * address , int nextHop){
    int index = address[0] - '0';
    if(address[1]=='\0'){
        if(root->childs[index]==NULL){
            root->childs[index] = createBinaryTree(nextHop);
        }else{
          root->childs[index]->nextHop = nextHop;
        }
        return 1;
    }else{
      if(root->childs[index]==NULL){
        root->childs[index] = createBinaryTree(-1);
      }
      InsertPrefix(root->childs[index], address+1 , nextHop);
    }
    return 0;
}



void PrintTableRec(BinaryNode * root,char * address){
  char nextAddress[17];
  if(root->nextHop!=-1){
    if(strlen(address)==0){
        printf("e %d\n",root->nextHop);
    }else{
        printf("%s %d\n",address,root->nextHop);
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
  int nextHop;

  FILE *file = fopen(filePath, "r");
  BinaryNode * root = createBinaryTree(-1);//TODO CHECK IF THE FGETS READS THE ROOT NODE

  while (fgets(buffer,100,file)!=NULL) {
    sscanf(buffer,"%s %d", address, &nextHop);
    InsertPrefix(root,address,nextHop);
  }

  fclose(file);
  return root;
}

int LookUp_rec(BinaryNode* root, char * address, int previus_Hop){
  int code_bit = address[0] - '0';
  if(root->nextHop != -1){
    previus_Hop = root->nextHop;
  }
  if(root->childs[code_bit] != NULL){
    previus_Hop = LookUp_rec(root->childs[code_bit], &address[1],previus_Hop);
  }
  return previus_Hop;
}

int LookUp(BinaryNode * root,char * address){
  int nextHop;
  BinaryNode * aux;
  aux = root;
  int child;
  for (int i = 0; i < strlen(address); i++) {
    if(aux->nextHop!=-1){
      nextHop = aux->nextHop;
    }
    child = address[i] - '0';
    aux = aux->childs[child];
    if(aux==NULL)
      break;
  }
  return nextHop;
}



void DeletePrefix(BinaryNode * root, char * prefix){
  BinaryNode * aux;
  BinaryNode ** father; // vai armazenar um poteiro para o poteiro que da a root da arvore que se pode apagar
  int childNr;

  int len = strlen(prefix);
  aux = root;
  father = NULL;
  for (int i = 0; i < len; i++) {
    childNr = prefix[i] - '0';
    if(aux->childs[childNr]==NULL)
      return;
    if(aux->nextHop != -1 || (aux->childs[0] != NULL && aux->childs[1] != NULL)){
      father = &aux->childs[childNr];
    }
    aux = aux->childs[childNr];
  }
  if(aux->childs[0] == NULL && aux->childs[1] == NULL){ // é uma folha
      freeBinaryTree(*father);
      *father = NULL;
  }else{
      aux->nextHop = -1;
  }




}

//TODO check this
//TODO Simplifiquei isto, vejam se concordam
int freeBinaryTree(BinaryNode * root){

  for (int i = 0; i < 2; i++) {
    if(root->childs[i]!=NULL){
      freeBinaryTree(root->childs[i]);
    }
  }
  free(root);
  return 1;
}
