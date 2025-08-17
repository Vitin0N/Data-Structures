/*
    Implementation of Sequential Lists (ARRAYS)
*/
#ifndef SEQUENTIALLIST_H  
#define SEQUENTIALLIST_H  

typedef struct SequentialList{ //With dynamic size
    int tam; 
    int *list;
    int ctr;
}SequentialList;

// Creation
void createList(SequentialList *list, int max_size);

//Insertion
void insertFront(SequentialList *list, int element);
void insertEnd(SequentialList * list, int element);
void insertAt(SequentialList * list, int index, int element);
void insertSort(SequentialList * list, int element);

//deletion
void deleteList(SequentialList * list);
void removeFront(SequentialList * list);
void removeEnd(SequentialList * list);
void removeAt(SequentialList * list, int index);
void clearList(SequentialList * list);

//information of 
int isEmpty(SequentialList * list);
int isFull(SequentialList * list);

//move elements
void moveLeft(SequentialList * list, int start);
void moveRight(SequentialList * list, int start);

#endif // SEQUETIALLIST_H