// This file was automatically generated.

#ifndef LLIST_WRAPPERS_H
#define LLIST_WRAPPERS_H
int llappendint(const llnode* rootnode, int data);
int llappendchar(const llnode* rootnode, char data);
int llappendfloat(const llnode* rootnode, float data);
int llappenddouble(const llnode* rootnode, double data);
int llappendptr(const llnode* rootnode, void* data);
int llgetint(const llnode* rootnode, int i);
char llgetchar(const llnode* rootnode, int i);
float llgetfloat(const llnode* rootnode, int i);
double llgetdouble(const llnode* rootnode, int i);
void* llgetptr(const llnode* rootnode, int i);
#endif
