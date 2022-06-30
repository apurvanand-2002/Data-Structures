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
void delete (struct node *p, int pos)
{
    struct node *a = NULL;
    struct node *b = NULL;
    if (pos == 1)
    {
        a = first;
        first = (*(first)).next;
        free(a);
    }
    else
    {
        a = first;
        for (int i = 1; i <= (pos - 1) && a != NULL; i++)
        {
            b = a;
            a = (*(a)).next; /*Used two pointer ,so, that we can delete the node.*/
        }
        if (a != NULL)
        {
            (*(b)).next = (*(a)).next;
            free(a);
        }
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\nEnter number of elements you want to delete?\n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter position to be deleted:\n");
        int n;
        scanf("%d", &n);
        delete (first, n);
        printf("\nDeleted linked list is:\n");
        display(first);
    }
}