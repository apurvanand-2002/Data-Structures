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
    (*(first)).data = A[0];
    (*(first)).prev = NULL;
    (*(first)).next = NULL;
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
void insert(struct node *p, int pos, int n)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = n;
    struct node *q = NULL;
    if (pos == 0)
    {
        (*(t)).next = first;
        (*(t)).prev = NULL;
        (*(first)).prev = t;
        first = t; /*Must be written otherwise node will be made but won't be printed.*/
    }
    else
    {
        q = first;
        for (int i = 0; i < (pos - 1); i++)
        {
            q = (*(q)).next;
        }
        (*(t)).next = (*(q)).next;
        (*(t)).prev = q;
        if ((*(q)).next != NULL)
        {
            (*(q)).next->prev = t;
        }
        (*(q)).next = t;
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\nHow many number do you want to insert?\n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter position and and value:\n");
        int pos, val;
        scanf("%d %d", &pos, &val);
        insert(first, pos, val);
        display(first);
    }
}