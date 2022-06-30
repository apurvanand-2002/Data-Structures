#include <stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct rectangle a;
    struct rectangle *r;
    r = &a;
    (*(r)).length = 9;
    (*(r)).breadth = 10;
    printf("Area of the given rectangle is %d.", a.length * a.breadth);
}