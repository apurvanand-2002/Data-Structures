#include <stdio.h>
int z = 0;
int fun(int a)
{
    if (a > 0)
    {
        z++;
        return fun(a - 1) + z;
    }
    return 0;
}

int main()
{
    printf("%d ", fun(5));
}