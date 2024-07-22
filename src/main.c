#include <stdio.h>

#include "../include/llistcore.h"
#include "../include/llistwrappers.h"


int main()
{
    int i = 9;
    llnode* list = init_llnode(&i, sizeof(int));
    i = 8;
    llappendint(list, i);
    i = 7;
    llappendint(list, i);
    printf("%d, %d, %d", llgetint(list, 0), llgetint(list, 1), llgetint(list, 2));
    return 0;
}

