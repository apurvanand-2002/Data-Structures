#include <stdio.h>
/*
float exponent(float x, float n)
{
    static float p = 1, f = 1;
    static float r = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = exponent(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
}*/
float exponent(float x, float n)
{
    static float p = 1, f = 1;
    float r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = exponent(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
}
int main()
{
    /*Three things are being performed at the same time:
    1. increase in powers of x by multiplication.
    2. increase in factorial
    3. addition of terms.*/
    printf("%f ", exponent(1, 10));
    return 0;
}