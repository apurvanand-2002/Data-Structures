#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
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
        printf("Queue is full\n");
    }
    else
    {
        (*(q)).rear = ((*(q)).rear + 1) % (*(q)).size;
        (*(q)).A[(*(q)).rear] = p;
    }
}
struct node *dequeue(struct queue *p)
{
    struct node *x = NULL;
    if ((*(p)).rear == (*(p)).front)
    {
        return x;
    }
    else
    {
        (*(p)).front = ((*(p)).front + 1) % (*(p)).size;
        x = (*(p)).A[(*(p)).front];
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
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in the root:\n");
    scanf("%d", &(*(first)).data);
    (*(first)).lchild = (*(first)).rchild = NULL;
    enqueue(q, first);

    while (isempty(q) != 1)
    {
        struct node *p = NULL;
        p = dequeue(q);
        printf("Enter data in left child of %d (Enter -1 if no child exists):\n", (*(p)).data);
        int num;
        scanf("%d", &num);
        if (num != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = num;
            (*(p)).lchild = t;
            (*(t)).lchild = (*(t)).rchild = NULL;
            enqueue(q, t);
        }

        printf("Enter right child of %d (Enter -1 if no child exists):\n", (*(p)).data);
        int n;
        scanf("%d", &n);
        if (n != (-1))
        {
            struct node *s;
            s = (struct node *)malloc(sizeof(struct node));
            (*(s)).data = n;
            (*(p)).rchild = s;
            (*(s)).lchild = (*(s)).rchild = NULL;
            enqueue(q, s);
        }
    }
    return first;
}
void preorder(struct node *q)
{
    if (q != NULL)
    {
        printf("%d ", (*(q)).data);
        preorder((*(q)).lchild);
        preorder((*(q)).rchild);
    }
}
void inorder(struct node *q)
{
    if (q != NULL)
    {
        inorder((*(q)).lchild);
        printf("%d ", (*(q)).data);
        inorder((*(q)).rchild);
    }
}
void postorder(struct node *q)
{
    if (q != NULL)
    {
        postorder((*(q)).lchild);
        postorder((*(q)).rchild);
        printf("%d ", (*(q)).data);
    }
}
int main()
{
    struct queue q;
    qcreate(&q);
    struct node *first = NULL;
    first = tcreate(&q);
    preorder(first);
    printf("\n");
    inorder(first);
    printf("\n");
    postorder(first);
}