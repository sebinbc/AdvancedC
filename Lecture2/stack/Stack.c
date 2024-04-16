#include <stdio.h>
#include <stdlib.h>


#include "Stack.h"



Stack *createStack(int capacity)
{
    Stack* stack= (Stack*)malloc(capacity * sizeof(Stack));
    if(!stack) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->data= (int*)malloc(capacity * sizeof(int));
    for(int i=0; i<capacity; i++) {
        stack->data[i] = 0;
    }
    return stack;
}
// Check if the stack is empty
int isEmpty(Stack *stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    return 0;
}
// Add an element to the top of the stack
void push(Stack *stack, int data)
{
    stack->top++;
    stack->data[stack->top] = data;
}
// Remove the top element of the stack
void pop(Stack *stack)
{
    stack->top--;
}
// Return the top element of the stack
int top(Stack *stack)
{
    return stack->data[stack->top];
}
// Free the memory allocated for the stack and the data
void destroyStack(Stack *stack)
{
    free(stack->data);
    free(stack);
}
