#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cinclude/llistcore.h"
#include "../include/aux.h"


/* Non-API code. (unaccessible externally) */


typedef struct llistnode llistnode;

typedef struct llistnode
{
    void* data;
    llistnode* next;

} llistnode;


llistnode new_llnode(void* data)
{
    llistnode new_node;
    new_node.data = data;
    new_node.next = NULL;

    return new_node;
}


void deletenodes(llistnode* node)
{
    if(node->next)
    {
        deletenodes(node->next);
    }

    free(node->data);
    free(node);
}


/* API code. (accessible externally) */


llist* new_llist(size_t item_size)
{
    llist* new_llist = malloc(sizeof(llist));
    if(!new_llist) { return NULL; }


    new_llist->item_size = item_size;
    new_llist->len = 0;
    new_llist->head = NULL;
    new_llist->tail = NULL;

    return new_llist;
}


void deletellist(llist* list)
{
    deletenodes(list->head);
    free(list);
}


int llinsert(llist* list, void* data, int index)
{
    if(!list || !data || list->len < index+1) { return 1; }

    void* new_data = copy_data(data, list->len);

    llistnode* new_node = malloc(sizeof(llistnode));

    switch(index)
    {
    case 0:
        new_node->next = list->head;
        list->head = new_node;
        break;

    default:
        llistnode* previous_node = list->head;
        for(int i = 1; i < index; i++)
        {
            previous_node = previous_node->next;
        }

        new_node->next = previous_node->next;
        previous_node->next = new_node;
    }

    new_node->data = new_data;
    list->len++;
    return 0;
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


void* llgetindex(llist* list, int index)
{
    if(list->len < index+1) { return NULL; }
    llistnode* node = list->head;

    int item_size = list->item_size;
    void* data = malloc(item_size);
    if(!data) { return NULL; }
 
    for(int i = 0; i < index; i++)
    {
        node = node->next;
    }

    memcpy(data, node->data, item_size);
    return data;
}


void* llgethead(llist* list)
{
    if(!list || !list->head) { return NULL; }

    size_t item_size = list->item_size;
    void* new_data = malloc(item_size);
    if(!new_data) { return NULL; }
    memcpy(new_data, list->head->data, item_size);

    return new_data;
}


void* llgettail(llist* list)
{
    if(!list || !list->tail) { return NULL; }

    size_t item_size = list->item_size;
    void* new_data = malloc(item_size);
    if(!new_data) { return NULL; }
    memcpy(new_data, list->tail->data, item_size);

    return new_data;
}


int lldeleteindex(llist* list, int index)
{
    if(list->len < index+1) { return 1; }
    llistnode* node = list->head;

    switch(index)
    {
    case 0:
        list->head = node->next;
        free(node);
        break;

    default:
        // Find the node before the node to delete.
        for(int i = 0; i < index-1; i++)
        {
            node = node->next;
        }
        llistnode* node_to_delete = node->next;
        node->next = node_to_delete->next;
        free(node_to_delete->data);
        free(node_to_delete);

        // If the last cell was deleted, change list->tail.
        if(list->len == index+1)
        {
            list->tail = node;
        }
    }

    list->len--;

    return 0;
}


int lllen(llist* list)
{
    return list->len;
}


llist* llconcat(llist* list1, llist* list2)
{
    if(!list1 || !list2) { return NULL; }

    llist* new_list = new_llist(list1->item_size);
    if(!new_list) { return NULL; }

    // Copy first list to new list.
    new_list->head = list1->head;
    new_list->tail = list1->tail;

    // Tie together new lists last index to second lists first.
    new_list->tail->next = list2->head;
    new_list->tail = list2->tail;

    new_list->len = list1->len + list2->len;

    return new_list;

}

