// This file was automatically generated.

#ifndef STACK_WRAPPERS_H
#define STACK_WRAPPERS_H
Stack* new_stack_int(void);
Stack* new_stack_char(void);
Stack* new_stack_float(void);
Stack* new_stack_double(void);
Stack* new_stack_ptr(void);
int spush_int(Stack* stack, int data);
int spush_char(Stack* stack, char data);
int spush_float(Stack* stack, float data);
int spush_double(Stack* stack, double data);
int spush_ptr(Stack* stack, void* data);
int spop_int(Stack* stack);
char spop_char(Stack* stack);
float spop_float(Stack* stack);
double spop_double(Stack* stack);
void* spop_ptr(Stack* stack);
int sgethead_int(Stack* stack);
char sgethead_char(Stack* stack);
float sgethead_float(Stack* stack);
double sgethead_double(Stack* stack);
void* sgethead_ptr(Stack* stack);
int sgettail_int(Stack* stack);
char sgettail_char(Stack* stack);
float sgettail_float(Stack* stack);
double sgettail_double(Stack* stack);
void* sgettail_ptr(Stack* stack);
#endif
