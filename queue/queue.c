
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Create
void createQueue(struct Queue ** q){
    *q = NULL;
}

// Insert
void Enqueue(struct Queue ** q, int newElement){
    struct Queue *new, *end = *q;

    new = (struct Queue *)malloc(sizeof(struct Queue));
    if(!new) return;

    new->dado = newElement; 
    new->next = NULL;

    if(isEmpty(q)) {*q = new; return;}

    while(end->next) {end = end->next;}
    
    end->next = new;    
}

// Remove front
void Dequeue(struct Queue ** q){
    if(isEmpty(q)) return;

    struct Queue *rmv = *q;
    
    *q = (*q)->next;
    free(rmv);
}

// See the first
int peek(struct Queue *q){
    if(isEmpty(&q)) {printf("NULL\n"); return 0;}

    printf("(%d)\n", q->dado);
    return q->dado;
}

// Information
int isEmpty(struct Queue ** q){
    if(*q == NULL) return 1;
    return 0;
}