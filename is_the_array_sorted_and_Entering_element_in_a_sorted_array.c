#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
int issorted(struct array a)
{
    for (int i = 0; i < a.length - 1; i++)
    {
        if (a.A[i] > a.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void enter(struct array *a, int num)
{
    int i = ((*(a)).length - 1);
    (*(a)).length++;
    while (num < (*(a)).A[i])
    {
        (*(a)).A[i + 1] = (*(a)).A[i];
        i--;
    }
    (*(a)).A[i + 1] = num;
}
int main()
{
    struct array arr;
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size);
    printf("Enter length of the array:\n");
    scanf("%d", &arr.length);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("Entered elements are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    if (issorted(arr) == 1)
    {
        printf("\nArray is sorted!\n");
    }
    else
    {
        printf("\nArray is not sorted!\n");
    }
    enter(&arr, 156);
    printf("New array is:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}