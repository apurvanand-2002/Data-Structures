#include <stdio.h>
#include <stdlib.h>
int maximum(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void count_sort(int A[], int n)
{
    int maxim = maximum(A, n);
    int *count;
    count = (int *)malloc((maxim + 1) * sizeof(int));
    int i;
    for (i = 0; i < (maxim + 1); i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    i = 0;
    static int k = 0;
    while (k < n)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            while (count[i] != 0)
            {
                A[k] = i;
                count[i]--;
                k++;
            }
            i++;
        }
    }
}
int main()
{
    int A[] = {2, 3, 4, 5, 2, 3, 6, 8};
    count_sort(A, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}
/*Count sort takes a large amount of space due to creation of an array of
maximum size possible.*/