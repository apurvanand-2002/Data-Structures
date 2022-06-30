#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
void create_first(int A[], int n)
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
void create_second(int A[], int n)
{
    second = (struct node *)malloc(sizeof(struct node));
    (*(second)).data = A[0];
    (*(second)).next = NULL;
    struct node *t, *last;
    last = second;
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
struct node *concatenate(struct node *p, struct node *q)
{
    struct node *a;
    a = p;
    while ((*(a)).next != NULL)
    {
        a = (*(a)).next;
    }
    (*(a)).next = q;
    q = NULL;
    return p;
}
struct node *merge(struct node *p, struct node *q)
{
    struct node *last = NULL;
    if ((*(p)).data < (*(q)).data)
    {
        third = last = p;
        p = (*(p)).next;
        (*(last)).next = NULL;
    }
    else if ((*(q)).data < (*(p)).data)
    {
        third = last = q;
        q = (*(q)).next;
        (*(last)).next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if ((*(p)).data < (*(q)).data)
        {
            (*(last)).next = p;
            last = p;
            p = (*(p)).next;
            (*(last)).next = NULL;
        }
        else if ((*(q)).data < (*(p)).data)
        {
            (*(last)).next = q;
            last = q;
            q = (*(q)).next;
            (*(last)).next = NULL;
        }
    }
    if (p != NULL)
    {
        while (p != NULL)
        {
            (*(last)).next = p;
            last = p;
            p = (*(p)).next;
            (*(last)).next = NULL;
        }
    }
    if (q != NULL)
    {

        while (q != NULL)
        {
            (*(last)).next = q;
            last = q;
            q = (*(q)).next;
            (*(last)).next = NULL;
        }
    }
    return third;
}
int main()
{
    int A[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int B[5] = {2, 4, 6, 8, 10};
    create_first(A, 8);
    printf("First linked list is:\n");
    display(first);
    create_second(B, 5);
    printf("\nSecond linked list is:\n");
    display(second);
    // printf("\nConcatenated linked list is:\n");
    // display(concatenate(first, second));
    printf("\nMerged Linked list is:\n");
    display(merge(first, second));
}