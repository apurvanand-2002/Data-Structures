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
struct node *linear_search(struct node *p, int n)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if ((*(p)).data == n)
        {
            (*(q)).next = (*(p)).next;
            (*(p)).next = first;
            first = p;
            return p;
        }
        else
        {
            q = p;
            p = (*(p)).next;
        }
    }
    return NULL;
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\n%d is found at address:%x.\n", 40, linear_search(first, 40));
    display(first);
    printf("\n%d is found at address:%x.\n", 30, linear_search(first, 30));
    display(first);
}