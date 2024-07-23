#include <stdio.h>

#include "../include/llistcore.h"


int main()
{
    llist* list = init_llist();
    int i = 9;
    int* data;

    llappend(list, &i, sizeof(int));
    i--;
    llappend(list, &i, sizeof(int));
    i--;
    llappend(list, &i, sizeof(int));

    data = llgetpointeratindex(list, 0);
    printf("%d\n", *data);
    data = llgetpointeratindex(list, 1);
    printf("%d\n", *data);
    data = llgetpointeratindex(list, 2);
    printf("%d\n", *data);
    llnode* node = llnodeatindex(list, 2);
    printf("%d\n", *(int*)(node->dataptr));


    return 0;
}

