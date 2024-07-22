// This file was automatically generated.

#ifndef STACK_WRAPPERS_H
#define STACK_WRAPPERS_H
void* spushint(Stack* stack, int data);
void* spushchar(Stack* stack, char data);
void* spushfloat(Stack* stack, float data);
void* spushdouble(Stack* stack, double data);
void* spushptr(Stack* stack, void* data);
void* spopint(Stack* stack);
void* spopchar(Stack* stack);
void* spopfloat(Stack* stack);
void* spopdouble(Stack* stack);
void* spopptr(Stack* stack);
#endif
