#include "Stack2.h"
#include <stdlib.h>
#include <string.h>
#include "status.h"


Stack* createStack(int elementSize){
    Stack *res = (Stack *)malloc(sizeof(Stack));
    if(!res)
        return 0;
    res->top = NULL;
    res->eltSize = elementSize;
    res->available = NULL;
    return res;
}

int isEmpty(Stack *stack){
    return stack->top == NULL;
}

status_t push(Stack *stack, void *data){
    
    //step 1: point to temporary box
    Box *box = stack->available;
    if(!box){
        box = (Box *)malloc(sizeof(Box) + stack->eltSize - 1);
        if(!box)
            return ERR_ALLOC_FAIL;
    }else{
        stack->available = box->next;
    }
    //step 2: link temp box to the top of the stack
    box->next = stack->top;
    //step 3: change the top of the stack to the temp box
    stack->top = box;
    //step 4: copy the data to the temp box;
    memcpy(box->value, data, stack->eltSize);

    return SUCCESS;
}

// status_t pop(Stack *stack){
//     if(isEmpty(stack))
//         return ERR_EMPTY;
//     //step 1: point to the top box
//     Box *box = stack->top;
//     //step 2: change the top of the stack to the next box
//     stack->top = box->next;
//     //step 3: link the box to the available list
//     box->next = stack->available;
//     stack->available = box;
//     // //step 4: free the box // not required because it's not being malloced.
//     // free(box);
//     return SUCCESS;
// }

status_t pop(Stack *stack,void *res){
    //step1: check if stack is not empty first.
    if(!stack->top)
    //step2:
    memcpy(res,stack->top->value,stack->eltSize);
    //
    return SUCCESS;
}

void destroyStack(Stack *stack){
    Box * temp = stack->top;
    while(temp){
        stack->top = temp->next;
        free(temp);
        temp = stack->top;
    }
    temp = stack->available;
    while(temp){
        stack->available = temp->next;
        free(temp);
        temp = stack->available;
    }
    free(stack);
}



