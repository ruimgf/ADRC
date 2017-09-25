#include "tree.h"

my_tree_node * create_tree(){
  my_tree_node * root;
  root = (my_tree_node*) malloc(sizeof(my_tree_node));

  root->next_hoop = NULL;
  root->right = NULL;
  root->left = NULL;

  return root;
}
