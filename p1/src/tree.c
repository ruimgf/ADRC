#include "tree.h"

BinaryNode * createBinaryTree(){
  BinaryNode * root;
  root = (BinaryNode*) malloc(sizeof(BinaryNode));

  root->nextHoop = NULL;
  root->childs[0] = NULL;
  root->childs[1] = NULL;
  return root;
}

BinaryNode * readBinaryTreeFromFile(){

}
