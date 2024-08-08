#include <stdlib.h>

#include "../include/aux.h"
#include "../include/stackcore.h"


/* Non-API code. */


typedef struct stacknode
{
    void* data;
    stacknode* previous;

} stacknode;


stacknode* new_stacknode(void* data)
{
    stacknode* new_node = malloc(sizeof(stacknode));

    new_node->data = NULL;
    new_node->previous = NULL;

    return new_node;
}


void delete_stacknode(stacknode* node)
{
    if(node->previous)
    {
        delete_stacknode(node->previous);
    }
    free(node->data);
    free(node);
}


/* API code. */


Stack* new_stack(size_t item_size)
{
    Stack* new_stack = malloc(sizeof(Stack));
    if(!new_stack) { return NULL; }


    new_stack->item_size = item_size;
    new_stack->len = 0;
    new_stack->head = NULL;
    new_stack->tail = NULL;

    return new_stack;
}


void deletestack(Stack* stack)
{
    delete_stacknode(stack->tail);

    free(stack);
}


int spush(Stack* stack, void* data)
{
    if(!stack || !data) { return 1; }

    void* new_data = copy_data(data, stack->item_size);

    stacknode* new_node = new_stacknode(new_data);
    if(!new_node) { free(new_data); return 1; }
    new_node->data = new_data;

    switch(stack->len)
    {
    case 0:
        stack->head = new_node;
        break;

    default:
        new_node->previous = stack->tail;
        break;
    }

    stack->tail = new_node;

    stack->len++;
    return 0;
}


void* spop(Stack* stack)
{
    if(!stack || stack->len == 0) { return NULL; }

    stacknode* popped_node = stack->tail;
    stack->tail = popped_node->previous;


    void* new_data = copy_data(popped_node->data, sizeof(stack->item_size));
    if(!new_data) { return NULL; }
    free(popped_node->data); free(popped_node);

    stack->len--;
    return new_data;
}



void* sgethead(Stack* stack)
{
    void* data = copy_data(stack->head->data, stack->item_size);
    return data ? data : NULL;
}


void* sgettail(Stack* stack)
{
    void* data = copy_data(stack->tail->data, stack->item_size);
    return data ? data : NULL;
}

