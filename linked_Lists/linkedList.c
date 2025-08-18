#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

// Creation
void createlist(struct LinkedList ** list){
    (*list) = NULL;
}

// Insertion
void insertFront(struct LinkedList ** list, int newElement){
    struct LinkedList * new;

    new = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if(!new){return;}

    new->info = newElement;
    new->prox = *list;
    *list = new;
}

void insertEnd(struct LinkedList ** list, int newElement){
    if(isEmpty(list)){
        insertFront(list, newElement);
        return;
    }
    
    struct LinkedList * new, *i;

    i = *list;

    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if(!new){return;}

    for(;i->prox; i = i->prox);

    new->info = newElement;
    new->prox = NULL;
    i->prox = new;
}

void insertAt(struct LinkedList ** list, int newElement, int index){
    if(isEmpty(list)){
        insertFront(list, newElement);
        return;
    }
    
    struct LinkedList *new, *aux = *list;
    int i = 1;

    while(i<index){
        aux = aux->prox;
        i++;
    }

    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));

    new->info = newElement;
    new->prox = aux->prox;
    aux->prox = new;
}

void insertSort(struct LinkedList ** list, int newElement){
    if(isEmpty(list)){
        insertFront(list, newElement);
        return;
    }

    int index = 0;

    struct LinkedList* i = *list;
    for(; i && i->info < newElement; i = i->prox, index++);

    insertAt(list, newElement, index);
}

// Deletion
void deleteList(struct LinkedList ** list){
    clearlist(list);
    
    free(list);
}

void removeFront(struct LinkedList ** list){
    if(isEmpty(list)){return;}

    struct LinkedList *aux = *list;

    *list = (*list)->prox;
    free(aux);
}

void removeEnd(struct LinkedList ** list){
    if(isEmpty(list)){return;}
    if(!(*list)->prox){removeFront(list); return;}

    struct LinkedList *aux, *end;

    for(aux = *list, end = aux->prox ; end->prox ; aux = aux->prox, end = end->prox);

    aux->prox = NULL;
    free(end);
}

void removeAt(struct LinkedList ** list, int index){
    if(isEmpty(list)){return;}
    if(index == 0){removeFront(list); return;}

    --index;

    struct LinkedList *aux = *list, *rmv = aux->prox;

    while(aux && index--){
        aux = aux->prox;
        rmv = aux->prox;
    }

    if(isEmpty(&aux)){return;}

    aux->prox = rmv->prox;
    free(rmv);
}

void clearlist(struct LinkedList ** list){
    struct LinkedList * aux;

    while(*list){
        aux = *list;
        *list = (*list)->prox;
        free(aux);
    }
}

// Information of
int isEmpty(struct LinkedList ** list){
    if((*list) == NULL){return 1;}
    return 0;
}

// Visual
void showList(struct LinkedList ** list){
    struct LinkedList *i;

    i = *list;
    printf("[");
    for(;i != NULL; i = i->prox){
        printf("%d%c", i->info, i->prox == NULL ? ']' : ',');
    }
}