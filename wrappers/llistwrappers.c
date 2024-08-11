// This file was automatically generated.
#include <stdlib.h>
#include "core/llistcore.h"
#include "wrappers/llistwrappers.h"
llist* new_llist_int(void)
{
    return new_llist(sizeof(int));
}
llist* new_llist_char(void)
{
    return new_llist(sizeof(char));
}
llist* new_llist_float(void)
{
    return new_llist(sizeof(float));
}
llist* new_llist_double(void)
{
    return new_llist(sizeof(double));
}
llist* new_llist_ptr(void)
{
    return new_llist(sizeof(void*));
}
int llinsert_int(llist* list, int data, int index)
{
    return llinsert(list, &data, index);
}
int llinsert_char(llist* list, char data, int index)
{
    return llinsert(list, &data, index);
}
int llinsert_float(llist* list, float data, int index)
{
    return llinsert(list, &data, index);
}
int llinsert_double(llist* list, double data, int index)
{
    return llinsert(list, &data, index);
}
int llinsert_ptr(llist* list, void* data, int index)
{
    return llinsert(list, &data, index);
}
int llappend_int(llist* list, int data)
{
    return llappend(list, &data);
}
int llappend_char(llist* list, char data)
{
    return llappend(list, &data);
}
int llappend_float(llist* list, float data)
{
    return llappend(list, &data);
}
int llappend_double(llist* list, double data)
{
    return llappend(list, &data);
}
int llappend_ptr(llist* list, void* data)
{
    return llappend(list, &data);
}
int llgetindex_int(llist* list, int index)
{
    int* new_data_ptr = llgetindex(list, index);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char llgetindex_char(llist* list, int index)
{
    char* new_data_ptr = llgetindex(list, index);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float llgetindex_float(llist* list, int index)
{
    float* new_data_ptr = llgetindex(list, index);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double llgetindex_double(llist* list, int index)
{
    double* new_data_ptr = llgetindex(list, index);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* llgetindex_ptr(llist* list, int index)
{
    void** new_data_ptr = llgetindex(list, index);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
int llgethead_int(llist* list)
{
    int* new_data_ptr = llgethead(list);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char llgethead_char(llist* list)
{
    char* new_data_ptr = llgethead(list);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float llgethead_float(llist* list)
{
    float* new_data_ptr = llgethead(list);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double llgethead_double(llist* list)
{
    double* new_data_ptr = llgethead(list);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* llgethead_ptr(llist* list)
{
    void** new_data_ptr = llgethead(list);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
int llgettail_int(llist* list)
{
    int* new_data_ptr = llgettail(list);
    int new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
char llgettail_char(llist* list)
{
    char* new_data_ptr = llgettail(list);
    char new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
float llgettail_float(llist* list)
{
    float* new_data_ptr = llgettail(list);
    float new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
double llgettail_double(llist* list)
{
    double* new_data_ptr = llgettail(list);
    double new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
void* llgettail_ptr(llist* list)
{
    void** new_data_ptr = llgettail(list);
    void* new_data = *new_data_ptr;
    free(new_data_ptr);
    return new_data;
}
