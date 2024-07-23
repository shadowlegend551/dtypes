#ifndef LLISTCORE_H
#define LLISTCORE_H

#include "typesize.h"

typedef struct llnode llnode;

typedef struct llnode
{
    void* dataptr;
    size_t datalen;

    llnode* next;

} llnode;

typedef struct llist
{
    int len;
    llnode* head;
    llnode* tail;
} llist;

llnode* init_llnode(void* dataptr, size_t datalen);

llist* init_llist(void);

int lllen(llist* list);

llnode* llnodeatindex(llist* list, int i);

void* llgetpointeratindex(llist* list, int index);

void deletellist(llist* list);

int llappend(llist* list, void* dataptr, size_t datasize);

#endif

