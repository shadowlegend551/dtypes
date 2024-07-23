#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/llistcore.h"


llnode* init_llnode(void* dataptr, size_t datalen)
{
    llnode* nodeptr = malloc(sizeof(llnode));
    if(!nodeptr) { return NULL; }

    nodeptr->dataptr = dataptr;

    nodeptr->datalen = datalen;
    nodeptr->next = NULL;
    return nodeptr;
}


llist* init_llist(void)
{
    llist* new_llist = malloc(sizeof(llist));
    if(!new_llist) { return NULL; }

    new_llist->len = 0;
    new_llist->head = NULL;
    new_llist->tail = NULL;

    return new_llist;
}


int lllen(llist* list)
{
    return list->len;
}


llnode* llnodeatindex(llist* list, int i)
{
    llnode* node = list->head;
    for(;i > 0; i--)
    {
        // Index error.
        if(!node) { return NULL; }
        node = node->next;
    }

    return node;
}


void* llgetpointeratindex(llist* list, int index)
{
    if(index+1>list->len) { return NULL; }
    llnode* node = list->head;

    for(int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node->dataptr;
}


void deletenodes(llnode* node)
{
    if(node->next)
    {
        deletenodes(node->next);
    }

    free(node);
}


void deletellist(llist* list)
{
    deletenodes(list->head);
    free(list);
}


int llappend(llist* list, void* dataptr, size_t datasize)
{
    if(!dataptr) { return 1; }

    void* data = malloc(datasize);
    memcpy(data, dataptr, datasize);
    llnode* new_node = init_llnode(data, datasize);
    switch(list->len)
    {
    // Empty list.
    case 0:
        list->tail = new_node;
        list->head = new_node;
        break; 

    // Non-empty list.
    default:
        (list->tail)->next = new_node;
        list->tail = new_node;
        break;
    }

    list->len++;
    return 0;
}

