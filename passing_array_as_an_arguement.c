#include <stdio.h>
void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", (*(A + i)));
    }
}
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    display(A, 5);
}