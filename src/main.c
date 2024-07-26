#include <stdio.h>

#include "../include/llistcore.h"


int main()
{
    llist list = new_llist(sizeof(int));
    int i = 9;
    int* data;

    llappend(&list, &i);
    i--;
    llappend(&list, &i);
    i--;
    llappend(&list, &i);

    data = llgetindex(&list, 0);
    printf("%d\n", *data);

    data = llgetindex(&list, 1);
    printf("%d\n", *data);

    data = llgetindex(&list, 2);
    printf("%d\n", *data);

    return 0;
}

