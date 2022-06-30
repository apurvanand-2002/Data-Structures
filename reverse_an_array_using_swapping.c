#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
void display(struct array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
}
int main()
{
    struct array a;
    // a.size = 100;
    printf("Enter length of array:\n");
    scanf("%d", &a.length);
    a.A = (int *)malloc(a.length * sizeof(int));
    printf("enter elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        scanf("%d", &a.A[i]);
    }
    printf("Entered elements are:\n");
    display(a);
    int i, j;
    for (i = 0, j = a.length - 1; i < j; i++, j--)
    {
        swap(&a.A[i], &a.A[j]);
    }
    printf("Reversed!\n");
    display(a);
}