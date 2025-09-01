#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// Creation Trees | insertion
struct Tree* createTreeEmpty(void){
    return NULL;
}

struct Tree* createTree(int data, struct Tree* tl, struct Tree* tr){
    struct Tree* tree = (struct Tree*)malloc(sizeof(struct Tree));

    tree->data = data;
    tree->pl = tl;
    tree->pr = tr;

    return tree;
}

// Remove
void deleteTree(struct Tree **tree){ // delete the entire tree
    if(isEmpty(*tree)) return;

    deleteTree(&((*tree)->pl));
    deleteTree(&((*tree)->pr));

    free(*tree);

    *tree = createTreeEmpty();
}


//information
int isEmpty(struct Tree* tree){
    if(tree == NULL) return 1;
    return 0;
}

//visual
void showTree(struct Tree* tree){
    if(!isEmpty(tree)){
        printf("(%d) <- (%d) -> (%d)\n", 
                !isEmpty(tree->pl) ? tree->pl->data : 0,
                tree->data,
                !isEmpty(tree->pr) ? tree->pr->data : 0
              );

        showTree(tree->pl);
        showTree(tree->pr);
    }
}


