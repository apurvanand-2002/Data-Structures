#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
int get(struct array a, int index)
{
    if (index >= 0 && index < a.length)
    {
        return a.A[index];
    }
    return -1;
}
void set(struct array *a, int index, int num)
{
    if (index >= 0 && index <= (*(a)).length)
    {
        int temp;
        temp = (*(a)).A[index];
        (*(a)).A[index] = num;
    }
}
int max(struct array a)
{
    int max = a.A[0];
    for (int i = 1; i < a.length; i++)
    {
        if (a.A[i] > max)
        {
            max = a.A[i];
        }
    }
    return max;
}
int min(struct array a)
{
    int min = a.A[0];
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] < min)
        {
            min = a.A[i];
        }
    }
    return min;
}
int sum(struct array a)
{
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
        sum = sum + a.A[i];
    }
    return sum;
}
float average(struct array a)
{
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
        sum = sum + a.A[i];
    }
    return ((sum) / a.length);
}
int rsum(struct array a, int length)
{
    int sum = 0;
    if (length >= 0)
    {
        return a.A[length] + rsum(a, length - 1);
    }
    else
    {
        return 0;
    }
}
void display(struct array a)
{
    printf("printing the elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
}
int main()
{
    struct array arr;
    printf("Enter the size of array:\n");
    scanf("%d", &arr.size);
    printf("Enter the length of the array:\n");
    scanf("%d", &arr.length);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    display(arr);
    printf("Element at index %d is %d.\n", 3, get(arr, 3));
    set(&arr, 4, 90);
    display(arr);
    printf("Max is %d and min is %d.\n", max(arr), min(arr));
    printf("Sum is %d , rsum is %d and average is %f.\n", sum(arr), rsum(arr, arr.length - 1), average(arr));
}