#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int l, int mid, int h)
{
    int i = l, j = (mid + 1), k = 0;
    int *B;
    B = (int *)malloc((h + 1) * sizeof(int));
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else if (A[j] < A[i])
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    for (; i <= mid; i++)
    {
        B[k] = A[i];
        k++;
    }
    for (; j <= h; j++)
    {
        B[k] = A[j];
        k++;
    }
    for (int p = 0; p < k; p++)
    {
        A[p] = B[p];
    }
    free(B);
    B = NULL;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}
int main()
{
    int A[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int *p;
    merge(A, 0, 4, 9);
}