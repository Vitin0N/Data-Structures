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

typedef struct List{ //Now i can have the initial and the last element
    Doubly_LinList *start;
    Doubly_LinList *end;
}List;


// Creation
void createList(struct List ** list);

// Insertion
void insertStart(struct List ** list, int newElement);
void insertEnd(struct List ** list, int newElement);
void insertAt(struct List ** list, int newElement, int index);
void insertSort(struct List ** list, int newElement);

// Deletion
void removeStart(struct List ** list);
void removeEnd(struct List ** list);
void removeAt(struct List ** list, int index);
void clearList(struct List ** list);
void deleteList(struct List ** list);

// Information
int isEmpty(struct List ** list);
int isUnitary(struct List ** list);

// Visual
void showList(struct List ** list);

#endif // CIRCULAR_DOUBLY_LINKED_LIST