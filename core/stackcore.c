#include <stdlib.h>

#include "../include/stackcore.h"


/* Non-API code. */
typedef struct stacknode
{
    void* data;
    stacknode* previous;

} stacknode;

