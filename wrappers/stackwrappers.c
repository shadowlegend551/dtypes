// This file was automatically generated.

#include <stdlib.h>

#include "../include/stackcore.h"
#include "../include/stackwrappers.h"
#include "../include/typesize.h"
void* spushint(Stack* stack, int data)
{
    int* dataptr = malloc(INT_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, INT_SIZE);
    return 1;
}
void* spushchar(Stack* stack, char data)
{
    char* dataptr = malloc(CHAR_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, CHAR_SIZE);
    return 1;
}
void* spushfloat(Stack* stack, float data)
{
    float* dataptr = malloc(FLOAT_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, FLOAT_SIZE);
    return 1;
}
void* spushdouble(Stack* stack, double data)
{
    double* dataptr = malloc(DOUBLE_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, DOUBLE_SIZE);
    return 1;
}
void* spushptr(Stack* stack, void* data)
{
    void** dataptr = malloc(PTR_SIZE);
    if(!dataptr) { return 0; }
    *dataptr = data;

    spush(stack, dataptr, PTR_SIZE);
    return 1;
}
void* spopint(Stack* stack)
{
    return spop(stack, INT_SIZE);
}
void* spopchar(Stack* stack)
{
    return spop(stack, CHAR_SIZE);
}
void* spopfloat(Stack* stack)
{
    return spop(stack, FLOAT_SIZE);
}
void* spopdouble(Stack* stack)
{
    return spop(stack, DOUBLE_SIZE);
}
void* spopptr(Stack* stack)
{
    return spop(stack, PTR_SIZE);
}
