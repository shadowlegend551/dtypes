stack###
#include <stdlib.h>
#include "core/<n>core.h"
#include "wrappers/<n>wrappers.h"
###
Stack* new_stack_<T>(void)
{
    return new_stack(sizeof(<t>));
}
###
int spush_<T>(Stack* stack, <t> data)
{
    return spush(stack, &data);
}
###
<t> spop_<T>(Stack* stack)
{
    <t>* new_data_ptr = spop(stack);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
###
<t> sgethead_<T>(Stack* stack)
{
    <t>* new_data_ptr = sgethead(stack);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
###
<t> sgettail_<T>(Stack* stack)
{
    <t>* new_data_ptr = sgettail(stack);
    <t> new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
