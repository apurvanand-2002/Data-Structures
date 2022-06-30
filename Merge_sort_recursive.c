#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int l, int mid, int h)
{
    int i = l, j = (mid + 1);
    int *c;
    int k = l; // remember
    c = (int *)malloc((h + 1) * sizeof(int));
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            i++;
            k++;
        }
        else if (A[j] < A[i])
        {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    for (; i <= mid; i++)
    {
        c[k] = A[i];
        k++;
    }
    for (; j <= h; j++)
    {
        c[k] = A[j];
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = c[i];
    }
}
void merge_sort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}
int main()
{
    int A[] = {2, 3, 5, 4, 78, 56, 43, 21};
    merge_sort(A, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}