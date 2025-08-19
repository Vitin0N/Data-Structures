/*
    Circular Linked List Implementation (copied from linkedList.h)
*/

#ifndef CIRCULARLINKEDLIST_H  
#define CIRCULARLINKEDLIST_H  

typedef struct LinkedList{
    int info;
    struct LinkedList * prox;
} LinkedList;

// Creation
void createlist(struct LinkedList ** list);

// Insertion
void insertFront(struct LinkedList ** list, int newElement);
void insertEnd(struct LinkedList ** list, int newElement);
void insertAt(struct LinkedList ** list, int newElement, int index);
void insertSort(struct LinkedList ** list, int newElement);

// Deletion
void deleteList(struct LinkedList ** list);
void removeFront(struct LinkedList ** list);
void removeEnd(struct LinkedList ** list);
void removeAt(struct LinkedList ** list, int index);
void clearlist(struct LinkedList ** list);

// Information of
int isEmpty(struct LinkedList ** list);
int isUnitary(struct LinkedList ** list);

// Visual
void showList(struct LinkedList ** list);

#endif // CIRCULARLINKEDLIST_H