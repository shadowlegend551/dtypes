#include <stdlib.h>

#include "../../include/llistcore.h"
#include "../../include/llistwrappers.h"


int llappendint(const llnode* rootnode, int data)
{
    // Copy data to heap so it doesn't go out of scope.
    int* dataptr = malloc(INT_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    llappend(rootnode, dataptr, INT_SIZE);
    return 1;
}

int llappendfloat(const llnode* rootnode, float data)
{
    float* dataptr = malloc(FLOAT_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    llappend(rootnode, dataptr, FLOAT_SIZE);
    return 1;
}

int llappenddouble(const llnode* rootnode, double data)
{
    double* dataptr = malloc(DOUBLE_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    llappend(rootnode, dataptr, DOUBLE_SIZE);
    return 1;
}

int llappendchar(const llnode* rootnode, char data)
{
    char* dataptr = malloc(CHAR_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    llappend(rootnode, dataptr, CHAR_SIZE);
    return 1;
}


/*-----------------------------------------------------┐
|      Getting functions for different datatypes.      |
└-----------------------------------------------------*/

int llgetint(const llnode* rootnode, int i)
{
    return *(int*)llgetatindex(rootnode, INT_SIZE, i);
}

float llgetfloat(const llnode* rootnode, int i)
{
    return *(float*)llgetatindex(rootnode, FLOAT_SIZE, i);
}

double llgetdouble(const llnode* rootnode, int i)
{
    return *(double*)llgetatindex(rootnode, DOUBLE_SIZE, i);
}

char llgetchar(const llnode* rootnode, int i)
{
    return *(char*)llgetatindex(rootnode, CHAR_SIZE, i);
}

