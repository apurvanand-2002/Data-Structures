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
void append(struct array *r, int a)
{
    if ((*(r)).length < (*(r)).size)
    {
        (*(r)).A[(*(r)).length] = a;
        (*(r)).length++;
    }
}
void insert(struct array *a, int index, int n)
{
    if ((*(a)).length < (*(a)).size)
    {
        for (int i = (*(a)).length; i > index; i--)
        {
            (*(a)).A[i] = (*(a)).A[i - 1];
        }
        (*(a)).A[index] = n;
        (*(a)).length++;
    }
}
void delete (struct array *a, int index)
{
    for (int i = index; i < (*(a)).length - 1; i++)
    {
        (*(a)).A[i] = (*(a)).A[i + 1];
    }
    (*(a)).length--;
}
int main()
{
    struct array arr;
    arr.size = 10;
    arr.length = 6;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.A[0] = 0;
    arr.A[1] = 1;
    arr.A[2] = 2;
    arr.A[3] = 3;
    arr.A[4] = 4;
    arr.A[5] = 5;
    display(arr);
    append(&arr, 6);
    printf("\n");
    display(arr);
    insert(&arr, 3, 456);
    printf("\n");
    display(arr);
    delete (&arr, 3);
    printf("\n");
    display(arr);
}