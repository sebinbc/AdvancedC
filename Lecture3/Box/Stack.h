#ifndef __STACK_H__
#define __STACK_H__


// implementing a box type

typedef struct Box{
    int value;
    struct Box * next;
}Box,*Stack;

// same function profiles for box
// (except createStack())

Stack* createStack();
int isEmpty(Stack *stack);
void push(Stack *stack, int data);
void pop(Stack *stack);
int top(Stack *stack);
void destroyStack(Stack *stack);


#endif