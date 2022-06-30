#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
int binary_search_iterative(struct array a, int num)
{
    int l = 0, h = (a.length - 1);
    int mid;
    while (l <= h)
    {
        mid = ((l + h) / 2);
        if (num < a.A[mid])
        {
            h = mid - 1;
        }
        else if (num > a.A[mid])
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    struct array arr;
    printf("Enter the size of array:\n");
    scanf("%d", &arr.size);
    printf("Enter the length of array:\n");
    scanf("%d", &arr.length);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("Printing the entered elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nEnter the element to be found:\n");
    int x;
    scanf("%d", &x);
    printf("Element %d is present at index:%d.\n", x, binary_search_iterative(arr, x));
}