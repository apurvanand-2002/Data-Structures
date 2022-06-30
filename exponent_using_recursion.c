#include <stdio.h>
float exponent(float n, float p)
{
    if (p > 0)
    {
        return n * exponent(n, p - 1);
    }
    else if (p == 0)
    {
        return 1;
    }
    else if (p < 0)
    {
        return exponent(1 / n, -p);
    }
}
int main()
{
    printf("%f ", exponent(3, -3));
}