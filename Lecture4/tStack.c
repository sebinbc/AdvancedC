#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main(){
    int i;
    printf("Hello World\n");
    Stack *stack = createStack();
    status_t error;
    for(i=1;i<=10;i++)
    {
        printf("Pushing %d\n",i);
        error=push(stack,&i);
        if(error)
        {
            errorMessages(error);
            break;
        }
    }
    while (!isEmpty(stack))
    {
        int topElement;
        error=top(stack,&topElement);
        if(error)
        {
            errorMessages(error);
            break;
        }
        else
        {
            printf("%d\n",topElement);
        }
        errorMessages(pop(stack));
    }
    destroyStack(stack);
    return 0;
}