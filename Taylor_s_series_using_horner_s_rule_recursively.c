#include <stdio.h>
float exponent(float x, float n)
{
    static float s = 1;
    if (n > 0)
    {
        s = 1 + (x / n) * s;
        exponent(x, n - 1);
    }
    else if (n == 0)
    {
        return 1;
    }

    return s;
}
int main()
{
    printf("%f ", exponent(4, 15));
}