/*
    Circular Doubly Linked List Implements
*/
#include "circular_DLL.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// Creation
void createList(struct Doubly_LinList ** list){
    *list = NULL;
}

// Insertion
void insertStart(struct Doubly_LinList ** list, int newElement){
    struct Doubly_LinList *new;

    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));
    if(!new){return;}

    new->prev = NULL;
    new->data = newElement;
    new->next = (*list);
    if (!isEmpty(list)) {
        (*list)->prev = new;
    }
    *list = new;
}

void insertEnd(struct Doubly_LinList ** list, int newElement){
    if (isEmpty(list)){insertStart(list, newElement); return;}

    struct Doubly_LinList *aux = *list;
    while(aux->next){aux = aux->next;}

    struct Doubly_LinList *new;
    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));
    if(!new){return;}

    new->next = NULL;
    new->data = newElement;
    new->prev = aux;
    aux->next = new;
}

void insertAt(struct Doubly_LinList ** list, int newElement, int index){
    if(isEmpty(list) || !index){insertStart(list, newElement); return;}

    struct Doubly_LinList *aux = *list, *new;
    int i = 1;
    
    while(i<index && aux){
        i++;
        aux = aux->next;
    }

    if(isEmpty(&aux)){insertEnd(list, newElement); return;}

    new = (struct Doubly_LinList*)malloc(sizeof(struct Doubly_LinList));

    new->data = newElement;
    new->prev = aux;
    new->next = aux->next;

    aux->next = new;
    aux = new->next;
    if(aux) {aux->prev = new;}
}

void insertSort(struct Doubly_LinList ** list, int newElement){
    if(isEmpty(list)){insertStart(list, newElement); return;}

    struct Doubly_LinList *aux = *list; 
    int index = 0;
    
    while(aux && aux->data < newElement){
        aux = aux->next;
        index++;
    }

    insertAt(list, newElement, index);
}

// Deletion
void removeStart(struct Doubly_LinList ** list){
    if(isEmpty(list)) return;

    struct Doubly_LinList *rmv = *list;

    *list = (*list)->next;
    if(*list) (*list)->prev = NULL;

    free(rmv);
}

void removeEnd(struct Doubly_LinList ** list){
    if(isEmpty(list)) return;
    if(isUnitary(list)){removeStart(list); return;}

    struct Doubly_LinList *aux = *list,*rmv = aux->next;

    while(rmv && rmv->next){
        aux = aux->next;
        rmv = rmv->next;
    }

    aux->next = NULL;
    free(rmv);
}

void removeAt(struct Doubly_LinList ** list, int index){
    if(isEmpty(list) || !index){removeStart(list); return;}
    if(isUnitary(list)){removeStart(list); return;}

    struct Doubly_LinList *aux = *list, *rmv = aux->next; 
    int i = 1;   

    while(rmv->next && i<index){
        aux = aux->next;
        rmv = rmv->next;
        i++;
    }

    aux->next = rmv->next;
    aux = rmv->next;
    if(aux) aux->prev = rmv->prev;

    free(rmv);
}

void clearList(struct Doubly_LinList ** list){
    if(isEmpty(list)) return;
    
    while(!isEmpty(list)){removeStart(list);}
}

void deleteList(struct Doubly_LinList ** list){
    if(!isEmpty(list)) clearList(list);

    free(list);
}

// Information
int isEmpty(struct Doubly_LinList ** list){
    if(!(*list)){
        return 1;
    }
    return 0;
}

int isUnitary(struct Doubly_LinList ** list){
    if((*list)->next == (*list)->prev){
        return 1;
    }
    return 0;
}

// Visual
void showList(struct Doubly_LinList ** list){
    if(isEmpty(list)){printf("[]"); return;}

    struct Doubly_LinList *aux;

    printf("[");
    for(aux = *list; aux ;aux = aux->next){
        printf("%d%c", aux->data, aux->next ? ',' : ']');
    }
}