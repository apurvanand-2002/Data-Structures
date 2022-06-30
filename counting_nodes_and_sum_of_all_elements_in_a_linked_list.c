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
int ncounter(struct node *p)
{
    static int count = 0;
    while (p != NULL)
    {
        count++;
        p = (*(p)).next;
    }
    return count;
}
int sum(struct node *p)
{
    static int sum = 0;
    while (p != NULL)
    {
        sum += (*(p)).data;
        p = (*(p)).next;
    }
    return sum;
}
int rncounter(struct node *p)
{
    if (p != NULL)
    {
        return 1 + rncounter((*(p)).next);
    }
    else
    {
        return 0;
    }
}
int rsum(struct node *p)
{
    if (p != NULL)
    {
        return (*(p)).data + rsum((*(p)).next);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("count:%d,sum:%d", rncounter(first), rsum(first));
}