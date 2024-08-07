#include <stdlib.h>
#include <string.h>

#include "../include/aux.h"


void* copy_data(void* data, size_t item_size)
{
    void* new_data = malloc(item_size);
    if(!new_data) { return NULL; }
    memcpy(new_data, data, item_size);

    return new_data;
}

