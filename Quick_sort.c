#include <stdio.h>
#include <limits.h>
/*As in quick sort algorithm ,we need an infinity as well ,so, we include limits.h
header file so,that we can use INT_MAX which gives us the maximum possible number
according to the configuration of the compiler.*/
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
int partition(int A[], int l, int h)
{
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= A[l]);
        do
        {
            j--;
        } while (A[j] > A[l]);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[j], &A[l]);
    return j;
}
void quick_sort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quick_sort(A, l, j);
        quick_sort(A, j + 1, h);
    }
}
int main()
{
    int A[] = {10, 23, 4, 6, 78, 98, 1, 78, 54, 0, INT_MAX};
    quick_sort(A, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}