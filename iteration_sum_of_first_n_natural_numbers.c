#include <stdio.h>
int sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}
int formula_sum(int n)
{
    return ((n * (n + 1)) / 2);
}
int main()
{
    printf("Sum= %d\n", sum(3));
    printf("Sum= %d", formula_sum(3));
}