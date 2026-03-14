#ifndef BROWSER_H
#define BROWSER_H

#include "bst.h"
#include "stack.h"

typedef struct {
  char currentPage[256];
  Stack *backStack;
  Stack *forwardStack;
  BookmarkTree *bookmarks;
} Browser;

Browser *initBrowser();
void visitPage(Browser *b, const char *url);
void goBack(Browser *b);
void goForward(Browser *b);
void addBookmark(Browser *b, const char *name, const char *url);
void openBookmark(Browser *b, const char *name);
void displayStatus(Browser *b);

#endif