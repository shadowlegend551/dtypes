#ifndef LLIST_H
#define LLIST_H

// llappend versions for primitive datatypes.
int llappendint(const llnode* rootnode, int data);
int llappendfloat(const llnode* rootnode, float data);
int llappenddouble(const llnode* rootnode, double data);
int llappendchar(const llnode* rootnode, char data);


// Returns data stored at index i in linked list.
int llgetint(const llnode* rootnode, int i);
float llgetfloat(const llnode* rootnode, int i);
double llgetdouble(const llnode* rootnode, int i);
char llgetchar(const llnode* rootnode, int i);

#endif

