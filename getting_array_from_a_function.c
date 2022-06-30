#include <stdio.h>
#include <stdlib.h>
int *array(int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    (*(p)) = 1;
    (*(p + 1)) = 2;
    (*(p + 2)) = 3;
    (*(p + 3)) = 4;
    (*(p + 4)) = 5;
    return p;
}
int main()
{
    int *A;
    A = array(5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
}