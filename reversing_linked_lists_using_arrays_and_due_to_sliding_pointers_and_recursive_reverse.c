#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void create(int A[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    (*(first)).data = A[0];
    (*(first)).next = NULL;
    struct node *t, *last;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = A[i];
        (*(t)).next = NULL;
        (*(last)).next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", (*(p)).data);
        p = (*(p)).next;
    }
}
void reverse_using_array(struct node *p)
{
    static int count = 0;
    while (p != NULL)
    {
        count++;
        p = (*(p)).next;
    }
    int *z;
    z = (int *)malloc(count * sizeof(int));
    static int i = 0;
    p = first; /*As it has moved to NULL due to previous for loop,it must be set again
                    at a desired location ,so, that it can work according to our need
                    else, it will give garbage values.*/
    while (p != NULL)
    {
        (*(z + i)) = (*(p)).data;
        i++;
        p = (*(p)).next;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        (*(p)).data = (*(z + i));
        i--;
        p = (*(p)).next;
    }
}
void reverse_using_sliding_pointers(struct node *p)
{
    struct node *a = NULL;
    struct node *b = NULL;
    struct node *c = NULL;

    a = first;
    while (a != NULL)
    {
        c = b;
        b = a;
        a = (*(a)).next;
        (*(b)).next = c;
    }
    first = b;
}
void recursive_reverse(struct node *q, struct node *p)
{
    if (p != NULL)
    {
        recursive_reverse(p, (*(p)).next);
        (*(p)).next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int A[5] = {10, 20, 300, 4000, 50};
    create(A, 5);
    display(first);
    printf("\nReversed array is:\n");
    recursive_reverse(NULL, first);
    display(first);
}