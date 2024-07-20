#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/stackcore.h"

#define DEFAULT_MAX_SIZE 2048


Stack init_stack(int STACK_MAX_SIZE)
{
    if(STACK_MAX_SIZE < 0)
    {
        printf("Invalid stack size: %d. Exiting...\n", STACK_MAX_SIZE);
        exit(1);
    }

    Stack new_stack;

    new_stack.MAX_SIZE = STACK_MAX_SIZE
                         ? STACK_MAX_SIZE
                         : DEFAULT_MAX_SIZE;

    new_stack.used_size = 0;
    new_stack.base_pointer = malloc(sizeof(BYTE) * new_stack.MAX_SIZE);

    if(!new_stack.base_pointer)
    {
        printf("Error: Initializing stack failed. Exiting...\n");
        exit(1);
    }

    new_stack.stack_pointer = new_stack.base_pointer;

    return new_stack;
}


int delete_stack(Stack* stack)
{
    if(!stack)
        return 0;

    free(stack->base_pointer);
    return 1;
}


void* spush(Stack* stack, BYTE* data_pointer, int data_length)
{
    int new_size = stack->used_size + data_length;
    
    if(!stack || !data_pointer || new_size > stack->MAX_SIZE)
        return NULL;

    // Copy data to stack.
    for(int i = 0; i < data_length; i++)
    {
        *stack->stack_pointer = *data_pointer;
        stack->stack_pointer++;
        data_pointer++;
    }

    stack->used_size = new_size;

    return NULL;
}


void* spop(Stack* stack, int data_length)
{

    BYTE* data;
    if(!stack || !(data = malloc(sizeof(BYTE)*data_length)))
        return NULL;

    memcpy(data, stack->stack_pointer-data_length, data_length);

    stack->stack_pointer -= data_length;
    stack->used_size -= data_length;

    return data;
}

