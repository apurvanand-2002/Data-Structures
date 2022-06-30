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
        (*(last)).next = NULL;
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
void insert(struct node *p, int pos, int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = num;
    if (pos == 0)
    {
        (*(t)).next = first;
        first = t;
    }
    else
    {
        struct node *q = NULL;
        q = first;
        for (int i = 0; i < pos - 1; i++)
        {
            q = (*(q)).next;
        }
        (*(t)).next = (*(q)).next;
        (*(q)).next = t;
    }
}
int main()
{
    printf("How many numbers do you want to insert?\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter position and value:\n");
        int pos, val;
        scanf("%d %d", &pos, &val);
        insert(first, pos, val);
        printf("\n NEW LINKED LIST:\n");
        display(first);
    }
}