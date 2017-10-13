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
/**
 * [createQuaternaryTree create a Quaternary Tree]
 * @param  root_nextHop [next hop for root]
 * @return              [pointer to root node]
 */
Node * createQuaternaryTree(int root_nextHop);
/**
 * [insertPrefixQuaternaryTree Function to insert a prefix in Quaternary tree]
 * @param  root    [root node]
 * @param  address [prefix to insert]
 * @param  nextHop [nextHop]
 * @return         []
 */
int insertPrefixQuaternaryTree(Node* root , char* address , int nextHop);
/**
 * [freeQuaternaryTree free a Quaternary tree]
 * @param  root [root node]
 * @return      [description]
 */
int freeQuaternaryTree(Node * root);
/**
 * [printTableEven print prefix table of even length]
 * @param root    [description]
 * @param address [description]
 */
void printTableEven(Node * root, char* address);
/**
 * [binaryToQuaternaryTree function to convert a binary tree into a Quaternary tree]
 * @param root_binary [root_binary node]
 * @param root_twobit [root node for Quaternary tree]
 * @param address     [description]
 */
void binaryToQuaternaryTree(BinaryNode* root_binary, Node* root_twobit, char* address);

#endif
