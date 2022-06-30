/*Shell sort is based on the assumption that if we do sorting at larger gaps ,so,
we complete a larger part of sorting in the least time.*/
#include <stdio.h>
void shell_sort(int A[], int n)
{
    int gap, i, temp, j;
    for (gap = (n / 2); gap >= 1; gap = (gap / 2)) // order of logarithm of 'n' to the base 2
    {
        for (i = gap; i < n; i++) // order of 'n'
        {
            temp = A[i];
            j = (i - gap);
            while (j >= 0 && A[j] > temp) // neglected as it won't contribute everytime
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
} // net order of shell sort is of nlog(n)
int main()
{
    int A[] = {2, 3, 4, 5, 2, 3, 6, 8};
    shell_sort(A, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}