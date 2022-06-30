#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
void arranger(struct array *a)
{
    int i = 0;
    int j = (*(a)).length - 1;
    while (i < j)
    {
        while ((*(a)).A[i] < 0)
        {
            i++;
        }
        while ((*(a)).A[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&(*(a)).A[i], &(*(a)).A[j]);
        }
    }
}
int main()
{
    struct array arr;
    arr.size = 15;
    printf("Enter the length of the array:\n");
    scanf("%d", &arr.length);
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("\nEntered elements are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    arranger(&arr);
    printf("\nArranged elements are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}