#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/llistcore.h"


llistnode new_llnode(void* data)
{
    llistnode new_node;
    new_node.data = data;
    new_node.next = NULL;

    return new_node;
}


llist new_llist(size_t item_size)
{
    llist new_llist;

    new_llist.item_size = item_size;
    new_llist.len = 0;
    new_llist.head = NULL;
    new_llist.tail = NULL;

    return new_llist;
}


int lllen(llist* list)
{
    return list->len;
}


void* llgetindex(llist* list, int index)
{
    if(index+1 > list->len) { return NULL; }
    llistnode* node = list->head;

    for(int i = 0; i < index; i++)
    {
        node = node->next;
    }

    int item_size = list->item_size;
    void* data = malloc(item_size);
    if(!data) { return NULL; }
    memcpy(data, node->data, item_size);

    return data;
}


void deletenodes(llistnode* node)
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


int llappend(llist* list, void* data)
{
    if(!list || !data) { return 1; }
    size_t item_size = list->item_size;

    void* new_data = malloc(item_size);
    if(!new_data) { return 1; }
    memcpy(new_data, data, item_size);

    llistnode* new_node = malloc(sizeof(llistnode));
    if(!new_node) {free(new_data); return 1; }
    *new_node = new_llnode(new_data);

    switch(list->len)
    {
    case 0:
        list->head = new_node;
        break;

    default:
        list->tail->next = new_node;
        break;
    }
    list->tail = new_node;

    list->len++;
    return 0;

}

