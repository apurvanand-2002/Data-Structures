#include <stdio.h>
float exponent(float x, float n)
{
    static float s = 1;
    for (; n > 0; n--)
    {
        s = 1 + (x / n) * s;
    }
    return s;
}
int main()
{
    printf("%f ", exponent(4, 15));
}