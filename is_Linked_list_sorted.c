#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
int issorted(struct node *p)
{
    struct node *a = NULL;
    struct node *b = NULL;
    a = (*(first)).next;
    b = first;
    while (a != NULL)
    {
        if ((*(a)).data < (*(b)).data)
        {
            return 0;
        }
        else
        {
            a = (*(a)).next;
            b = (*(b)).next;
        }
    }
    return 1;
}
int sorted(struct node *p)
{
    int x = INT_MIN;
    struct node *q;
    q = first;
    while (q != NULL)
    { // x<(*(q)).data
        if (x > (*(q)).data)
        {
            return 0;
        }
        else
        {
            x = (*(q)).data;
            q = (*(q)).next;
        }
    }
    return 1;
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50000};
    create(A, 5);
    display(first);
    if (sorted(first) == 1)
    {
        printf("\nLINKED LIST IS SORTED!\n");
    }
    else
    {
        printf("\nLINKED LIST IS NOT SORTED!\n");
    }
}