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
    (*(first)).next = NULL;
    (*(first)).prev = NULL;
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
void delete (struct node *p, int pos)
{
    struct node *z = NULL;
    if (first == NULL)
    {
        printf("\nNULL LINKED LIST\n");
    }
    else
    {
        if (pos == 1)
        {
            z = first;
            first = (*(z)).next;
            if (first != NULL)
            {
                (*(first)).prev = NULL;
            }
            free(z);
        }
        else
        {
            z = first;
            for (int i = 0; i < (pos - 1); i++)
            {
                z = (*(z)).next;
            }
            (*(z)).prev->next = (*(z)).next;
            if ((*(z)).next != NULL)
            {
                (*(z)).next->prev = (*(z)).prev;
            }
            free(z);
        }
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
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    printf("\nEnter how many numbers are to be deleted?\n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter position:\n");
        int pos;
        scanf("%d", &pos);
        delete (first, pos);
        display(first);
    }
}