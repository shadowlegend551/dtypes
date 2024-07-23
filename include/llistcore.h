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

int lllen(const llnode* rootnode);

llnode* llnodeatindex(const llnode* rootnode, int i);

void* llgetatindex(const llnode* rootnode, size_t datasize, int index);

int llappend(llnode* rootnode, const void* dataptr, const size_t datasize);

#endif

