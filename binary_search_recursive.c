#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
int binary_search_recursive(struct array a, int l, int h, int num)
{
    static int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (num < a.A[mid])
        {
            return binary_search_recursive(a, l, mid - 1, num);
        }
        else if (num > a.A[mid])
        {
            return binary_search_recursive(a, mid + 1, h, num);
        }
        else
        {
            return mid;
        }
    }
    else
    {
        return (-1);
    }
}
int main()
{
    struct array arr;
    printf("Enter size and length of the array:\n");
    scanf("%d %d", &arr.size, &arr.length);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nEnter element to be found:\n");
    int x;
    scanf("%d", &x);
    printf("Element %d is present at index:%d.\n", x, binary_search_recursive(arr, 0, arr.length - 1, x));
}