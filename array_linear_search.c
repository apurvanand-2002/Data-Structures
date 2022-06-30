#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
void display(struct array r)
{
    for (int i = 0; i < r.length; i++)
    {
        printf("%d ", r.A[i]);
    }
}
int linear_search(struct array r, int num)
{
    for (int i = 0; i < r.length; i++)
    {
        if (r.A[i] == num)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    struct array arr;
    printf("Enter sizeof array:\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter length of the array:\n");
    scanf("%d", &arr.length);
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("\n");
    display(arr);
    printf("\nEnter the element to be found:\n");
    int x;
    scanf("%d", &x);
    printf("Element %d is at index:%d.\n", x, linear_search(arr, x));
}