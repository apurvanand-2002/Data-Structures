#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
int area(struct rectangle &a)
{
    return a.length * a.breadth;
}
int main()
{
    struct rectangle r;
    printf("Enter length and breadth:\n");
    scanf("%d %d", &r.length, &r.breadth);
    printf("Area of rectangle is %d.\n", area(r));
}