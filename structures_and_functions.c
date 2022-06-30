#include <stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
void create(struct rectangle *a, int l, int b)
{
    (*(a)).length = l;
    (*(a)).breadth = b;
}
int area(struct rectangle a)
{
    return (a).length * (a).breadth;
}
void change_length(struct rectangle *a, int x)
{
    (*(a)).length = x;
}
int main()
{
    struct rectangle r;
    create(&r, 10, 10);
    printf("Area is %d.\n", area(r));
    change_length(&r, 20);
    printf("length %d\n", r.length);
    printf("Area=%d", area(r));
}