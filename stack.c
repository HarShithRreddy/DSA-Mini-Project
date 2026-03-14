#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *createStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = NULL;
  return s;
}

void push(Stack *s, const char *url) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  strncpy(newNode->url, url, 255);
  newNode->next = s->top;
  s->top = newNode;
}

char *pop(Stack *s) {
  if (isEmpty(s))
    return NULL;
  StackNode *temp = s->top;
  char *url = strdup(temp->url);
  s->top = temp->next;
  free(temp);
  return url;
}

char *peek(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->top->url;
}

int isEmpty(Stack *s) { return s->top == NULL; }

void destroyStack(Stack *s) {
  while (!isEmpty(s)) {
    free(pop(s));
  }
  free(s);
}