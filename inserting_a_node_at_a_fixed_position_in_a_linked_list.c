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
struct node *insert(struct node *p, int pos)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in the new node:\n");
    scanf("%d", &(*(t)).data);
    if (pos == 0)
    {
        (*(t)).next = first;
        first = t;
    }
    else
    {
        struct node *q = NULL;
        q = first;
        for (int i = 0; i < (pos - 1) && q != NULL; i++)
        {
            q = (*(q)).next;
        }
        if (q != NULL)
        {
            (*(t)).next = (*(q)).next;
            (*(q)).next = t;
        }
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\n");
    insert(first, 0);
    display(first);
    printf("\n");
    insert(first, 7);
    display(first);
    printf("\n");
}