#include <stdio.h>
int factorial(int n)
{
    int prod = 1;
    for (int i = 1; i <= n; i++)
    {
        prod = prod * i;
    }
    return prod;
}
int main()
{
    printf("%d ", factorial(5));
}