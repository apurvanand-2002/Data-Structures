#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}
int main()
{
    int a = 1, b = 2;
    printf("Values are a=%d and b=%d.\n", a, b);
    swap(&a, &b);
    printf("Values are a=%d and b=%d.\n", a, b);
}