/*
    Circular Doubly Linked List Implements
*/
#include "circular_DLL.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void createList(struct List ** list){
    (*list)->start = NULL;
    (*list)->end = NULL;
}

// Insertion
void insertStart(struct List ** list, int newElement){
    struct Doubly_LinList *new;

    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));
    if(!new) return;

    new->data = newElement;
    if(isEmpty(list)){
        new->next = new;
        new->prev = new;
        (*list)->start = new;
        (*list)->end = new;
        return;
    }

    new->next = (*list)->start;
    (*list)->start->prev = new;
    (*list)->end->next = new;
    (*list)->start = new;
}

void insertEnd(struct List ** list, int newElement){
    if(isEmpty(list)) {insertStart(list, newElement); return;}

    struct Doubly_LinList *new;

    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));
    if(!new) return;   
    
    new->data = newElement;
    new->prev = (*list)->end;
    (*list)->end->next = new;
    (*list)->end = new;

    new->next = (*list)->start;
    (*list)->start->prev = new;
}

void insertAt(struct List ** list, int newElement, int index){
    if(isEmpty(list)|| !index) {insertStart(list, newElement); return;}

    struct Doubly_LinList *new, *aux = (*list)->start;

    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));
    if(!new) return;  

    int i = 1;
    while(i < index){
        aux = aux->next;
        i++;
    }

    if(aux == (*list)->end){insertEnd(list, newElement); return;}

    new->data = newElement;
    new->prev = aux;
    new->next = aux->next;
    aux->next = new;
    aux = new->next;
    aux->prev = new;
}

void insertSort(struct List ** list, int newElement){
    if(isEmpty(list)){insertStart(list, newElement); return;}
    if(isUnitary(list)) {(*list)->start->data > newElement ? insertStart(list, newElement) : insertEnd(list, newElement); return;}

    int i = 0;
    struct Doubly_LinList *aux = (*list)->start;

    do{ // check it once before turn around
        if(aux->data >= newElement) break;
        aux = aux->next;
        i++;
    }while(aux != (*list)->start);

    if(aux == (*list)->start && i > 0){insertEnd(list, newElement); return;}

    insertAt(list, newElement, i);

}

// Deletion
void removeStart(struct List ** list){
    if(isEmpty(list)) return;
    if(isUnitary(list)){
        free((*list)->start);
        createList(list);
        return;
    }

    struct Doubly_LinList *rmv = (*list)->start;

    (*list)->start = (*list)->start->next;
    (*list)->start->prev = (*list)->end;
    (*list)->end->next = (*list)->start;

    free(rmv);
}

void removeEnd(struct List ** list){
    if(isEmpty(list)){return;}
    if(isUnitary(list)){removeStart(list); return;}

    struct Doubly_LinList *rmv = (*list)->end;

    (*list)->end = (*list)->end->prev;
    (*list)->end->next = (*list)->start;
    (*list)->start->prev = (*list)->end;

    free(rmv);
}

void removeAt(struct List ** list, int index){
    if(isEmpty(list)) return;
    if(isUnitary(list) || !index){removeStart(list); return;}

    struct Doubly_LinList *aux = (*list)->start, *rmv = aux->next;

    while(--index){
        aux = aux->next;
        rmv = rmv->next;
    }

    if(rmv == (*list)->end){removeEnd(list); return;}
    if(rmv == (*list)->start){removeStart(list); return;}

    aux->next = rmv->next;
    aux = rmv->next;
    aux->prev = rmv->prev;

    free(rmv);
}

void clearList(struct List ** list){
    while(!isEmpty(list)) {removeStart(list);}
}

void deleteList(struct List ** list);

// Information
int isEmpty(struct List ** list){
    if(!(*list)->start && !(*list)->end) return 1;
    return 0;
}

int isUnitary(struct List ** list){
    if(!isEmpty(list) && (*list)->end == (*list)->start) return 1;
    return 0;
}

// Visual
void showList(struct List ** list){
    if(isEmpty(list)) {printf("[]"); return;}

    Doubly_LinList *aux = (*list)->start;

    printf("[%d%c", aux->data, aux->next != aux ? ',' : ']');

    aux = aux->next;
    for(; aux != (*list)->start; aux = aux->next){
        printf("%d%c", aux->data, aux->next != (*list)->start ? ',' : ']');
    }
}