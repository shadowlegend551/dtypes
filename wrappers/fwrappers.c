#include <stdio.h>

int printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}
char printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}
float printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}
double printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}
ptr printhello(char* target)
{
    printf("Hello %s!", target);

    return 1;
}
void printinthello(void)
{
    printf("Hello int!");
}
void printcharhello(void)
{
    printf("Hello char!");
}
void printfloathello(void)
{
    printf("Hello float!");
}
void printdoublehello(void)
{
    printf("Hello double!");
}
void printptrhello(void)
{
    printf("Hello ptr!");
}