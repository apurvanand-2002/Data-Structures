#include <stdio.h>
#include <stdlib.h>
struct rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct rectangle *r = (struct rectangle *)malloc(sizeof(struct rectangle));
    (*(r)).length = 10;
    (*(r)).breadth = 7;
    printf("Area of the rectangle is %d.\n", (*(r)).length * (*(r)).breadth);
    printf("Perimeter of the given rectangle is %d.", (2 * ((*(r)).length * (*(r)).breadth)));
    free(r);
}