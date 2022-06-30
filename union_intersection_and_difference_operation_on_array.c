#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int length;
    int size;
};
void display(struct array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
}
void union_array(struct array *a, struct array *b, struct array *u)
{
    int i = 0, j = 0, k = 0;
    while (i < (*a).length && j < (*b).length)
    {
        if ((*a).A[i] < (*b).A[j])
        {
            (*u).A[k] = (*a).A[i];
            k++;
            i++;
        }
        else if ((*b).A[j] < (*a).A[i])
        {
            (*u).A[k] = (*b).A[j];
            k++;
            j++;
        }
        else if ((*b).A[j] == (*a).A[i])
        {
            (*u).A[k] = (*a).A[i];
            i++;
            j++;
            k++;
        }
    }
    if (j != (*b).length)
    {
        while (j != (*b).length)
        {
            (*u).A[k] = (*b).A[j];
            j++;
            k++;
        }
    }
    if (i != (*a).length)
    {
        while (i != (*a).length)
        {
            (*u).A[k] = (*a).A[i];
            k++;
            i++;
        }
    }
    (*u).length = k;
}
void intersection(struct array *a, struct array *b, struct array *d)
{
    static int i = 0, j = 0, k = 0;
    while (i < (*(a)).length && j < (*(b)).length)
    {
        if ((*(a)).A[i] < (*(b)).A[j])
        {
            i++;
        }
        else if ((*(a)).A[i] > (*(b)).A[j])
        {
            j++;
        }
        else if ((*(a)).A[i] == (*(b)).A[j])
        {
            (*(d)).A[k] = (*(a)).A[i];
            k++;
            i++;
            j++;
        }
    }
    (*(d)).length = k;
}
void difference(struct array *a, struct array *b, struct array *e)
{
    static int i = 0, j = 0, k = 0;
    while (i < (*(a)).length && j < (*(b)).length)
    {
        if ((*(a)).A[i] < (*(b)).A[j])
        {
            (*(e)).A[k] = (*(a)).A[i];
            k++;
            i++;
        }
        else if ((*(a)).A[i] > (*(b)).A[j])
        {
            j++;
        }
        else if ((*(a)).A[i] == (*(b)).A[j])
        {
            i++;
            j++;
        }
    }
    if (i != (*(a)).length)
    {
        while (i != (*(a)).length)
        {
            (*(e)).A[k] = (*(a)).A[i];
            k++;
            i++;
        }
    }
    if (j != (*(b)).length)
    {
        while (j != (*(b)).length)
        {
            j++;
        }
    }
    (*(e)).length = k;
}
int main()
{
    struct array a, b, u, i, d;
    a.size = 15;
    b.size = 15;
    u.size = d.size = 15;
    i.size = 15;
    a.A = (int *)malloc(a.size * sizeof(int));
    b.A = (int *)malloc(b.size * sizeof(int));
    u.A = (int *)malloc(u.size * sizeof(int));
    i.A = (int *)malloc(i.size * sizeof(int));
    d.A = (int *)malloc(d.size * sizeof(int));
    printf("Enter length of A and B:\n");
    scanf("%d %d", &a.length, &b.length);
    printf("\nEnter first array in sorted manner:\n");
    for (int i = 0; i < a.length; i++)
    {
        scanf("%d", &a.A[i]);
    }
    display(a);
    printf("\nEnter second array in sorted manner:\n");
    for (int i = 0; i < b.length; i++)
    {
        scanf("%d", &b.A[i]);
    }
    display(b);
    printf("\nUnion of two arrays:\n");
    union_array(&a, &b, &u);
    display(u);
    printf("\nIntersection of Two arrays:\n");
    intersection(&a, &b, &i);
    display(i);
    printf("\nDifference of Two arrays:\n");
    difference(&a, &b, &d);
    display(d);
}