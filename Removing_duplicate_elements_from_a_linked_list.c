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
        (*(t)).next = NULL;
        (*(t)).data = A[i];
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
void remover(struct node *p)
{
    struct node *a = NULL;
    struct node *b = NULL;
    a = (*(first)).next;
    b = first;
    while (a != NULL)
    {
        if ((*(a)).data == (*(b)).data)
        {
            (*(b)).next = (*(a)).next;
            free(a);
            a = (*(b)).next;
        }
        else
        {
            a = (*(a)).next;
            b = (*(b)).next;
        }
    }
}
int main()
{
    int A[10] = {10, 20, 20, 30, 30, 30, 40, 40, 40, 40};
    create(A, 10);
    display(first);
    remover(first);
    printf("\nAfter removing duplicate elements:\n");
    display(first);
}
/*Nodes were formed during create function and we make only pointers for accessing the
nodes.*/