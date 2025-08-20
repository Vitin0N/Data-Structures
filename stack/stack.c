#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Dynamic Stack implemetation

// Create
void createStack_d(struct dStack ** stack){
    *stack = NULL;
}

// Insetion
void push_d(struct dStack ** stack, int newElement){
    struct dStack *new;

    new = (struct dStack*)malloc(sizeof(struct dStack));
    if(!new) return;

    new->data = newElement;
    new->next = *stack;
    *stack = new;
}

// remove
void pop_d(struct dStack ** stack){
    if(isEmpty_d(stack)) return;
    struct dStack *rmv = *stack;

    *stack = (*stack)->next;

    free(rmv);
}

//information
int isEmpty_d(struct dStack ** stack){
    if(*stack == NULL) return 1;
    return 0;
}

// Visual
void consult_d(struct dStack ** stack){
    if(isEmpty_d(stack)) {printf("()\n"); return;}
    printf("(%d)\n", (*stack)->data);
}

// Static Stack implementation

// Create
void createStack_s(struct sStack *stack, int max_size){
    stack->data = (int*)malloc(max_size*sizeof(int)); // verifyspace in memory
    if(!(stack->data)) return; // if there is no space, return

    stack->start = -1;
    stack->end = -1;
    stack->tam = max_size;
}

//Insertion
void push_s(struct sStack *stack, int newElement){
    if(isEmpty_s(stack)){
        stack->start = 0;
        stack->end = 0;
        stack->data[stack->end] = newElement;
        return;
    }

    if(isFull(stack)) return;

    stack->end++;
    stack->data[stack->end] = newElement;
}

// Remove 
void pop_s(struct sStack *stack){
    if(isEmpty_s(stack)) return;
    if(isUnitary(stack)){
        stack->end = -1;
        stack->start = -1;
        return;
    }

    stack->end--;
}

//information
int isEmpty_s(struct sStack * stack){
    if(stack->end == -1 && stack->start == -1) return 1;
    return 0;
}
int isUnitary(struct sStack * stack){
    if(stack->end == 0 && stack->start == 0) return 1;
    return 0;
}

int isFull(struct sStack * stack){
    if(stack->end == stack->tam) return 1;
    return 0;
}


// Visual
void consult_s(struct sStack *stack){
    if(isEmpty_s(stack)) return;

    printf("(%d)\n", stack->data[stack->end]);
}