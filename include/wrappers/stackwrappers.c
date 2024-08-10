// This file was automatically generated.

#include <stdlib.h>
#include "../include/stackcore.h"
#include "../winclude/stackwrappers.h"
Stack* new_stack_int(void)
{
    return new_stack(sizeof(int));
}
Stack* new_stack_char(void)
{
    return new_stack(sizeof(char));
}
Stack* new_stack_float(void)
{
    return new_stack(sizeof(float));
}
Stack* new_stack_double(void)
{
    return new_stack(sizeof(double));
}
Stack* new_stack_ptr(void)
{
    return new_stack(sizeof(void*));
}
int spush_int(Stack* stack, int data)
{
    return spush(stack, &data);
}
int spush_char(Stack* stack, char data)
{
    return spush(stack, &data);
}
int spush_float(Stack* stack, float data)
{
    return spush(stack, &data);
}
int spush_double(Stack* stack, double data)
{
    return spush(stack, &data);
}
int spush_ptr(Stack* stack, void* data)
{
    return spush(stack, &data);
}
int spop_int(Stack* stack)
{
    int* new_data_ptr = spop(stack);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char spop_char(Stack* stack)
{
    char* new_data_ptr = spop(stack);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float spop_float(Stack* stack)
{
    float* new_data_ptr = spop(stack);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double spop_double(Stack* stack)
{
    double* new_data_ptr = spop(stack);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* spop_ptr(Stack* stack)
{
    void** new_data_ptr = spop(stack);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
int sgethead_int(Stack* stack)
{
    int* new_data_ptr = sgethead(stack);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char sgethead_char(Stack* stack)
{
    char* new_data_ptr = sgethead(stack);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float sgethead_float(Stack* stack)
{
    float* new_data_ptr = sgethead(stack);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double sgethead_double(Stack* stack)
{
    double* new_data_ptr = sgethead(stack);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* sgethead_ptr(Stack* stack)
{
    void** new_data_ptr = sgethead(stack);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
int sgettail_int(Stack* stack)
{
    int* new_data_ptr = sgettail(stack);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char sgettail_char(Stack* stack)
{
    char* new_data_ptr = sgettail(stack);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float sgettail_float(Stack* stack)
{
    float* new_data_ptr = sgettail(stack);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double sgettail_double(Stack* stack)
{
    double* new_data_ptr = sgettail(stack);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* sgettail_ptr(Stack* stack)
{
    void** new_data_ptr = sgettail(stack);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
