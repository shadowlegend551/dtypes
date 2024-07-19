#include <stdio.h>
#include <stdlib.h>

#include "../include/llistcore.h"


llnode* init_llnode(const void* const dataptr, const size_t datalen)
{
    llnode* nodeptr = malloc(sizeof(llnode));
    if(!nodeptr) { return NULL; }

    nodeptr->dataptr = dataptr;
    nodeptr->datalen = datalen;
    nodeptr->next = NULL;

    return nodeptr;
}


int llistlen(const llnode* rootnode)
{
    // Length is 0 if list doesn't exist;
    if(!rootnode) { return 0; }

    int len = 0;

    while(rootnode->next)
    {
        len++;
        rootnode = rootnode->next;
    }
    len++;  // Add last index with next = NULL to length.

    return len;
}


llnode* llnodeatindex(const llnode* rootnode, int i)
{
    for(;i > 0; i--)
    {
        // Index error.
        if(!rootnode) { return NULL; }
        rootnode = rootnode->next;
    }

    return rootnode;
}


void* llgetatindex(const llnode* rootnode, size_t datasize, int index)
{
    if(index+1 > llistlen(rootnode))
    {
        fprintf(stderr,
                "Index error: Index %d of linked list out of bounds.\n",
                index);
        exit(1);
    }

    for(int i = index; i > 0; i--)
    {
        rootnode = rootnode->next;
    }

    return rootnode->dataptr;
}


void llistdelete(llnode* rootnode)
{
    if (rootnode->next) {
        llistdelete(rootnode->next);
        rootnode->next = NULL;
    }
    free(rootnode);

}


int llappend(llnode* rootnode, const void* dataptr, const size_t datasize)
{
    while(rootnode->next) { rootnode = rootnode->next; }

    rootnode->next = init_llnode(dataptr, datasize);
    return rootnode->next ? 1 : 0;
}

