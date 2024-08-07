#ifndef STACKCORE_H
#define STACKCORE_H

typedef struct stacknode stacknode;

typedef struct Stack
{
    size_t item_size;

    int len;
    stacknode* base;
    stacknode* top;

} Stack;

// Returns a pointer to a new stack.
Stack* new_stack(size_t item_size);

// Deletes a stack along with it's data.
void deletestack(Stack* stack);

// Pushes data on top of stack.
int spush(Stack* stack, void* data);

// Returns the top of stack and removes it from stack.
void* spop(Stack* stack);

// Returns the topmost data from stack without deleting it.
void* sgettop(Stack* stack);

// Gets the bottommost data.
void* sgetbase(Stack* stack);

// Returns the length (height) of a stack.
int sgetlen(Stack* stack);

#endif
