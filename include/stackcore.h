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

Stack* new_stack(size_t item_size);

void deletestack(Stack* stack);

#endif
