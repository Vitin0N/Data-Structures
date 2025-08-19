/*
    Circular Linked Lista Implements
*/
#include "../LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

// Creation
void createlist(struct LinkedList ** list){
    (*list) = NULL;
}

// Insertion
void insertFront(struct LinkedList ** list, int newElement){
    struct LinkedList * new, *end = *list;

    new = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if(!new){return;}

    new->info = newElement;
    if(isEmpty(list)) {
        new->prox = new; 
        *list = new; return;
    }

    while(end->prox != *list) end = end->prox;// Searches for the last node, until the return

    new->prox = *list;
    end->prox = new;
    *list = new;
}

void insertEnd(struct LinkedList ** list, int newElement){
    if(isEmpty(list)){
        insertFront(list, newElement);
        return;
    }
    
    struct LinkedList * new, *end;

    end = *list;

    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if(!new){return;}

    while(end->prox != *list) end = end->prox;// Searches for the last node, until the return

    new->info = newElement;
    new->prox = *list;
    end->prox = new;
}

void insertAt(struct LinkedList ** list, int newElement, int index){
    if(isEmpty(list) || index == 0){
        insertFront(list, newElement);
        return;
    }
    
    struct LinkedList *new, *aux = *list, *end = aux;
    int i = 1;

    while(end->prox != *list) end = end->prox;// Searches for the last node, until the return

    while(i<index){
        aux = aux->prox;
        i++;
    }

    if(aux == end){insertEnd(list, newElement); return;} // if the node is the last one, insert it at the end

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
    if(isUnitary(list)){(*list)->info > newElement ? insertFront(list, newElement) : insertEnd(list, newElement); return;}

    int index = 0;
    struct LinkedList* i = *list, *end = i;

    while(end->prox != *list) {end = end->prox;} // Searches for the last node, until the return

    for(;i->info < newElement && i != end; i = i->prox, index++);

    if(i==end){insertEnd(list, newElement); return;} // if the node is the last one, insert it at the end

    insertAt(list, newElement, index);
}

// Deletion
void deleteList(struct LinkedList ** list){
    clearlist(list);
    
    free(list);
}

void removeFront(struct LinkedList ** list){
    if(isEmpty(list)){return;}
    if(isUnitary(list)) {createlist(list); return;}

    struct LinkedList *aux = *list, *end = *list;

    while(end->prox != *list) end = end->prox;

    *list = (*list)->prox;
    end->prox = *list;
    free(aux);
}

void removeEnd(struct LinkedList ** list){
    if(isEmpty(list)){return;}
    if(isUnitary(list)){removeFront(list); return;}

    struct LinkedList *aux = *list, *end = aux->prox;

    while(end->prox != *list){
        aux = aux->prox;
        end = end->prox;
    }

    aux->prox = *list;
    free(end);
}

void removeAt(struct LinkedList ** list, int index){
    if(isEmpty(list)){return;}
    if(index == 0){removeFront(list); return;} //remove the first node
    if(isUnitary(list)) {removeFront(list); return;} //if there is only one node remove the beginning

    --index;

    struct LinkedList *aux = *list, *rmv = aux->prox;

    while(index--){
        aux = aux->prox;
        rmv = aux->prox;
    }

    aux->prox = rmv->prox;
    free(rmv);
}

void clearlist(struct LinkedList ** list){
    while(*list){
        removeFront(list); //if the list exists remove the beginning
    }
}

// Information of
int isEmpty(struct LinkedList ** list){
    if((*list) == NULL){return 1;}
    return 0;
}

int isUnitary(struct LinkedList ** list){
    if((*list)->prox == *list) return 1;
    return 0;
}

// Visual
void showList(struct LinkedList ** list){
    if(isEmpty(list)) {printf("[]"); return;}
    
    struct LinkedList *i;

    i = *list;
    printf("[%d%c", i->info, i->prox == *list ? ']' : ',');
    i = i->prox;

    for(;i != *list; i = i->prox){
        printf("%d%c", i->info, i->prox == *list ? ']' : ',');
    }
}

