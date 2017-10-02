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



Node * createTwoTree(int root_nextHoop){
  Node* root;
  root = (Node*)malloc(sizeof(Node));

  for(int i=0;i<4;i++){
    root->childs[i] = NULL;
  }

  root->nextHoop = root_nextHoop;
  return root;

}

int insertPrefixTwoTree(Node* root,char* address,int nextHoop){

  if(address[2] == '\0'){//reach the position to insert
    if(root->childs[translateBitToIndex(address)] == NULL){//If empty insert
      root->childs[translateBitToIndex(address)] = createTwoTree(nextHoop);
    }else{//if not just change the number, because previously it was empty
      root->childs[translateBitToIndex(address)]->nextHoop = nextHoop;
    }
    return 1;
  }

  if(root->childs[translateBitToIndex(address)] == NULL){//If empty insert node and then jump to the new
    root->childs[translateBitToIndex(address)] = createTwoTree(-1);
  }
  return insertPrefixTwoTree(root->childs[translateBitToIndex(address)], &address[2], nextHoop);
  return 0;
}

void printTableEven(Node * root,char * address){
  char nextAddress[17];
  if(root->nextHoop!=-1){
      printf("%s %d\n",address,root->nextHoop);
  }
  for (int i = 0; i < 4; i++) {
    if(root->childs[i] != NULL){

      sprintf(nextAddress, "%s%s", address, translateIndexToBit(i) );
      printTableEven(root->childs[i], nextAddress);
    }
  }
  return;
}

int freeTwoTree(Node * root){

  for (int i = 0; i < 4; i++) {
    if(root->childs[i]!=NULL){
      freeTwoTree(root->childs[i]);
    }
  }
  free(root);
  return 1;
}



void binaryToTwoBit(BinaryNode* root_binary, Node* root_twobit, char* address){
  char nextAddress[17];
  for(int i = 0;i<2;i++){
    if(root_binary->childs[i] != NULL){
      sprintf(nextAddress,"%s%d",address,i);
      binaryToTwoBit(root_binary->childs[i],root_twobit,nextAddress);
    }
  }

  if(root_binary->nextHoop != -1){
    if(strlen(address)%2 == 0){//we are in a even address we can insert with no problems
    
      insertPrefixTwoTree(root_twobit,address,root_binary->nextHoop);
    }else{//we are in a odd address so we have to dicide
      char tempAddress[17];
      for(int i = 0;i<2;i++){
        if(root_binary->childs[i]!= NULL){
          if(root_binary->childs[i]->nextHoop == -1){
            sprintf(tempAddress,"%s%d",address,i);

            insertPrefixTwoTree(root_twobit,tempAddress,root_binary->nextHoop);
          }
        }else{
          sprintf(tempAddress,"%s%d",address,i);

          insertPrefixTwoTree(root_twobit,tempAddress,root_binary->nextHoop);
        }
      }
    }
  }




}
