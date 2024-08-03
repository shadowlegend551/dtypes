#include <stdio.h>

#include "../include/dtypes.h"
#include "../winclude/wrappers.h"


void print_llist(llist* list)
{
    for(int i = 0; i < list->len; i++)
    {
        printf("%d\n", llgetindex_int(list, i));
    }
}


int main()
{
    llist* list = new_llist_int();
    int i = 9;
    int* data;

    llappend_int(list, i);
    i--;
    llinsert_int(list, i, 1);
    i--;

    printf("%d,%d\n", llgethead_int(list), llgettail_int(list));

    return 0;
}

