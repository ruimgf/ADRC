#include "tree.h"

int main(){
  BinaryNode * arvore;

  arvore = createBinaryTree(1);
  InsertPrefix(arvore ,"0",2);
  InsertPrefix(arvore ,"00",3);
  InsertPrefix(arvore ,"10",4);
  InsertPrefix(arvore ,"010",5);
  InsertPrefix(arvore ,"1001",6);
  InsertPrefix(arvore ,"1101",7);
  PrintTable(arvore,"");
}
