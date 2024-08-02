#ifndef STACKCORE_H
#define STACKCORE_H

typedef struct stacknode stacknode;

typedef struct stack
{
    size_t item_size;

    stacknode* base;
    stacknode* head;
}

#endif
