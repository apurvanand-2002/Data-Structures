#include <stdio.h>
void set(int A[4][4], int B[], int m, int n)
{
    int i = 0, j = 0;
    static int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                B[k] = A[i][j];
                k++;
            }
        }
    }
}
void get(int B[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", B[i]);
    }
}
int main()
{
    int A[4][4], B[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter element-A[%d][%d]:\n", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Displaying Entered matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    set(A, B, 4, 4);
    printf("\nDiagonal Matrix is:\n");
    get(B, 4);
}