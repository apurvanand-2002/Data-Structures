/*Selection sort takes minimum number of swaps and it is also used for finding 'k'
smallest numbers.*/
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
void selection_sort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i <= (n - 1); i++) //'i' shows passes
    {
        for (j = k = i; j <= (n - 1); j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(&A[k], &A[i]);
    }
}
int main()
{
    int A[] = {10, 23, 4, 6, 78, 98, 1, 78, 54, 0};
    selection_sort(A, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}