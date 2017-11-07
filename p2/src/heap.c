#include "heap.h"

heap * new_heap(int maxSize){
    heap * h = malloc(sizeof(heap));
    h->elements = malloc(maxSize * sizeof(heapNode));
    h->indexes = malloc(maxSize * sizeof(int));
    h->freePos = 0;
    for(int i=0; i < maxSize ; i++){
      h->indexes[i] = -1;
    }
    return h;
}

void heap_up(heap * h, int pos){
    int son = pos;
    int father = (son-1)/2;

    while (son!=0) {
      if(h->elements[father].prior < h->elements[son].prior){
        int swapId = h->elements[father].id;
        int swapPrior= h->elements[father].prior;
        h->elements[father].id = h->elements[son].id;
        h->elements[father].prior = h->elements[son].prior;
        h->elements[son].id = swapId;
        h->elements[son].prior = swapPrior;
        h->indexes[swapId] = son;
        h->indexes[h->elements[father].id] = father;
        son = father;
        father = (son-1)/2;
      }else{
        return;
      }
    }
}

void heap_insert(heap * h,int id, int prior){
  h->elements[h->freePos].id = id;
  h->elements[h->freePos].prior = prior;
  h->indexes[id] = h->freePos;
  h->freePos ++;
  heap_up(h,h->freePos - 1);
}

void heap_down(heap * h, int pos){
  int father = pos;
  int son = pos+1;


  while (son<h->freePos) {

    if(h->elements[father].prior < h->elements[son].prior){
      int swapId = h->elements[father].id;
      int swapPrior= h->elements[father].prior;
      h->elements[father].id = h->elements[son].id;
      h->elements[father].prior = h->elements[son].prior;
      h->elements[son].id = swapId;
      h->elements[son].prior = swapPrior;
      h->indexes[swapId] = son;
      h->indexes[h->elements[father].id] = father;
      father = son;
      son = father + 1;
    }else{
      return;
    }
  }
}

int heap_pop(heap * h){
  if(h->freePos==0){
    return -1;
  }
  int popId = h->elements[0].id;
  h->indexes[popId] = -1;
  h->freePos--;
  h->elements[0].id = h->elements[h->freePos].id;
  h->elements[0].prior = h->elements[h->freePos].prior;
  heap_down(h,0);
  return popId;
}

void increase_prior(heap * h,int id, int newPrior){
    h->elements[h->indexes[id]].prior = newPrior;
    heap_up(h,h->indexes[id]);

}

void heap_print(heap * h){
  for(int i=0;i<h->freePos;i++){
    printf("id: %d | prior : %d\n",h->elements[i].id,h->elements[i].prior);
  }

}
