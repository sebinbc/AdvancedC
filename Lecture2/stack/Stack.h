#ifndef __STACK_H__
#define __STACK_H__

#define CAPA 20
typedef struct _Stack {
    int *data;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity);
int isEmpty(Stack *stack);
void push(Stack *stack, int data);
void pop(Stack *stack);
int top(Stack *stack);
void destroyStack(Stack *stack);


#endif