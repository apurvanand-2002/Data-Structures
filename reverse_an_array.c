#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
void display(struct array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
}
int main()
{
    struct array a, b;
    // a.size = 100;
    // b.size = 100;

    printf("Enter the length of array:\n");
    scanf("%d", &a.length);
    b.length = a.length;
    a.A = (int *)malloc(a.length * sizeof(int));
    b.A = (int *)malloc(b.length * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        scanf("%d", &a.A[i]);
    }
    display(a);
    int i, j;
    for (i = a.length - 1, j = 0; i >= 0, j < b.length; i--, j++)
    {
        b.A[j] = a.A[i];
    }
    printf("Reversed:\n");
    for (i = 0; i < a.length; i++)
    {
        a.A[i] = b.A[i];
    }
    display(a);
    free(b.A);
    b.A = NULL;
}