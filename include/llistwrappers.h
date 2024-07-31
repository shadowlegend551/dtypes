// This file was automatically generated.

#ifndef LLIST_WRAPPERS_H
#define LLIST_WRAPPERS_H
llist* new_llist_int(void);
llist* new_llist_char(void);
llist* new_llist_float(void);
llist* new_llist_double(void);
llist* new_llist_ptr(void);
int llinsert_int(llist* list, int data, int index);
int llinsert_char(llist* list, char data, int index);
int llinsert_float(llist* list, float data, int index);
int llinsert_double(llist* list, double data, int index);
int llinsert_ptr(llist* list, void* data, int index);
int llappend_int(llist* list, int data);
int llappend_char(llist* list, char data);
int llappend_float(llist* list, float data);
int llappend_double(llist* list, double data);
int llappend_ptr(llist* list, void* data);
int llgetindex_int(llist* list, int index);
char llgetindex_char(llist* list, int index);
float llgetindex_float(llist* list, int index);
double llgetindex_double(llist* list, int index);
void* llgetindex_ptr(llist* list, int index);
int llgethead_int(llist* list);
char llgethead_char(llist* list);
float llgethead_float(llist* list);
double llgethead_double(llist* list);
void* llgethead_ptr(llist* list);
int llgettail_int(llist* list);
char llgettail_char(llist* list);
float llgettail_float(llist* list);
double llgettail_double(llist* list);
void* llgettail_ptr(llist* list);
#endif