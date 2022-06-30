#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;
void create(int A[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    (*(first)).prev = NULL;
    (*(first)).next = NULL;
    (*(first)).data = A[0];
    struct node *t, *last;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = A[i];
        (*(t)).next = (*(last)).next;
        (*(t)).prev = last;
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
/*void reversal(struct node *q)
{
    struct node *temp = NULL;
    struct node *p = NULL;
    p = q;
    while (p != NULL)
    {
        temp = (*(p)).next;
        (*(p)).next = (*(p)).prev;
        (*(p)).prev = temp;
        p = (*(p)).prev;
        if (p != NULL && (*(p)).next == NULL)
        {
            first = p;
        }
    }
}*/
void reversal(struct node *p)
{
    struct node *temp;
    while (p != NULL)
    {
        temp = (*(p)).next;
        (*(p)).next = (*(p)).prev;
        (*(p)).prev = temp;
        p = (*(p)).prev;
        if (p != NULL && (*(p)).next == NULL)
        {
            first = p;
        }
    }
}
int main()
{
    int A[5] = {100, 200, 300, 400, 500};
    create(A, 5);
    display(first);
    reversal(first);
    printf("\n");
    display(first);
}