#ifndef BST_H
#define BST_H

typedef struct BSTNode {
  char name[100];
  char url[256];
  struct BSTNode *left, *right;
} BSTNode;

typedef struct {
  BSTNode *root;
} BookmarkTree;

BookmarkTree *createBST();
void insert(BookmarkTree *bst, const char *name, const char *url);
char *search(BookmarkTree *bst, const char *name);
void inOrder(BSTNode *root);
void destroyTree(BSTNode *root);

#endif