#include <stdio.h>
int fibonacci_series(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    /*else if (n == 3)
    {
        return 1;
    }*/
    else
    {
        return fibonacci_series(n - 1) + fibonacci_series(n - 2);
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
    printer(5);
}