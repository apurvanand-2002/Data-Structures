#include <stdio.h>
#include <stdlib.h>
int *merge(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int *C;
    C = (int *)malloc((m + n) * sizeof(int));
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] > B[j])
        {
            C[k] = B[j];
            k++;
            j++;
        }
    }
    for (; i < m; i++)
    {
        C[k] = A[i];
        k++;
        i++;
    }
    for (; j < n; j++)
    {
        C[k] = B[j];
        k++;
        j++;
    }
    return C;
}
int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    int *P;
    P = merge(A, 5, B, 5);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*(P + i)));
    }
}