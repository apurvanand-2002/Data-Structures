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
void insert_sorted(struct node *p, int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = num;
    struct node *r = NULL;
    struct node *q = NULL;
    r = first;

    if ((*(r)).data > num && r == first)
    {
        (*(t)).next = r;
        first = t;
    }
    else
    {
        while (r != NULL && (*(r)).data < num)
        {
            q = r;
            r = (*(r)).next;
        }
        (*(t)).next = (*(q)).next;
        (*(q)).next = t;
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\nHow many numbers do you want to insert?\n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter number to be inserted:\n");
        int n;
        scanf("%d", &n);
        insert_sorted(first, n);
        printf("\nNEW LINKED LIST IS:\n");
        display(first);
    }
}