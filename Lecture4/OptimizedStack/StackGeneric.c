#include <stdio.h>
#include <stdlib.h>


#include "StackGeneric.h"
#include "status.h"

// we assume that there is a static Box pointer called available
static Box * available = 0;

Stack *createStack()
{
    Stack* res=(Stack*)malloc(sizeof(Stack));
    if(!res)
        return 0;
    *res = 0;
    return res;
}
// Check if the stack is empty
int isEmpty(Stack *stack)
{
    return *stack == 0;
}
// Add an element to the top of the stack
// modifying the return type to return an error message
status_t push(Stack *stack, void * data)
{
    Box *newBox= available;
    if(!newBox){
        newBox = (Box*)malloc(sizeof(Box));
        if(!newBox)
            return ERR_ALLOC_FAIL;
    }
    else{
        available = newBox->next;
    }
    if(!newBox)
        return ERR_ALLOC_FAIL;
    newBox->value = data;
    newBox->next = *stack;
    *stack = newBox;
    return SUCCESS;
}
// Remove the top element of the stack
// modifying the return type to return an error message
status_t pop(Stack *stack)
{
    //Stack temp = *stack;// Box *temp = *stack;
    Box *temp ;
    if(!*stack)
        return ERR_EMPTY;

    temp=(*stack)->next;
    (*stack)->next = available;
    available = *stack;
    *stack = temp;
    return SUCCESS;

}
// Return the top element of the stack
// modifying the return type to return an error message
status_t top(Stack *stack, void *data)
{
    if(isEmpty(stack))
        return ERR_EMPTY ;
    else{
        *(void**)data = (*stack)->value;
        return SUCCESS;
    }
}
// Free the memory allocated for the stack and the data
void destroyStack(Stack *stack)
{
    // free the memory allocated for the data
    // 1st method
    while(!isEmpty(stack))
    {
        pop(stack);
    }
    free(*stack);

    // 2nd method
    /*
    while(*s){
        Box *temp = *s;
        *s = temp->next;
        free(temp);
    }
    */

}
