#include <stdlib.h>

#include "../include/stackcore.h"


/* Non-API code. */
typedef struct stacknode
{
    void* data;
    stacknode* previous;

} stacknode;

Stack* new_stack(size_t item_size)
{
    Stack* new_stack = malloc(sizeof(Stack));
    if(!new_stack) { return NULL; }


    new_stack->item_size = item_size;
    new_stack->len = 0;
    new_stack->base = NULL;
    new_stack->top = NULL;

    return new_stack;
}

