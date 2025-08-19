/*
    circular Doubly Linked Lists implementation (copied from doublyLinLists.h) 
*/

#ifndef CIRCULAR_DOUBLY_LINKED_LIST
#define CIRCULAR_DOUBLY_LINKED_LIST

typedef struct Doubly_LinList{

    int data;
    struct Doubly_LinList *next;
    struct Doubly_LinList *prev;

}Doubly_LinList;


// Creation
void createList(struct Doubly_LinList ** list);

// Insertion
void insertStart(struct Doubly_LinList ** list, int newElement);
void insertEnd(struct Doubly_LinList ** list, int newElement);
void insertAt(struct Doubly_LinList ** list, int newElement, int index);
void insertSort(struct Doubly_LinList ** list, int newElement);

// Deletion
void removeStart(struct Doubly_LinList ** list);
void removeEnd(struct Doubly_LinList ** list);
void removeAt(struct Doubly_LinList ** list, int index);
void clearList(struct Doubly_LinList ** list);
void deleteList(struct Doubly_LinList ** list);

// Information
int isEmpty(struct Doubly_LinList ** list);
int isUnitary(struct Doubly_LinList ** list);

// Visual

void showList(struct Doubly_LinList ** list);

#endif // CIRCULAR_DOUBLY_LINKED_LIST