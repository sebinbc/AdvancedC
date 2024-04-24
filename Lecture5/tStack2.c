// generic stack.
#include <stdio.h>
#include <stdlib.h>
#include "Stack2.h"
#include "status.h"

// create 2 ints and 1 stack
// push ints to stack
// while stack is not empty
//- print top of stack
//- pop from stack
// destroy stack
int main(){
    int a = 10;
    int b = 20;
    Stack *stack = createStack(sizeof(int));
    //check if stack is actually created:
    if(!stack){
        printf("Stack creation failed\n");
        return 1;
    }
    push(stack, &a);
    push(stack, &b);
    while(!isEmpty(stack)){
        int top_val;
        top(stack, &top_val);
        printf("%d\n",top_val);
        pop(stack, &top_val);
    }
    destroyStack(stack);
    return 0;
}