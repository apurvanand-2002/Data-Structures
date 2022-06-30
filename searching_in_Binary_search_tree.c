#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
/*Binary tree is made using queue and traversal is done using stack.*/
struct queue
{
    int size;
    int front;
    int rear;
    struct node **A;
};
void qcreate(struct queue *q)
{
    (*(q)).size = 100;
    (*(q)).front = (*(q)).rear = 0; // circular queue
    (*(q)).A = (struct node **)malloc((*(q)).size * sizeof(struct node *));
}
void enqueue(struct queue *q, struct node *p)
{
    if (((*(q)).rear + 1) % (*(q)).size == (*(q)).front)
    {
        printf("Queue is full.\n");
    }
    else
    {
        (*(q)).rear = ((*(q)).rear + 1) % (*(q)).size;
        (*(q)).A[(*(q)).rear] = p;
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;
    if ((*(q)).front == (*(q)).rear)
    {
        return x;
    }
    else
    {
        (*(q)).front++;
        x = (*(q)).A[(*(q)).front];
        return x;
    }
}
int isempty(struct queue *q)
{
    if ((*(q)).front == (*(q)).rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *tcreate(struct queue *q)
{
    struct node *first = NULL;
    first = (struct node *)malloc(sizeof(struct node));
    struct queue *k = q;
    printf("Enter the data in root node:\n");
    scanf("%d", &(*(first)).data);
    (*(first)).lchild = (*(first)).rchild = NULL;
    enqueue(k, first);

    while (isempty(q) != 1)
    {
        struct node *p;
        p = dequeue(k);
        printf("Enter data in left child of %d(Enter '-1' if no child exists):\n", (*(p)).data);
        int num;
        scanf("%d", &num);
        if (num != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = num;
            (*(p)).lchild = t;
            (*(t)).lchild = (*(t)).rchild = NULL;
            enqueue(k, t);
        }

        printf("Enter data in right child of %d(Enter '-1' if no child exists):\n", (*(p)).data);
        int n;
        scanf("%d", &n);
        if (n != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = n;
            (*(p)).rchild = t;
            (*(t)).lchild = (*(t)).rchild = NULL;
            enqueue(k, t);
        }
    }
    return first;
}
void inorder_traversal(struct node *p) /*In-order traversal of a BST gives a sorted array.*/
{
    if (p != NULL)
    {
        inorder_traversal((*(p)).lchild);
        printf("%d ", (*(p)).data);
        inorder_traversal((*(p)).rchild);
    }
}
struct node *recursive_search(struct node *p, int num)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if ((*(p)).data == num)
    {
        return p;
    }
    else if ((*(p)).data < num)
    {
        recursive_search((*(p)).rchild, num);
    }
    else if ((*(p)).data > num)
    {
        recursive_search((*(p)).lchild, num);
    }
}
struct node *iterative_search(struct node *p, int num)
{
    while (p != NULL)
    {
        if ((*(p)).data == num)
        {
            return p;
        }
        else if ((*(p)).data < num)
        {
            p = (*(p)).rchild;
        }
        else if ((*(p)).data > num)
        {
            p = (*(p)).lchild;
        }
    }
    return NULL;
}
void main()
{
    struct node *first, *second, *third;
    first = NULL;
    third = NULL;
    struct queue q;
    qcreate(&q);
    first = tcreate(&q);
    printf("\nEnter the element to be searched:\n");
    int find;
    scanf("%d", &find);
    printf("Element %d is present at address: %x.\n", find, recursive_search(first, find));
    printf("Element %d is present at address: %x.\n", find, iterative_search(first, find));
}