/*
    Implements of Queue (Only Linked)
*/

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue{

    int dado;
    struct Queue *next;

}Queue;

// Create
void createQueue(struct Queue ** q);

// Insert
void Enqueue(struct Queue ** q, int newElement);

// Remove front
void Dequeue(struct Queue ** q);

// See the first
int peek(struct Queue *q);

// Information
int isEmpty(struct Queue ** q);


#endif //QUEUE_H