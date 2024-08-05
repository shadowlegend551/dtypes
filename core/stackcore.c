#include <stdlib.h>

#include "../cinclude/stackcore.h"


/* Non-API code. (unaccessible externally) */


typedef struct stacknode
{
    void* data;
    stacknode* previous;

} stacknode;


/* API code. (accessible externally) */


stack* new_stack(size_t item_size)
{
    stack* new_stack = malloc(sizeof(stack));
    if(!new_stack) { return NULL; }

    new_stack->item_size = item_size;
    new_stack->len = 0;
    new_stack->base = NULL;
    new_stack->head = NULL;

    return new_stack;
}

