#ifndef STACK_H
#define STACK_H

#include <stdint.h>


typedef uint8_t BYTE;

typedef struct Stack
{
    int MAX_SIZE;
    int used_size;

    // Points to the bottom of the stack.
    BYTE* base_pointer;

    // Points to the top of the stack.
    BYTE* stack_pointer;

} Stack;

// Initializes a stack struct with stack size STACK_MAX_SIZE.
// Default size is used if 0 is entered.
Stack init_stack(int STACK_MAX_SIZE);

// Deletes base_pointer.
int delete_stack(Stack* stack);

// Pushes data_length bytes from pointer data on to stack.
void* spush(Stack* stack, BYTE* data, int data_length);

// Pops data_length bytes from top of stack.
void* spop(Stack* stack, int data_length);

#endif

