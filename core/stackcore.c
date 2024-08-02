#include <stdlib.h>

#include "../cinclude/stackcore.h"


/* Non-API code. */
typedef struct stacknode
{
    void* data;
    stacknode* previous;

} stacknode;

