#ifndef LLISTCORE_H
#define LLISTCORE_H

#include "typesize.h"

typedef struct llistnode llistnode;

typedef struct llist
{
    size_t item_size;

    int len;
    llistnode* head;
    llistnode* tail;

} llist;


// Returns a new empty linked list.
llist new_llist(size_t item_size);

// Deletes a linked list along with its nodes.
void deletellist(llist* list);

// Inserts a new node to a linked list. Insertion cannot be done to last index.
int llinsert(llist* list, void* data, int index);

// Appends a new node to a linked list.
int llappend(llist* list, void* data);

// Gets the data at index from a linked list.
void* llgetindex(llist* list, int index);

// Gets the data from first node of a linked list.
void* llgethead(llist* list);

// Gets the data from last node of a linked list.
void* llgettail(llist* llist);

// Deletes a node at an index.
int lldeleteindex(llist* list, int index);

// Returns the length of a linked list.
int lllen(llist* list);

#endif

