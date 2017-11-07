#include "list.h"
/**
 * [createmyList createmyList]
 * @param  max [max number of messages]
 * @return
 */
myList  * createmyList(){
    myList  * m1 = malloc(sizeof(myList));
    if(m1 == NULL){
      printf("ERROR malloc\n");
      exit(-1);
    }
    m1->begin = NULL;
    m1->end = NULL;
    return m1;
}
/**
 * [insertmyListEnd insert on the end off list]
 * @param m       [pointer to list]
 * @param message [item to save]
 */
void insertmyListEnd(myList * m , void * item){
    listNode * aux;
    listNode * insert_node;
    aux = m->end;

    insert_node = (listNode *)malloc(sizeof(listNode));
    if(insert_node == NULL){
      printf("ERROR : malloc\n");
      exit(-1);
    }

    insert_node->item = item;
    insert_node->next = NULL;

    if(m->begin == NULL){ // Empty List
      m->begin = insert_node;
      insert_node->prev = NULL;
    }else{
      insert_node->prev = m->end->prev;
      m->end->next = insert_node;
    }
    m->end = insert_node;
}
/**
 * [printmyList print list]
 * @param m [pointer to myList]
 */
void printmyList(myList * m, void (*printfunction)(void*)){
    listNode * aux;
    aux = m->begin;
    if(aux==NULL)
      printf("There are no messages\n");
    while(aux != NULL){
        (*printfunction)(aux->item);
        aux = aux->next;
    }
}
/**
 * [freemyList free myList]
 * @param m [pointer to myList]
 */
void freemyList(myList * m){
    listNode * aux = m->begin;
    listNode * aux1;
    while(aux != NULL){
      aux1 = aux-> next;
      free(aux);
      aux = aux1;
    }
    free(m);
}


int lenmyList(myList * m){
  listNode* aux = m->begin;
  int number_tier1 = 0;
  while(aux != NULL){
    number_tier1 = number_tier1 +1;
    aux = aux->next;
  }
  return number_tier1;
}
