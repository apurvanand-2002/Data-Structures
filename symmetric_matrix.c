#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m, int i, int j, int n)
{
    if (i >= j)
    {
        (*(m)).A[(i * (i - 1) / 2) + (j - 1)] = n;
    }
}
void get(struct matrix *m)
{
    for (int i = 0; i < (((*(m)).n) * ((*(m)).n + 1) / 2); i++)
    {
        printf("%d\t", (*(m)).A[i]);
    }
}
int main()
{
    struct matrix m;
    printf("Enter number of rows:\n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(((m.n) * (m.n + 1) / 2) * sizeof(int));
    set(&m, 1, 1, 1);
    set(&m, 1, 2, 8);
    set(&m, 1, 3, 9);
    set(&m, 1, 4, 10);
    set(&m, 2, 1, 8);
    set(&m, 2, 2, 2);
    set(&m, 2, 3, 7);
    set(&m, 2, 4, 6);
    set(&m, 3, 1, 9);
    set(&m, 3, 2, 7);
    set(&m, 3, 3, 3);
    set(&m, 3, 4, 5);
    set(&m, 4, 1, 10);
    set(&m, 4, 2, 6);
    set(&m, 4, 3, 5);
    set(&m, 4, 4, 4);
    printf("Equivalent representation of symmetric matrix is:\n");
    get(&m);
}