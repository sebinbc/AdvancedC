/*Stack2.h- "owner" version*/
#ifndef STACK2_H
#define STACK2_H

#include "status.h"

typedef struct Box{
    struct Box *next;
    char value[1];//this way the compiler knows where the field next and value are.
}Box;

typedef struct Stack{
    Box *top;
    int eltSize;//this could be enough but to improve the performance we can use 
                //define an available space in the Box structure.
    //store an available local to the stack to the given stack.
    Box * available;
}Stack;

Stack* createStack(int elementSize);
int isEmpty(Stack *stack);
status_t push(Stack *stack, void *data);
status_t pop(Stack *stack, void *res);

status_t top(Stack *stack,void *res);

void destroyStack(Stack *stack);


#endif // STACK2_H