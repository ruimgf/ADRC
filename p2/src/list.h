#ifndef	LIST
#define LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode_{
    void * item;
    struct listNode_ * next;
    struct listNode_ * prev;
}listNode;

typedef struct List_{
    struct listNode_ * begin;
    struct listNode_ * end;
}myList;

/**
 * [createList createList]
 * @return
 */
myList  *  createmyList();
/**
 * [insertmyListEnd insert on the end off list]
 * @param m       [pointer to list]
 * @param message [message to save]
 * @param lc      [logical clock]
 */
void insertmyListEnd(myList * m, void * item);

void printmyList(myList * m, void (*printfunction)(void*));

/**
 * [freemyList free myList]
 * @param m [pointer to myList]
 */

void freemyList(myList * m);
#endif
