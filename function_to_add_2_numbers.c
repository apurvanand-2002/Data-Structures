#include <stdio.h>
int adding(int x, int y)
{
    int sum;
    sum = x + y;
    return sum;
}
int main()
{
    int a, b;
    printf("Enter values of a and b respectively:\n");
    scanf("%d %d", &a, &b);
    printf("Sum of entered numbers is %d.", adding(a, b));
}