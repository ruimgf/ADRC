#include "two_tree.h"

//function that receive a address and analyses the first two bits, assume that address its a string with at least two entries
int TranslateBitToIndex(char* address){
  if(address[0] == '0'){
    if(address[1] == '0'){
      return 0;
    }else{
      return 1;
    }
  }else{
    if(address[1] == '0'){
      return 2;
    }else{
      return 3;
    }
  }
}

char* TranslateIndexToBit(int index){
  if(index == 0){
    return "00";
  }

  if(index == 1){
    return "01";
  }

  if(index == 2){
    return "10";
  }

  if(index == 3){
    return "11";
  }

  return "nn";

}

Node * createTwoTree(int root_nextHoop){
  Node* root;
  root = (Node*)malloc(sizeof(Node));

  for(int i=0;i<4;i++){
    root->childs[i] = NULL;
  }

  root->nextHoop = root_nextHoop;
  return root;

}

int InsertPrefixTwoTree(Node* root;char* address;int nextHoop){

  if(address[2] == '\0'){//reach the position to insert
    if(root->childs[TranslateBitToIndex(address)] == NULL){//If empty insert
      root->childs[TranslateBitToIndex(address)] = createTwoTree(nextHoop);
    }else{//if not just change the number, because previously it was empty
      root->childs[TranslateBitToIndex(address)]->nextHoop = nextHoop;
    }
    return 1;
  }

  if(root->childs[TranslateBitToIndex(address)] == NULL){//If empty insert node and then jump to the new
    root->childs[TranslateBitToIndex(address)] = createTwoTree(nextHoop);
    return InsertPrefix(root->childs[TranslateBitToIndex(address)], &address[2], -1);
  }else{//if not just jump to that node
    return InsertPrefix(root->childs[TranslateBitToIndex(address)], &address[2], nextHoop);
  }

  return 0;
}

void PrintTableEven(Node * root,char * address){
  char nextAddress[17];
  if(root->nextHoop!=-1){
    if(strlen(address)==0){
        printf("e %d\n",root->nextHoop);
    }else{
        printf("%s %d\n",address,root->nextHoop);
    }

  }
  for (int i = 0; i < 4; i++) {
    if(root->childs[i] != NULL){
      sprintf(nextAddress, "%s%s", address, TranslateIndexToBit(i) );
      PrintTableEven(root->childs[i], nextAddress);
    }
  }
  return;
}

int freeTwoTree(Node* root){

  for (int i = 0; i < 4; i++) {
    if(root->childs[i]!=NULL){
      freeTwoTree(root->childs[i]);
    }
  }
  free(root);
  return 1;
}
