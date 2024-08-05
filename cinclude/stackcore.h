#ifndef STACKCORE_H
#define STACKCORE_H

typedef struct stacknode stacknode;

typedef struct stack
{
    size_t item_size;

    int len;
    stacknode* base;
    stacknode* top;

} stack;

stack* new_stack(size_t item_size);

#endif
