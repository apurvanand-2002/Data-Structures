#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m, int i, int j, int p)
{
    if (j >= i && i == 1)
    {
        (*(m)).A[j - i] = p;
    }
    if (i > j && j == 1)
    {
        (*(m)).A[(*(m)).n + i - j - 1] = p;
    }
}
void get(struct matrix *m)
{
    for (int i = 0; i < (2 * ((*(m)).n) - 1); i++)
    {
        printf("%d\t", (*(m)).A[i]);
    }
}
int main()
{
    struct matrix m;
    m.n = 4;
    m.A = (int *)malloc((2 * m.n - 1) * sizeof(int));
    set(&m, 1, 1, 1);
    set(&m, 1, 2, 5);
    set(&m, 1, 3, 6);
    set(&m, 1, 4, 8);
    set(&m, 2, 1, 2);
    set(&m, 2, 2, 1);
    set(&m, 2, 3, 5);
    set(&m, 2, 4, 6);
    set(&m, 3, 1, 3);
    set(&m, 3, 2, 2);
    set(&m, 3, 3, 1);
    set(&m, 3, 4, 5);
    set(&m, 4, 1, 4);
    set(&m, 4, 2, 3);
    set(&m, 4, 3, 2);
    set(&m, 4, 4, 1);
    printf("Equivalent Form of Toeplitz matrix is:\n");
    get(&m);
}