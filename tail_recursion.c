#include <stdio.h>
void fun(int x)
{
    if (x > 0)
    {
        printf("%d ", x);
        fun(x - 1);
    }
}
int main()
{
    /*in tail recursion, during the returning time, no operation is performed.*/
    fun(7);
}
/*Time complexity is same in recursive and loop approach as they call equal number of times
but recursive approach has more space complexity as it calls functions many times
which leads to formation of many activation records hence,more space consumption
but in iterative approach only one activation record is formed .
space complexity of recursive approach is O(n).
space complexity of iterative approach is O(1).*/