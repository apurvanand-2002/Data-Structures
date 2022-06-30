#include <stdio.h>
int ncr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
}
int main()
{
    printf("%d ", ncr(4, 2));
}