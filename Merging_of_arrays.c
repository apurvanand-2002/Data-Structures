#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
void display(struct array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
void merger(struct array *a, struct array *b, struct array *m)
{
    static int i = 0, j = 0, k = 0;
    while (i < (*a).length && j < (*b).length)
    {
        if ((*a).A[i] < (*b).A[j])
        {
            (*m).A[k] = (*a).A[i];
            i++;
            k++;
        }
        else if ((*a).A[i] > (*b).A[j])
        {
            (*m).A[k] = (*b).A[j];
            k++;
            j++;
        }
    }
    if (j < (*b).length)
    {
        while (j != (*b).length)
        {
            (*m).A[k] = (*b).A[j];
            j++;
            k++;
        }
    }
    if (i < (*a).length)
    {
        while (i != (*a).length)
        {
            (*m).A[k] = (*a).A[i];
            i++;
            k++;
        }
    }
}
int main()
{
    struct array a, b, m;
    a.size = 15;
    b.size = 15;
    m.size = 30;
    printf("Enter the lengths of two arrays respectively:\n");
    scanf("%d %d", &a.length, &b.length);
    a.A = (int *)malloc(a.length * sizeof(int));
    b.A = (int *)malloc(b.length * sizeof(int));
    m.A = (int *)malloc(m.size * sizeof(int));
    printf("Enter first array:\n");
    for (int i = 0; i < a.length; i++)
    {
        scanf("%d", &a.A[i]);
    }
    printf("second array is:\n");
    for (int i = 0; i < b.length; i++)
    {
        scanf("%d", &b.A[i]);
    }
    m.length = a.length + b.length;
    printf("\nFirst array is:\n");
    display(a);
    printf("\nSecond array is:\n");
    display(b);
    merger(&a, &b, &m);
    printf("\nMerged array is:\n");
    display(m);
}