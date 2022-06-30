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
    do
    {
        printf("%d\t", (*(p)).data);
        p = (*(p)).next;
    } while (p != first);
}
int isloop(struct node *p)
{
    struct node *a = NULL, *b = NULL;
    a = b = p;
    do
    {
        a = (*(a)).next;
        b = (*(b)).next;
        b = (b != NULL) ? (*(b)).next : NULL;
    } while (a != NULL && b != NULL && a != b);
    if (a == b)
        return 1;
    else
        return 0;
}
int main()
{
    struct node *p, *q;
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    p = first->next->next;
    q = first->next->next->next->next;
    (*(q)).next = p;
    // display(first);
    if (isloop(first) == 1)
    {
        printf("\nLOOP\n");
    }
    else
    {
        printf("\nLINEAR\n");
    }
}