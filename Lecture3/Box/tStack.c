#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main(){
    int i;
    Stack *stack = createStack();

    for(i=1;i<=10;i++)
    {
        push(stack,i);
    }
    while (!isEmpty(stack))
    {
        printf("%d\n",top(stack));
        pop(stack);
    }
    destroyStack(stack);
    return 0;
}