#ifndef	MY_TREE_H
#define	MY_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct BinaryNode_{
  int nextHoop;
  struct BinaryNode_ * childs[2]; //If we go right it means that adress is 1 for that bit //If we go left it means that address is 0 for that bit
}BinaryNode;


BinaryNode * createBinaryTree();

int InsertPrefix(BinaryNode * root , char * address , int nextHoop);

int removeNode(BinaryNode * previous_node, int to_remove); // TODO

int freeBinaryTree(BinaryNode * node); // TODO

BinaryNode * readBinaryTreeFromFile(char * filePath);

void PrintTable(BinaryNode * root);

int LookUp(BinaryNode * root,char * address);

int LookUp_rec(BinaryNode* root, char * address, int previus_hoop);


#endif
