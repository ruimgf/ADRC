#include "two_tree.h"

//function that receive a address and analyses the first two bits, assume that address its a string with at least two entries
int translateBitToIndex(char* address){
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

char* translateIndexToBit(int index){
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



Node * createQuaternaryTree(int root_nextHop){
  Node* root;
  root = (Node*)malloc(sizeof(Node));

  for(int i=0;i<4;i++){
    root->childs[i] = NULL;
  }

  root->nextHop = root_nextHop;
  return root;

}

int insertPrefixQuaternaryTree(Node* root,char* address,int nextHop){

  if(address[2] == '\0'){//reach the position to insert
    if(root->childs[translateBitToIndex(address)] == NULL){//If empty insert
      root->childs[translateBitToIndex(address)] = createQuaternaryTree(nextHop);
    }else{//if not just change the number, because previously it was empty
      root->childs[translateBitToIndex(address)]->nextHop = nextHop;
    }
    return 1;
  }

  if(root->childs[translateBitToIndex(address)] == NULL){//If empty insert node and then jump to the new
    root->childs[translateBitToIndex(address)] = createQuaternaryTree(-1);
  }
  return insertPrefixQuaternaryTree(root->childs[translateBitToIndex(address)], &address[2], nextHop);
  return 0;
}

void printTableEven(Node * root,char * address){
  char nextAddress[17];
  if(root->nextHop!=-1){
      printf("%s %d\n",address,root->nextHop);
  }
  for (int i = 0; i < 4; i++) {
    if(root->childs[i] != NULL){

      sprintf(nextAddress, "%s%s", address, translateIndexToBit(i) );
      printTableEven(root->childs[i], nextAddress);
    }
  }
  return;
}

int freeQuaternaryTree(Node * root){

  for (int i = 0; i < 4; i++) {
    if(root->childs[i]!=NULL){
      freeQuaternaryTree(root->childs[i]);
    }
  }
  free(root);
  return 1;
}


void binaryToQuaternaryTree(BinaryNode* root_binary, Node* root_twobit, char* address){
  char nextAddress[17];
  for(int i = 0;i<2;i++){
    if(root_binary->childs[i] != NULL){
      sprintf(nextAddress,"%s%d",address,i);
      binaryToQuaternaryTree(root_binary->childs[i],root_twobit,nextAddress);
    }
  }

  if(root_binary->nextHop != -1){
    if(strlen(address)%2 == 0){//we are in a even address we can insert with no problems
      insertPrefixQuaternaryTree(root_twobit,address,root_binary->nextHop);
    }else{//we are in a odd address so we have to dicide
      char tempAddress[17];
      for(int i = 0;i<2;i++){
        if(root_binary->childs[i]!= NULL){
          if(root_binary->childs[i]->nextHop == -1){
            sprintf(tempAddress,"%s%d",address,i);

            insertPrefixQuaternaryTree(root_twobit,tempAddress,root_binary->nextHop);
          }
        }else{
          sprintf(tempAddress,"%s%d",address,i);

          insertPrefixQuaternaryTree(root_twobit,tempAddress,root_binary->nextHop);
        }
      }
    }
  }

}
