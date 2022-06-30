#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int l, int mid, int h)
{
    int i = l, j = (mid + 1);
    int *b;
    int k = l;
    b = (int *)malloc((h + 1) * sizeof(int));
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            b[k] = A[i];
            k++;
            i++;
        }
        else if (A[j] < A[i])
        {
            b[k] = A[j];
            k++;
            j++;
        }
    }
    for (; i <= mid; i++)
    {
        b[k] = A[i];
        k++;
    }
    for (; j <= h; j++)
    {
        b[k] = A[j];
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = b[i];
    }
}
void merge_sort(int A[], int n)
{
    int p, i, l, mid, h;
    for (p = 2; p <= n; p = (2 * p)) // passes
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = (i + p - 1);
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if ((n - i) > (p / 2)) /*Merging each element during each pass.*/
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, (n - 1)); /*as 'if' condition will be executed only
             once so, instead of 'h' we will write (n-1) so,that all the elements
             till the end are merged.*/
        }
    }
    if (n > (p / 2))
    {
        merge(A, 0, (p / 2) - 1, (n - 1)); /*same reason as above*/
    }
}
int main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1};
    merge_sort(A, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", A[i]);
    }
}