#ifndef LLISTCORE_H
#define LLISTCORE_H

#include "typesize.h"

typedef struct llistnode llistnode;

typedef struct llistnode
{
    void* data;
    llistnode* next;

} llistnode;

typedef struct llist
{
    size_t item_size;

    int len;
    llistnode* head;
    llistnode* tail;

} llist;

llist new_llist(size_t item_size);

int lllen(llist* list);

void* llgetindex(llist* list, int index);

void deletellist(llist* list);

int llappend(llist* list, void* data);

#endif

