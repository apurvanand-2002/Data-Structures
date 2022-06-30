#include <stdio.h>
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("Values are %d and %d.\n", x, y);
}
int main()
{
    int a = 1, b = 2;
    printf("Values are %d and %d.\n", a, b);
    swap(a, b);
    printf("a=%d\n", a);
    printf("b=%d\n", b);
}