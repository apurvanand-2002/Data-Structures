#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m, int i, int j, int n)
{
    if ((i - j) == 1)
    {
        (*(m)).A[i - 2] = n;
    }
    else if ((i - j) == 0)
    {
        (*(m)).A[(*(m)).n + i - 2] = n;
    }
    else if ((i - j) == (-1))
    {
        (*(m)).A[2 * (*(m)).n + i - 2] = n;
    }
}
void get(struct matrix *m)
{
    for (int i = 0; i < (3 * ((*(m)).n) - 2); i++)
    {
        printf("%d\t", (*(m)).A[i]);
    }
}
int main()
{
    struct matrix m;
    m.n = 4;
    m.A = (int *)malloc(m.n * sizeof(int));
    set(&m, 1, 1, 1);
    set(&m, 1, 2, 6);
    set(&m, 1, 3, 0);
    set(&m, 1, 4, 0);
    set(&m, 2, 1, 8);
    set(&m, 2, 2, 2);
    set(&m, 2, 3, 5);
    set(&m, 2, 4, 0);
    set(&m, 3, 1, 0);
    set(&m, 3, 2, 7);
    set(&m, 3, 3, 3);
    set(&m, 3, 4, 4);
    set(&m, 4, 1, 0);
    set(&m, 4, 2, 0);
    set(&m, 4, 3, 5);
    set(&m, 4, 4, 4);
    printf("Equivalent form of Tri-diagonal matrix is:\n");
    get(&m);
}