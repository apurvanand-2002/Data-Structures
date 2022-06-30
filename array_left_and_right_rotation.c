#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
void left_reverse(struct array a)
{
    int i = 0;
    int temp;
    temp = a.A[i];
    for (int i = 0; i < a.length - 1; i++)
    {
        a.A[i] = a.A[i + 1];
    }
    a.A[a.length - 1] = temp;
}
void right_shift(struct array a)
{
    int temp;
    temp = a.A[a.length - 1];
    for (int i = a.length - 1; i >= 1; i--)
    {
        a.A[i] = a.A[i - 1];
    }
    a.A[0] = temp;
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
    printf("Enter length of array:\n");
    a.A = (int *)malloc(a.length * sizeof(int));
    scanf("%d", &a.length);
    printf("Enter elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        scanf("%d", &a.A[i]);
    }
    printf("Entered elements are:\n");
    display(a);
    printf("\nright shift by one:\n");
    // left_reverse(a);
    right_shift(a);
    display(a);
    printf("\nright shift by one:\n");
    // left_reverse(a);
    right_shift(a);
    display(a);
}