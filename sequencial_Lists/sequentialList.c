#include "sequentialList.h"
#include <stdlib.h>

// Creation
void createList(SequentialList *list, int max_size){
    list->list = (int*)malloc(max_size * sizeof(int)); //verify if have space in memory
    if(!(list->list)) {
        return;
    }
    
    list->tam = max_size;
    list->ctr = -1;
}

//Insertion
void insertFront(SequentialList *list, int element){
    if(isFull(list)){return;}

    moveRight(list, 0);

    list->ctr++;
    list->list[0] = element;
}

void insertEnd(SequentialList * list, int element){
    if(isFull(list)){return;}

    list->ctr++;
    list->list[list->ctr] = element;
}

void insertAt(SequentialList * list, int index, int element){
    if(isFull(list)){return;}

    moveRight(list, index);

    list->ctr++;
    list->list[index] = element;
}

void insertSort(SequentialList * list, int element){
    if(isFull(list)){return;}
    int i;

    for(i=0; i <= list->ctr && list->list[i] <= element; i++); //Go to index of the element minor than 'element

    moveRight(list, i);
    list->list[i] = element;
    list->ctr++;
}

//deletion
void deleteList(SequentialList * list){
    if (list != NULL){
        free(list->list);
        list->ctr = -1;
        list->tam = -1;
        free(list);
    }
    
}

void removeFront(SequentialList * list){
    if(isEmpty(list)){return;}

    moveLeft(list, list->ctr);

    list->ctr--;
}

void removeEnd(SequentialList * list){
    if(isEmpty(list)){return;}

    list->ctr--;
}

void removeAt(SequentialList * list, int index){
    if(isEmpty(list)){return;}

    moveLeft(list, index);

    list->ctr--;
}

void clearList(SequentialList * list){
    list->ctr = -1;
}

//information of 
int isEmpty(SequentialList * list){
    if(list->ctr == -1){
        return 1;
    }
    return 0;
}

int isFull(SequentialList * list){
    if(list->ctr == list->tam-1){
        return 1;
    }
    return 0;
}

//move elements
void moveLeft(SequentialList * list, int start){
    if(isEmpty(list)){return;}
    
    for(int i = start; i < list->ctr; i++){
        list->list[i] = list->list[i+1];
    }
}

void moveRight(SequentialList * list, int start){
    if(isFull(list)){return;}

    int i = list->ctr;

    for(;i >= start; i--){
        list->list[i+1] = list->list[i];
    }
} 