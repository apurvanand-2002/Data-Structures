#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
int binary_search(struct array r, int num)
{
    int l = 0, h = (r.length - 1);
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (r.A[mid] > num)
        {
            h = mid - 1;
        }
        else if (r.A[mid] < num)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return (-1);
}
int main()
{
    struct array arr;
    printf("Enter size of array:\n");
    scanf("%d", &arr.size);
    printf("Enter length of the array:\n");
    scanf("%d", &arr.length);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("\nEntered elements are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("Enter element to be found:\n");
    int x;
    scanf("%d", &x);
    printf("\nNumber %d is found at index:%d.\n", x, binary_search(arr, x));
}