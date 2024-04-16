#ifndef __STACK_H__
#define __STACK_H__

#include "status.h"
// implementing a box type

typedef struct Box{
    int value;
    struct Box * next;
}Box,*Stack;

// same function profiles for box
// (except createStack())

Stack* createStack();
int isEmpty(Stack *stack);
status_t push(Stack *stack, int *data);
status_t pop(Stack *stack);
status_t top(Stack *stack, int *data);
void destroyStack(Stack *stack);


#endif