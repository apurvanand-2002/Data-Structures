#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*int A[5] = {2, 4, 6, 8, 10};
    int *p;
    Array's name is also a pointer to 0th element of the array.
    p = A;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (*(A + i)));
    }*/

    int B[5];
    int *q;
    q = (int *)malloc(5 * sizeof(int));
    // Array's name is a pointer to 0th element of the array.
    q = B;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter element-%d:", i);
        scanf("%d", q + i);
    }
    printf("Entered elements are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (*(q + i)));
    }
}