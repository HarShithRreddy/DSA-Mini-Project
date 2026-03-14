#include "browser.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Browser *myBrowser = initBrowser();
  int choice;
  char url[256], name[100];

  while (1) {
    printf("\n1. Visit Page\n2. Go Back\n3. Go Forward\n4. Add Bookmark\n5. "
           "Open Bookmark\n6. List Bookmarks\n7. Status\n8. Exit\nChoice: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    switch (choice) {
    case 1:
      printf("Enter URL: ");
      scanf("%s", url);
      visitPage(myBrowser, url);
      break;
    case 2:
      goBack(myBrowser);
      break;
    case 3:
      goForward(myBrowser);
      break;
    case 4:
      printf("Name: ");
      scanf("%s", name);
      printf("URL: ");
      scanf("%s", url);
      addBookmark(myBrowser, name, url);
      break;
    case 5:
      printf("Name to open: ");
      scanf("%s", name);
      openBookmark(myBrowser, name);
      break;
    case 6:
      printf("\n--- Bookmarks ---\n");
      inOrder(myBrowser->bookmarks->root);
      break;
    case 7:
      displayStatus(myBrowser);
      break;
    case 8:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  }
  return 0;
}