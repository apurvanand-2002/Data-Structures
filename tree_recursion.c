/*Linear recursion occurs when recursive call is made only once int the entire programme.
Tree recursion occurs when recursive call is made more than once.*/
#include <stdio.h>
void fun(int x)
{
    if (x > 0)
    {
        printf("%d ", x);
        fun(x - 1);
        fun(x - 1);
    }
}
int main()
{
    fun(3);
}