#include <stdio.h>
int main()
{
    int A[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter element-A[%d]:\n", i);
        scanf("%d", &A[i]);
    }
    printf("Entered elements are:\n");
    i = 0;
    while (i < 5)
    {
        printf("%d ", A[i]);
        i++;
    }
}