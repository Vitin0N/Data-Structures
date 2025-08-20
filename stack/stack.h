/*
    implementations of Stack (Linked and Static)
*/

#ifndef STACK_H
#define STACK_H

typedef struct dStack{
    int data;
    struct dStack *next;
}dStack;

typedef struct sStack{
    int tam;
    int *data;
    int start, end;
}sStack;

// Dynamic Stack implemetation

// Create
void createStack_d(struct dStack ** stack);

// Insetion
void push_d(struct dStack ** stack, int newElement);

// remove
void  pop_d(struct dStack ** stack);

//information
int isEmpty_d(struct dStack ** stack);

// Visual
void consult_d(struct dStack ** stack);

// Static Stack implementation

// Create
void createStack_s(struct sStack *stack, int max_size);

//Insertion
void push_s(struct sStack *stack, int newElement);

// Remove 
void pop_s(struct sStack *stack);

//information
int isEmpty_s(struct sStack * stack);
int isUnitary(struct sStack * stack);
int isFull(struct sStack * stack);

// Visual
void consult_s(struct sStack *stack);

#endif //STACK_H