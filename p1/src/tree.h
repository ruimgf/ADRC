#ifndef	MY_TREE_H
#define	MY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryNode_{
  char* next_hoop;
  struct BinaryNode_ * childs[2]; //If we go right it means that adress is 1 for that bit //If we go left it means that address is 0 for that bit
}BinaryNode;  


//Function that returns a empty tree, that is the right and left links are pointing to null.
BinaryNode * createBinaryTree();

//Function that inserts a new node in the give links of the tree with the next_hoop
//returns 1 if good 0 if it occours a problem.
int insertNode(BinaryNode * link ,char * next_hoop);

//function that removes the right node attached to previous_node
// if to_remove = 1 or remove the left node if to_remove = 0.
int removeNode(BinaryNode* previous_node, int to_remove);

//Function that frees memory used by my_tree
//returns 1 if ok 0 if error.
int freeBinaryTree(BinaryNode * node);

#endif
