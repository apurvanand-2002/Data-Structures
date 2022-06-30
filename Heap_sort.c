#include <stdio.h>
void create(int A[], int n)
{
    /*Creates heap on the basis of the conditions that maximum numbers are at top as it
    is a max heap.*/
    int i = n;
    int temp = A[i];
    while (i > 1 && A[i / 2] < temp)
    { /*not equal to 1 as then comparison with 0.5 would also occur*/
        A[i] = A[i / 2];
        i = (i / 2);
    }
    A[i] = temp;
}
void insert(int A[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        create(A, i);
    }
}
int delete (int A[], int n) // n here is no.of elements present in array.
{
    /*deletion of only the root node occurs.*/
    int val = A[1];
    A[1] = A[n];
    A[n] = val; // inserted maximum at the end of the array
    int i = 1, j = (2 * i);
    while (j < (n - 1))
    {
        if (A[j] < A[j + 1])
        {
            j = j + 1;
        }
        if (A[j] > A[i])
        {
            int temp;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i = j;
            j = (2 * i);
        }
        else
        {
            break;
        }
    }
    return val;
}
int main()
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    insert(A, 7);
    for (int i = 1; i <= 7; i++)
    {
        printf("%d ", A[i]);
    }
    for (int i = 7; i >= 1; i--)
    {
        delete (A, i); /*variable 'i' in delete represents number of elements before
                            deletion.*/
    }
    printf("\n");
    for (int i = 1; i <= 7; i++)
    {
        printf("%d ", A[i]); // heap sort order of nlog(n)
    }
}