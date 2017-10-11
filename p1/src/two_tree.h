#ifndef	TWO_TREE_H
#define	TWO_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

typedef struct Node{
  int nextHop;
  struct Node* childs[4]; //If we go right it means that adress is 1 for that bit //If we go left it means that address is 0 for that bit
}Node;

Node * createTwoTree(int root_nextHop);

int insertPrefixTwoTree(Node* root , char* address , int nextHop);

int freeTwoTree(Node * root);

void printTableEven(Node * root, char* address);

void binaryToTwoBit(BinaryNode* root_binary, Node* root_twobit, char* address);

#endif
