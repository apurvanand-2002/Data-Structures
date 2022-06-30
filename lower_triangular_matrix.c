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
void get(struct matrix m)
{
    for (int i = 0; i < m.n * (m.n + 1) / 2; i++)
    {
        printf("%d ", m.A[i]);
    }
}
void display(struct matrix *m)
{
    for (int i = 1; i <= (*(m)).n; i++)
    {
        for (int j = 1; j <= (*(m)).n; j++)
        {
            if (i >= j)
            {
                printf("%d ", (*(m)).A[(i * (i - 1) / 2) + (j - 1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    printf("Enter number of rows:\n");
    scanf("%d", &m.n);
    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int));
    set(&m, 1, 1, 1);
    // set(&m, 1, 2, 0);
    // set(&m, 1, 3, 0);
    // set(&m, 1, 4, 0);
    set(&m, 2, 1, 2);
    set(&m, 2, 2, 3);
    // set(&m, 2, 3, 0);
    // set(&m, 2, 4, 0);
    set(&m, 3, 1, 4);
    set(&m, 3, 2, 5);
    set(&m, 3, 3, 6);
    // set(&m, 3, 4, 0);
    set(&m, 4, 1, 7);
    set(&m, 4, 2, 8);
    set(&m, 4, 3, 9);
    set(&m, 4, 4, 10);
    get(m);
    printf("\n\n");
    display(&m);
}