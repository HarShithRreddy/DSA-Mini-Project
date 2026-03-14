#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    char url[256];
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

Stack* createStack();
void push(Stack* s, const char* url);
char* pop(Stack* s);
char* peek(Stack* s);
int isEmpty(Stack* s);
void destroyStack(Stack* s);

#endif