#include "browser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Browser *initBrowser() {
  Browser *b = (Browser *)malloc(sizeof(Browser));
  strcpy(b->currentPage, "homepage.com");
  b->backStack = createStack();
  b->forwardStack = createStack();
  b->bookmarks = createBST();
  return b;
}

void visitPage(Browser *b, const char *url) {
  push(b->backStack, b->currentPage);
  strcpy(b->currentPage, url);
  // Clear forward stack on new visit
  while (!isEmpty(b->forwardStack)) {
    free(pop(b->forwardStack));
  }
  printf("---> Visiting: %s\n", b->currentPage);
}

void goBack(Browser *b) {
  if (isEmpty(b->backStack)) {
    printf("[!] Cannot go back. History is empty.\n");
    return;
  }
  push(b->forwardStack, b->currentPage);
  char *prev = pop(b->backStack);
  strcpy(b->currentPage, prev);
  free(prev);
  printf("<--- Back to: %s\n", b->currentPage);
}

void goForward(Browser *b) {
  if (isEmpty(b->forwardStack)) {
    printf("[!] Cannot go forward.\n");
    return;
  }
  push(b->backStack, b->currentPage);
  char *next = pop(b->forwardStack);
  strcpy(b->currentPage, next);
  free(next);
  printf("---> Forward to: %s\n", b->currentPage);
}

void addBookmark(Browser *b, const char *name, const char *url) {
  insert(b->bookmarks, name, url);
  printf("[+] Bookmark added: %s\n", name);
}

void openBookmark(Browser *b, const char *name) {
  char *url = search(b->bookmarks, name);
  if (url) {
    visitPage(b, url);
  } else {
    printf("[!] Bookmark '%s' not found.\n", name);
  }
}

void displayStatus(Browser *b) {
  printf("\n------------------------------\n");
  printf("CURRENT PAGE: %s\n", b->currentPage);
  printf("Back Top: %s\n", isEmpty(b->backStack) ? "None" : peek(b->backStack));
  printf("Forward Top: %s\n",
         isEmpty(b->forwardStack) ? "None" : peek(b->forwardStack));
  printf("------------------------------\n");
}