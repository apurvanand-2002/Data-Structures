#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **p;
    p = (int **)malloc(3 * sizeof(int *));
    p[0] = (int *)malloc(4 * sizeof(int));
    p[1] = (int *)malloc(4 * sizeof(int));
    p[2] = (int *)malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}