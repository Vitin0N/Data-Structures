#include <stdio.h>
#include "linkedList.c"

int main(){

    struct LinkedList *lista;

    createlist(&lista);

    insertSort(&lista, 1);

    clearlist(&lista);

    showList(&lista);

    return 0;
}