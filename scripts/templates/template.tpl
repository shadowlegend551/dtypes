type###
#include <stdio.h>
#include <<n>core.h>
###

<t> printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}



###     


void print<T>hello(void)
{
    printf("Hello <t>!");
}



