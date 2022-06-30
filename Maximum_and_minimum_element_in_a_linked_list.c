#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next; /*self-referential pointer*/
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
int max(struct node *p)
{
    int max = (*(p)).data;
    p = (*(p)).next;
    while (p != NULL)
    {
        if ((*(p)).data > max)
        {
            max = (*(p)).data;
            p = (*(p)).next;
        }
        else
        {
            p = (*(p)).next;
        }
    }
    return max;
}
int min(struct node *p)
{
    int min = (*(p)).data;
    p = (*(p)).next;
    while (p != NULL)
    {
        if ((*(p)).data < min)
        {
            min = (*(p)).data;
            p = (*(p)).next;
        }
        else
        {
            p = (*(p)).next;
        }
    }
    return min;
}
int rmax(struct node *p)
{
    int x;
    if (p == NULL)
    {
        return INT_MIN;
    }
    else
    {
        x = rmax((*(p)).next);
        return x < (*(p)).data ? (*(p)).data : x;
        /*if (x < (*(p)).data)
        {
            x = (*(p)).data;
            return x;
        }
        else
        {
            return x;
        }*/
    }
}
int rmin(struct node *p)
{
    int x;
    if (p == NULL)
    {
        return INT_MAX;
    }
    else
    {
        x = rmin((*(p)).next);
        return x > (*(p)).data ? (*(p)).data : x;
        /*if (x > (*(p)).data)
        {
            x = (*(p)).data;
            return x;
        }
        else
        {
            return x;
        }*/
    }
}
int main()
{
    int A[10] = {2, 34, 1, 0, 789, 34567, 9, 98, -76, 0};
    create(A, 10);
    display(first);
    printf("\nmaximum=%d and minimum=%d\n", rmax(first), rmin(first));
}