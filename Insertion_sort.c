#include <stdio.h>
void insertion_sort(int A[], int n)
{
    /*We assume one element is already present in the array at index=0*/
    for (int i = 1; i < n; i++)
    {
        int x = A[i], j;
        j = (i - 1);
        while (j > (-1) && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
int main()
{
    int A[] = {10, 23, 4, 6, 78, 98, 1, 78, 54, 0};
    insertion_sort(A, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}