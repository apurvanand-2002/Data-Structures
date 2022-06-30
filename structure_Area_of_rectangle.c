#include <stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct rectangle r;
    printf("Enter value of length:\n");
    scanf("%d", &r.length);
    printf("Enter breadth of rectangle:\n");
    scanf("%d", &r.breadth);
    printf("Area of the rectangle is %d.\n", r.length * r.breadth);
}