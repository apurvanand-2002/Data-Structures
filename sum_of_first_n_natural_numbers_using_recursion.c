#include <stdio.h>
int recursive_sum(int n)
{
    if (n > 0)
    {
        return n + recursive_sum(n - 1);
    }
    return 0;
}
int main()
{
    printf("%d ", recursive_sum(5));
}