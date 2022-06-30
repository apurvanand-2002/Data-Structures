#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; // self-referential pointer
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
void enqueue(struct node *p, int num)
{ // addition takes place at rear end.
    struct node *front = NULL, *rear = NULL;
    front = first;
    while (p != NULL && (*(p)).next != NULL) /* p!=NULL is added since,the next
                                              condition (*(p)).next!=NULL may or may not
                                              be defined as we don't know what is next to
                                              a null.*/
    {
        p = (*(p)).next;
    }
    rear = p;
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Queue is full!\n");
    }
    else
    {
        (*(t)).data = num;
        if (first == NULL)
        {
            first = t;
            front = rear = t;
            (*(t)).next = NULL;
            // t = NULL;
        }
        else
        {
            (*(rear)).next = t;
            (*(t)).next = NULL;
            rear = t;
            t = NULL;
        }
    }
}
int dequeue(struct node *p)
{ // dequeue:deletion from front end
    struct node *front = NULL, *rear = NULL;
    front = first;
    while (p != NULL && (*(p)).next != NULL)
    {
        p = (*(p)).next;
    }
    rear = p;
    if (first == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        struct node *p1;
        p1 = first;
        first = (*(p1)).next;
        free(p1);
        p1 = NULL;
    }
}
void display(struct node *p)
{
    if (p == NULL)
    {
        printf("Queue is NULL");
    }
    else
    {
        struct node *front = NULL, *rear = NULL;
        front = first;
        while (p != NULL && (*(p)).next != NULL)
        {
            p = (*(p)).next;
        }
        rear = p;
        p = first;
        do
        {
            printf("%d ", (*(p)).data);
            p = (*(p)).next;
        } while (p != (*(rear)).next);
    }
}
int main()
{
    // int A[3] = {1, 2, 3};
    // create(A, 3);
    dequeue(first);
    enqueue(first, 4);
    enqueue(first, 5);
    enqueue(first, 6);
    enqueue(first, 7);
    enqueue(first, 8);
    // dequeue(first);

    // dequeue(first);
    // dequeue(first);
    // dequeue(first);
    // dequeue(first);
    // dequeue(first);
    // dequeue(first);

    display(first);
}