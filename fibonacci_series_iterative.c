#include <stdio.h>
int fibonacci_series(int n)
{
    int a = 0, b = 1;
    int c = a + b;
    if (n == 1)
    {
        return a;
    }
    else if (n == 2)
    {
        return b;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return b;
    }
}

void printer(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", fibonacci_series(i));
    }
}
int main()
{
    printer(20);
}