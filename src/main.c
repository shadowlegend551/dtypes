#include <stdio.h>

#include "../include/llistcore.h"


void print_llist(llist* list)
{
    for(int i = 0; i < list->len; i++)
    {
        printf("%d\n", *(int*)llgetindex(list, i));
    }
}


int main()
{
    llist* list = new_llist(sizeof(int));
    int i = 9;
    int* data;

    llappend(list, &i);
    i--;
    llappend(list, &i);
    i--;
    llappend(list, &i);

    print_llist(list);

    llist* list2 = new_llist(sizeof(int));
    int i2 = 6;
    int* data2;

    llappend(list2, &i2);
    i2--;
    llappend(list2, &i2);
    i2--;
    llappend(list2, &i2);

    print_llist(list2);

    llist* list3 = llconcat(list, list2);
    print_llist(list3);

    return 0;
}

