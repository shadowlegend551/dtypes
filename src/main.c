#include <stdio.h>

#include "../include/llistcore.h"


void print_llist(llist* list)
{
    printf("%d\n", lllen(list));
    for(int i = 0; i < list->len; i++)
    {
        printf("%d\n", *(int*)llgetindex(list, i));
    }
}


int main()
{
    llistnode* node;
    llist* list = new_llist(sizeof(int));
    int i = 9;
    int* data;

    llappend(list, &i);
    i--;
    llappend(list, &i);
    i--;
    llinsert(list, &i, 1);

    lldeleteindex(list, 2);

    print_llist(list);

    data = llgethead(list);
    printf("%d\n", *data);
    data = llgettail(list);
    printf("%d\n", *data);


    return 0;
}

