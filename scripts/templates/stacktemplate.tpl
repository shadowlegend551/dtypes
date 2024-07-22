#include <stdlib.h>

#include "../include/stackcore.h"
#include "../include/stackwrappers.h"
#include "../include/typesize.h"

###

void* spush<t>(Stack* stack, <t> data)
{
    <t>* dataptr = malloc(<T>_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, <T>_SIZE);
    return 1;
}

###

void* spop<t>(Stack* stack)
{
    return spop(stack, <T>_SIZE);
}
