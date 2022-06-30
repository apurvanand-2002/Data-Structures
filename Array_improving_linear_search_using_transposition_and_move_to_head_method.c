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
int linear_search_transposition(struct array r, int num)
{
    for (int i = 0; i < r.length; i++)
    {
        if (num == r.A[i])
        {
            swap(&r.A[i], &r.A[i - 1]);
            return (i - 1);
        }
    }
    return -1;
}
int linear_search_moving_to_head(struct array r, int num)
{
    for (int i = 0; i < r.length; i++)
    {
        if (r.A[i] == num)
        {
            swap(&r.A[i], &r.A[0]);
            return 0;
        }
    }
    return -1;
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
    struct array arr;
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter length of array:\n");
    scanf("%d", &arr.length);
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("\n");
    display(arr);
    printf("\nEnter number which is to be found:\n");
    int x;
    scanf("%d", &x);
    linear_search_moving_to_head(arr, x);
    display(arr);
}