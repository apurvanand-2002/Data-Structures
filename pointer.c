#include <stdio.h>
int main()
{
    int a = 100;
    int *p;
    p = &a;
    printf("Value of a is %d.\n", (*(p)));
    printf("Address of a is %d.\n", p);
    printf("Address of a is %d.\n", &a);
}