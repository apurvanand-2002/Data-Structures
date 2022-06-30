#include <stdio.h>
void set(int A[], int B[15][15], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                B[i][j] = A[i];
            }
            else
            {
                B[i][j] = 0;
            }
        }
    }
}
void get(int B[15][15], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter number of elements in diagonal matrix:\n");
    int num;
    scanf("%d", &num);
    int A[num];
    int B[num][num];
    printf("Enter diagonal matrix:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Complete matrix is:\n");
    set(A, B, num);
    get(B, num);
}