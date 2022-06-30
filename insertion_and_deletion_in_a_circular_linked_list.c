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
void insert(struct node *p, int pos, int val)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = val;
    struct node *q = NULL;
    if (pos == 0)
    {
        (*(t)).next = first;
        q = first;
        do
        {
            q = (*(q)).next;
        } while ((*(q)).next != first);
        (*(q)).next = t;
        first = t;
    }
    else
    {
        q = first;
        for (int i = 1; i <= (pos - 1); i++)
        {
            q = (*(q)).next;
        }
        (*(t)).next = (*(q)).next;
        (*(q)).next = t;
    }
}
void delete (struct node *p, int pos)
{
    struct node *q = NULL;
    struct node *r = NULL;
    if (pos == 1)
    {
        q = first;
        do
        {
            q = (*(q)).next;
        } while ((*(q)).next != first);
        (*(q)).next = (*(first)).next;
        first = (*(q)).next;
    }
    else
    {
        q = first;
        for (int i = 1; i <= (pos - 2); i++)
        {
            q = (*(q)).next;
        }
        r = (*(q)).next;
        (*(q)).next = (*(r)).next;
        free(r);
    }
}
int main()
{
    struct node *a = NULL;
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    a = first;
    a = first->next->next->next->next;
    (*(a)).next = first;
    display(first);
    int num;
    /*printf("\nHow many numbers do you want to insert?\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        printf("Enter number to be inserted:\n");
        int n;
        scanf("%d", &n);
        printf("Enter position:\n");
        int pos;
        scanf("%d", &pos);
        insert(first, pos, n);
        display(first);
    }*/
    printf("\nHow many numbers are to be deleted?\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the position ofnumber to be deleted:\n");
        int num;
        scanf("%d", &num);
        delete (first, num);
        display(first);
    }
}