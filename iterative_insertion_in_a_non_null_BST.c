#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
/*BT is made using queue and traversal is done using stack.*/
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
    (*(q)).front = (*(q)).rear = 0;
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
    if ((*(q)).rear == (*(q)).front)
    {
        printf("Queue is empty.");
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
struct node *tcreate(struct node *p, struct queue *q)
{
    struct node *first = NULL;
    first = p;
    first = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in root:\n");
    scanf("%d", &(*(first)).data);
    (*(first)).lchild = (*(first)).rchild = NULL;
    enqueue(q, first);

    while (isempty(q) != 1)
    {
        struct node *p;
        p = dequeue(q);
        printf("Enter data in left child of %d(Enter '-1' if no child exists):\n", (*(p)).data);
        int num;
        scanf("%d", &num);
        if (num != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = num;
            (*(t)).lchild = (*(t)).rchild = NULL;
            (*(p)).lchild = t;
            enqueue(q, t);
        }
        printf("Enter data in right child of %d(Enter '-1' if no child exists):\n", (*(p)).data);
        int b;
        scanf("%d", &b);
        if (b != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = b;
            (*(t)).rchild = (*(t)).lchild = NULL;
            (*(p)).rchild = t;
            enqueue(q, t);
        }
    }
    return first;
}
void insert(struct node *p, int num)
{
    struct node *q;
    q = p;
    struct node *r = NULL;
    while (q != NULL)
    {
        r = q;
        if ((*(q)).data == num)
        {
            return;
        }
        else if ((*(q)).data < num)
        {
            q = (*(q)).rchild;
        }
        else if ((*(q)).data > num)
        {
            q = (*(q)).lchild;
        }
    }
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = num;
    (*(t)).lchild = (*(t)).rchild = NULL;
    if ((*(r)).data < num)
    {
        (*(r)).rchild = t;
    }
    else
    {
        (*(r)).lchild = t;
    }
}
void inorder_traversal(struct node *p)
{
    if (p != NULL)
    {
        inorder_traversal((*(p)).lchild);
        printf("%d ", (*(p)).data);
        inorder_traversal((*(p)).rchild);
    }
}
int main()
{
    struct queue q;
    struct node *first;
    qcreate(&q);
    first = tcreate(first, &q);
    inorder_traversal(first);
    printf("\nEnter number to be entered:\n");
    int n1;
    scanf("%d", &n1);
    insert(first, n1);
    printf("\n");
    inorder_traversal(first);
    printf("\nEnter number to be entered:\n");
    int n2;
    scanf("%d", &n2);
    insert(first, n2);
    printf("\n");
    inorder_traversal(first);
}