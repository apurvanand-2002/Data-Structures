#include <stdio.h>
void fun(int x)
{
    int i = 1;
    while (i <= x)
    {
        printf("%d ", i);
        i++;
    }
}
int main()
{
    fun(3);
}