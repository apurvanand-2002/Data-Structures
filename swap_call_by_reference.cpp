#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 1, b = 2;
    printf("a=%d b=%d\n", a, b);
    swap(a, b);
    printf("a=%d b=%d", a, b);
}