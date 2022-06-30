#include <stdio.h>
float exponent(float n, float p)
{
    float prod = n;
    if (p >= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            prod = prod * n;
        }
    }
    else if (p == 0)
    {
        return 1;
    }
    else if (p < 0)
    {
        float grod = (1 / prod);
        for (int i = 1; i < (-p); i++)
        {
            grod = grod * (1 / n);
        }
        return grod;
    }
    return prod;
}
int main()
{
    printf("%f ", exponent(2, -3));
}