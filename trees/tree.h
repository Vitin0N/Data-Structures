#ifndef TREE_H
#define TREE_H

typedef struct Tree{
    int data;
    struct Tree *pl, *pr; // pointer-left | pointer-right
}Tree;

// Creation Trees | insertion.
struct Tree* createTreeEmpty(void);

struct Tree* createTree(int data, struct Tree* tl, struct Tree* tr); // tl = Tree Left | tr = Tree Right

// Remove
void deleteTree(struct Tree **tree);

//information
int isEmpty(struct Tree* tree);

//visual
void showTree(struct Tree* tree);



#endif //TREE_H