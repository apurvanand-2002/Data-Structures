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
void recursive_display(struct node *p)
{
    static int k = 0; // static or global or extern
    if (p != first || k == 0)
    {
        k = 1;
        printf("%d\t", (*(p)).data);
        recursive_display((*(p)).next);
    }
    k = 0;
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    struct node *a;
    create(A, 5);
    a = first;
    a = first->next->next->next->next;
    (*(a)).next = first;
    recursive_display(first);
    recursive_display(first);
    recursive_display(first);
}