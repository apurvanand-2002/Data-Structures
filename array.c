#include <stdio.h>
int main()
{
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter element-%d:\n", i);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
}