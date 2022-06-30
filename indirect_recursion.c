#include <stdio.h>
void fun2(int y);
void fun1(int x)
{
    if (x > 0)
    {
        printf("%d ", x);
        fun2(x - 1);
    }
}
void fun2(int y)
{
    if (y > 0)
    {
        printf("%d ", y);
        fun1(y / 2);
    }
}
int main()
{
    fun1(20);
}
/*Indirect recursion occurs when two or more function call each-other in a cyclic order.*/