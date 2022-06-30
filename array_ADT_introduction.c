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
int main()
{
    struct array arr;
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter length of the array:\n");
    scanf("%d", &arr.length);
    printf("Enter the elements:\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("Entered elements are:\n");
    display(arr);
}
/*Array structure has size,length and also a pointer.This pointer is used for allocating
this array in heap.*/