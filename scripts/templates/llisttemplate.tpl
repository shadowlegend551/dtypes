#include <stdlib.h>
#include "../include/llistcore.h"
#include "../include/llistwrappers.h"
###
llist* new_llist_<T>(void)
{
    return new_llist(sizeof(<t>));
}
###
int llinsert_<T>(llist* list, <t> data, int index)
{
    return llinsert(list, &data, index);
}
###


int llappend_<T>(llist* list, <t> data)
{
    return llappend(list, &data);
}


###
<t> llgetindex_<T>(llist* list, int index)
{
    <t>* new_data_ptr = llgetindex(list, index);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
###
<t> llgethead_<T>(llist* list)
{
    <t>* new_data_ptr = llgethead(list);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
###
<t> llgettail_<T>(llist* list)
{
    <t>* new_data_ptr = llgettail(list);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
