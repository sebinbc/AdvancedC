#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main(){
    int i;
    Stack *stack = createStack(CAPA);
    if(!stack) {
        return 1;
    }
    for(i=0;i<CAPA;i++)
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