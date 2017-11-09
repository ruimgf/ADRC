#include "heap.h"

//returns a empty heap
heap* createHeap(int capacity){
  heap* new_heap;

  new_heap = (heap*)malloc(sizeof(heap));

  new_heap->heapTable = (heapNode*)malloc(capacity*sizeof(heapNode));
  new_heap->capacity = capacity;
  new_heap->heapLocations = (int*)malloc(capacity*(sizeof(int)));
  new_heap->size = 0;//this means empty heap

  heapNode empty_node;
  empty_node.v = -1;
  empty_node.value = -1;

  //-1 means empty;
  for(int i = 0;i<capacity;i++){
    //TODO not sure if this assigment work
    new_heap->heapTable[i] = empty_node;
    new_heap->heapLocations[i] = -1;
  }

  return new_heap;

}

//function that gives the parent of a child given its position on the heap
int parent(int child_position){
  return child_position/2;
}
//function that gives the child_left position of a given father
int leftChild(int parent_postion){
  return parent_postion*2 +1;
}
//function that gives the child_right position of a given father
int rightChild(int parent_postion){
  return parent_postion*2 +2;
}

//fucntion that swaps to nodes in the heap, it must also swap the locations
void swapNodes(heap* heapToChange, int heapLocationA, int heapLocationB){
  heapNode aux;
  int aux_location;

  /*get the vertices that we want to change*/
  int verticeA = heapToChange->heapLocations[heapToChange->heapTable[heapLocationA].v];
  int verticeB = heapToChange->heapLocations[heapToChange->heapTable[heapLocationB].v];

  //swap heapTable TODO not sure if this assigment work
  aux = heapToChange->heapTable[heapLocationB];
  heapToChange->heapTable[heapLocationB] = heapToChange->heapTable[heapLocationA];
  heapToChange->heapTable[heapLocationA] = aux;

  //swapHeapLocations
  aux_location = heapToChange->heapLocations[verticeB];
  heapToChange->heapLocations[verticeB] = heapToChange->heapLocations[verticeA];
  heapToChange->heapLocations[verticeA] = aux_location;

}

//Heap up in a startPosition of the heap
void heapUp(heap* heapToChange, int startPosition){

  //TODO maybe we have to check if the position is not empty

  //if we start at the top there is nothing to do
  if(startPosition == 0){
    return;
  }

  //if the parent value is greater then the startPosition we have to swap
  if( heapToChange->heapTable[parent(startPosition)].value > heapToChange->heapTable[startPosition].value ){
    swapNodes( heapToChange, parent(startPosition), startPosition);
    //call the function to the node we changed
    heapUp(heapToChange,parent(startPosition));
  }

  //nothing to do if it is ok
  return;
}

//Heap down at a startPosition in the heap
void heapDown(heap* heapToChange, int startPosition){

  //TODO maybe we have to check if the position is not empty

  //if we are at the end, nothing to do
  if(startPosition >= heapToChange->size - 1){
    return;
  }

  //check the lowest child, if the left is the minimum we have to test the left
  if(heapToChange->heapTable[leftChild(startPosition)].value < heapToChange->heapTable[rightChild(startPosition)].value ){

    //check the heap condition
    if( heapToChange->heapTable[leftChild(startPosition)].value > heapToChange->heapTable[startPosition].value ){
      swapNodes( heapToChange, leftChild(startPosition), startPosition);
      //call the function to the node we changed
      heapDown(heapToChange,rightChild(startPosition));
    }

  }else{//if the right is the lowest we have to check the right child

    //check heapcondition
    if( heapToChange->heapTable[rightChild(startPosition)].value > heapToChange->heapTable[startPosition].value ){
      swapNodes( heapToChange, rightChild(startPosition), startPosition);
      //call the function to the node we changed
      heapDown(heapToChange,rightChild(startPosition));
    }

  }

  return;
}

//insert the vertice v with the value in the heap returns 1 in sucess -1 in fail
int insertHeap(heap* heapToChange, int v, int value){

  //check if we have available capacity
  if(heapToChange->capacity < heapToChange->size+1){
    return -1;
  }

  //we go to the last insert it there and do heapUp

  heapNode new;
  new.v = v;
  new.value=value;

  heapToChange->heapTable[heapToChange->size] = new;
  heapToChange->heapLocations[heapToChange->size] = heapToChange->size;

  heapUp(heapToChange,heapToChange->size);

  //update the size
  heapToChange->size = heapToChange->size +1;
  return 1;
}


heapNode removeHeap(heap * heapToChange){
    //we have to swap the final with the last element
    heapNode ret;
    ret.v = heapToChange->heapTable[0].v;
    swapNodes(heapToChange,0,heapToChange->size-1);

    //erease the final element
      //first make the location of the element -1 to know that this element is no more in the heap
    heapToChange->heapLocations[heapToChange->heapTable[heapToChange->size - 1].v] = -1;
    heapToChange->size = heapToChange->size - 1;
    //heap down on the first
    heapDown(heapToChange,0);
    return ret;
}

/* This funtion change the priority(value) of a given vertice to a new value
    return 1 if sucess -1 if fail*/
int modifyHeap(heap* heapToChange,int v,int value){

  // first check if the v is in the heap, if not return fail
  if(heapToChange->heapLocations[v] == -1){
    return -1;
  }

  //if the vertice v is in the heap, we are ok to change it

  //position of v in the heap
  int position = heapToChange->heapLocations[v];
  //if the value that is there is of greater priority we have to change and then
  //heap down
  if(heapToChange->heapTable[position].value > value ){
    heapToChange->heapTable[position].value = value;
    heapDown(heapToChange,position);
  }else{
    //if the new value is smaller we have to heapUp
    heapToChange->heapTable[position].value = value;
    heapUp(heapToChange,position);
  }

  return 1;

}

/* Function that check if the heap is empty
  return 1 if is empty, -1 otherwise*/
int isEmpty(heap* heapToChange){
  //if the location of the first element in the heap is -1 the it is empty
  if(heapToChange->heapLocations[heapToChange->heapTable[0].v] == -1){
    return 1;
  }else{
    return -1;
  }
}
