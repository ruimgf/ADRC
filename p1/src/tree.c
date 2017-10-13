#include "tree.h"
/**
 * [createBinaryTree Function to create a New Binary Tree]
 * @param  nextHop [nextHop for root Node]
 * @return         [pointer to root Node]
 */
BinaryNode * createBinaryTree(int nextHop){
  BinaryNode * root;
  root = (BinaryNode*) malloc(sizeof(BinaryNode));

  root->nextHop = nextHop;
  root->childs[0] = NULL;
  root->childs[1] = NULL;
  return root;
}

/**
 * [InsertPrefix Function to insert a new prefix on tree]
 * @param  root    [root node]
 * @param  address [prefix to insert]
 * @param  nextHop [nextHop for given prefix]
 * @return         [description]
 */
int InsertPrefix(BinaryNode * root , char * address , int nextHop){
    int index = address[0] - '0';
    if(address[1]=='\0'){
        if(root->childs[index]==NULL){
            root->childs[index] = createBinaryTree(nextHop);
        }else{
          root->childs[index]->nextHop = nextHop;
        }
        return 1;
    }else{
      if(root->childs[index]==NULL){
        root->childs[index] = createBinaryTree(-1);
      }
      InsertPrefix(root->childs[index], address+1 , nextHop);
    }
    return 0;
}


/**
 * [PrintTableRec Function to print Prefix table]
 * @param root    [root node]
 * @param address [recursion argument]
 */
void PrintTableRec(BinaryNode * root,char * address){
  char nextAddress[17];
  if(root->nextHop!=-1){
    if(strlen(address)==0){
        printf("e %d\n",root->nextHop);
    }else{
        printf("%s %d\n",address,root->nextHop);
    }

  }
  for (int i = 0; i < 2; i++) {
    if(root->childs[i] != NULL){
      sprintf(nextAddress,"%s%d",address,i);
      PrintTableRec(root->childs[i],nextAddress);
    }
  }
}

/**
 * [PrintTable PrintTable Interface to user]
 * @param root [root node]
 */
void PrintTable(BinaryNode * root){
    PrintTableRec(root,"");
}


/**
 * [readBinaryTreeFromFile Function to read a binary Tree from a prefix table in a file]
 * @param  filePath [path to file]
 * @return          [node root]
 */
BinaryNode * readBinaryTreeFromFile(char * filePath){

  char buffer[100];
  char address[17];
  int nextHop;

  FILE *file = fopen(filePath, "r");
  BinaryNode * root = createBinaryTree(-1);

  while (fgets(buffer,100,file)!=NULL) {
    sscanf(buffer,"%s %d", address, &nextHop);
    InsertPrefix(root,address,nextHop);
  }

  fclose(file);
  return root;
}

/**
 * [LookUp Function to LookUp for next hop for an adress]
 * @param  root    [root node]
 * @param  address [address to search]
 * @return         [nextHop]
 */
int LookUp(BinaryNode * root,char * address){
  int nextHop;
  BinaryNode * aux;
  aux = root;
  int child;
  for (int i = 0; i < strlen(address); i++) {
    if(aux->nextHop!=-1){
      nextHop = aux->nextHop;
    }
    child = address[i] - '0';
    aux = aux->childs[child];
    if(aux==NULL)
      break;
  }
  return nextHop;
}


/**
 * [DeletePrefix Function to delete a prefix]
 * @param root   [root node]
 * @param prefix [prefix to Delete]
 */
void DeletePrefix(BinaryNode * root, char * prefix){
  BinaryNode * aux;
  BinaryNode ** father; // vai armazenar um poteiro para o poteiro que da a root da arvore que se pode apagar
  int childNr;

  int len = strlen(prefix);
  aux = root;
  father = NULL;
  for (int i = 0; i < len; i++) {
    childNr = prefix[i] - '0'; // int to adress vector
    if(aux->childs[childNr]==NULL) //prefixo não existe
      return;
    if(aux->nextHop != -1 || (aux->childs[0] != NULL && aux->childs[1] != NULL)){ // não tem saida nula ou tem mais que um filho
      father = &aux->childs[childNr]; // modify root of tree to delete
    }
    aux = aux->childs[childNr];
  }
  if(aux->childs[0] == NULL && aux->childs[1] == NULL){ // é uma folha
      freeBinaryTree(*father);
      *father = NULL;
  }else{ // é um nó intermédio
      aux->nextHop = -1;
  }

}

/**
 * [freeBinaryTree Function to free Binary Tree]
 * @param  root [root node]
 * @return      [description]
 */
int freeBinaryTree(BinaryNode * root){

  for (int i = 0; i < 2; i++) {
    if(root->childs[i]!=NULL){
      freeBinaryTree(root->childs[i]);
    }
  }
  free(root);
  return 1;
}
