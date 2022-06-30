#include <stdio.h>
int fibonacci(int n)
{
    int F[10];
    for (int i = 0; i < 10; i++)
    {
        F[i] = (-1);
    }
    if (n == 0)
    {
        F[0] = 0;
        return F[0];
    }
    else if (n == 1)
    {
        F[1] = 1;
        return F[1];
    }
    else
    {
        if (F[n - 1] == (-1))
        {
            F[n - 1] = fibonacci(n - 1);
        }
        if (F[n - 2] == (-1))
        {
            F[n - 2] = fibonacci(n - 2);
        }
        return F[n - 1] + F[n - 2];
    }
}
int main()
{
    printf("%d ", fibonacci(5));
}