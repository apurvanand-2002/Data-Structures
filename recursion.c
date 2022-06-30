#include <stdio.h>
void fun(int c)
{
    if (c > 0)
    {
        fun(c - 1);
        printf("%d ", c);
    }
}
int main()
{
    int a = 5;
    fun(a);
}
/*Recursion is implemented using stack.
During the implementation of each function with a new value of c as arguement,a new
activation record is made.*/