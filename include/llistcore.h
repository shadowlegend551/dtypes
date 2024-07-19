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

llnode* init_llnode(const void* const dataptr, const size_t datalen);

int llistlen(const llnode* rootnode);

llnode* llnodeatindex(const llnode* rootnode, int i);

void* llgetatindex(const llnode* rootnode, size_t datasize, int index);

int llappend(llnode* rootnode, const void* dataptr, const size_t datasize);

#endif

