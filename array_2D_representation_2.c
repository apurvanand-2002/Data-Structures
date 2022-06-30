#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *A[3]; // array  of integer pointers
    A[0] = (int *)malloc(3 * sizeof(int));
    A[1] = (int *)malloc(3 * sizeof(int));
    A[2] = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}
/*Pointer is created in stack . Its memory is allocated in heap using malloc.*/