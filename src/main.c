#include <stdio.h>

#include "../include/llistcore.h"


void print_llist(llist* list)
{
    llistnode* node = list->head;
    while(node)
    {
        printf("%d\n", *(int*)node->data);
        node = node->next;
    }
}


int main()
{
    llist list = new_llist(sizeof(int));
    int i = 9;
    int* data;

    llappend(&list, &i);
    i--;
    llappend(&list, &i);
    i--;
    llinsert(&list, &i, 1);

    lldeleteindex(&list, 2);

    print_llist(&list);

    return 0;
}

