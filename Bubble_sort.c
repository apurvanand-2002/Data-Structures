/*Bubble sort is used for finding 'k' largest elements.*/
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
void bubble_sort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {             //'i' shows the passes eg:pass-0,pass-1,pass-2 etc
        flag = 0; // helps in making bubble sort 'adaptive'
        for (int j = 0; j < (n - 1 - i); j++)
        { //'j' shows the  of comparisons eg:j=0,j=1 etc
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0 && i == 0)
        {
            printf("Elements are already sorted.\n");
            break;
        }
    }
}
int main()
{
    int A[] = {10, 23, 4, 6, 78, 98, 1, 78, 54, 0}; // bubble sort is 'stable'
    bubble_sort(A, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}