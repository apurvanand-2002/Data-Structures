/*Linked list is only created in heap.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void push(struct node *p, int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("\nStack overflow!\n");
    }
    else
    {
        (*(t)).data = num;
        (*(t)).next = first;
        first = t;
        t = NULL;
    }
}
int pop(struct node *p)
{
    int x = (-1);
    struct node *q = NULL;
    if (p == NULL)
    {
        printf("\nStack underflow!\n");
        return x;
    }
    else
    {
        q = first;
        x = (*(q)).data;
        first = (*(q)).next;
        free(q);
        q = NULL;
    }
}
int peek(struct node *p, int pos)
{
    struct node *q = NULL;
    int x = (-1);
    if (p == NULL)
    {
        return x;
    }
    else
    {
        q = first;
        for (int i = 0; q != NULL && i < (pos - 1); i++)
        {
            q = (*(q)).next;
        }
        if (q != NULL)
        {
            x = (*(q)).data;
        }
        else
        {
            x = (-1);
        }
        return x;
    }
}
int stacktop(struct node *p)
{
    int x = (-1);
    if (p == NULL)
    {
        return x;
    }
    else
    {
        x = (*(p)).data;
        return x;
    }
}
int isempty(struct node *p)
{
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct node *p)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", (*(p)).data);
        p = (*(p)).next;
    }
}
int main()
{
    push(first, 1);
    push(first, 2);
    push(first, 3);
    push(first, 4);
    display(first);
    printf("\n%d is at 3 position from top.\n", peek(first, 3));
    printf("\n%d is popped out!\n", pop(first));
    display(first);
    printf("\n%d is at top of the stack.\n", stacktop(first));
    if (isfull(first) == 1)
    {
        printf("\nFULL\n");
    }
    else
    {
        printf("\nNOT FULL\n");
    }
    pop(first);
    pop(first);
    pop(first);
    pop(first);
    if (isempty(first) == 1)
    {
        printf("\nEMPTY\n");
    }
    else
    {

        printf("\nNOT EMPTY\n");
    }
}