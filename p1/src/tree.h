#ifndef	MY_TREE_H
#define	MY_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct BinaryNode_{
  int nextHop;
  struct BinaryNode_ * childs[2]; //If we go right it means that adress is 1 for that bit //If we go left it means that address is 0 for that bit
}BinaryNode;

/**
 * [createBinaryTree Function to create a New Binary Tree]
 * @param  nextHop [nextHop for root Node]
 * @return         [pointer to root Node]
 */
BinaryNode * createBinaryTree();
/**
 * [InsertPrefix Function to insert a new prefix on tree]
 * @param  root    [root node]
 * @param  address [prefix to insert]
 * @param  nextHop [nextHop for given prefix]
 * @return         [description]
 */
int InsertPrefix(BinaryNode * root , char * address , int nextHop);
/**
 * [freeBinaryTree Function to free Binary Tree]
 * @param  root [root node]
 * @return      [description]
 */
int freeBinaryTree(BinaryNode * node);
/**
 * [readBinaryTreeFromFile Function to read a binary Tree from a prefix table in a file]
 * @param  filePath [path to file]
 * @return          [node root]
 */
BinaryNode * readBinaryTreeFromFile(char * filePath);
/**
 * [PrintTable PrintTable Interface to user]
 * @param root [root node]
 */
void PrintTable(BinaryNode * root);
/**
 * [LookUp Function to LookUp for next hop for an adress]
 * @param  root    [root node]
 * @param  address [address to search]
 * @return         [nextHop]
 */
int LookUp(BinaryNode * root,char * address);
/**
 * [DeletePrefix Function to delete a prefix]
 * @param root   [root node]
 * @param prefix [prefix to Delete]
 */
void DeletePrefix(BinaryNode * root, char * prefix);
#endif
