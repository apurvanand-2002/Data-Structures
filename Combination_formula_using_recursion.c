#include <stdio.h>
float ncr(float n, float r)
{
    if (n >= r)
    {
        if (r == 0)
        {
            return 1;
        }
        else
        {
            return (n / r) * ncr(n - 1, r - 1);
        }
    }
    return -1;
}
int main()
{
    printf("%f ", ncr(0, 2));
}