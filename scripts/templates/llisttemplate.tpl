#include <stdlib.h>
#include "../include/llistcore.h"
#include "../include//llistwrappers.h"
###
int llappend<t>(const llnode* rootnode, <t> data)
{
    <t>* dataptr = malloc(<T>_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    llappend(rootnode, dataptr, <T>_SIZE);
    return 1;
}
###
<t> llget<t>(const llnode* rootnode, int i)
{
    return *(<t>*)llgetatindex(rootnode, <T>_SIZE, i);
}
