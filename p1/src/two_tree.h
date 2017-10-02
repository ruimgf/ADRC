#ifndef	TWO_TREE_H
#define	TWO_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node{
  int nextHoop;
  struct Node* childs[4]; //If we go right it means that adress is 1 for that bit //If we go left it means that address is 0 for that bit
}Node;

Node * createTwoTree(int root_nextHoop);

int InsertPrefixTwoTree(Node* root , char* address , int nextHoop);

int freeTwoTree(Node * root);

void PrintTableEven(Node * root);

#endif
