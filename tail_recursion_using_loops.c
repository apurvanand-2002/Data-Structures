#include <stdio.h>
void fun(int x)
{
    while (x > 0)
    {
        printf("%d ", x);
        x--;
    }
}
int main()
{
    fun(7);
}