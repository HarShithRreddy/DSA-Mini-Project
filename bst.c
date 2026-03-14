#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BookmarkTree *createBST() {
  BookmarkTree *bst = (BookmarkTree *)malloc(sizeof(BookmarkTree));
  bst->root = NULL;
  return bst;
}

BSTNode *createNode(const char *name, const char *url) {
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  strcpy(newNode->name, name);
  strcpy(newNode->url, url);
  newNode->left = newNode->right = NULL;
  return newNode;
}

BSTNode *insertNode(BSTNode *root, const char *name, const char *url) {
  if (root == NULL)
    return createNode(name, url);
  if (strcmp(name, root->name) < 0)
    root->left = insertNode(root->left, name, url);
  else if (strcmp(name, root->name) > 0)
    root->right = insertNode(root->right, name, url);
  return root;
}

void insert(BookmarkTree *bst, const char *name, const char *url) {
  bst->root = insertNode(bst->root, name, url);
}

char *searchNode(BSTNode *root, const char *name) {
  if (root == NULL)
    return NULL;
  if (strcmp(name, root->name) == 0)
    return root->url;
  if (strcmp(name, root->name) < 0)
    return searchNode(root->left, name);
  return searchNode(root->right, name);
}

char *search(BookmarkTree *bst, const char *name) {
  return searchNode(bst->root, name);
}

void inOrder(BSTNode *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("[%s] -> %s\n", root->name, root->url);
    inOrder(root->right);
  }
}

void destroyTree(BSTNode *root) {
  if (root != NULL) {
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
}