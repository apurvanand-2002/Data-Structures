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
    struct node **A; /*as here array would be made from addresses of the nodes
                      ,these addresses are stored by pointers ,so,this array is a
                      collection of pointers.*/
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
        printf("Queue is full!\n");
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
        (*(q)).front = ((*(q)).front + 1) % (*(q)).size;
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
    struct node *a;
    a = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in root:\n");
    scanf("%d", &(*(a)).data);
    (*(a)).lchild = (*(a)).rchild = NULL;
    enqueue(q, a);
    // struct node *z;
    // z = first;
    while (isempty(q) != 1)
    {
        struct node *p;
        p = dequeue(q);
        printf("Enter data in left child of %d:\n", (*(p)).data);
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

        printf("Enter data in right child of %d:\n", (*(p)).data);
        int n;
        scanf("%d", &n);
        if (n != (-1))
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            (*(t)).data = n;
            (*(p)).rchild = t;
            (*(t)).lchild = (*(t)).rchild = NULL;
            enqueue(q, t);
        }
    }
    return a;
}
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", (*(p)).data);
        preorder((*(p)).lchild);
        preorder((*(p)).rchild);
    }
}
void inorder(struct node *p)
{
    if (p)
    {
        inorder((*(p)).lchild);
        printf("%d ", (*(p)).data);
        inorder((*(p)).rchild);
    }
}
void postorder(struct node *p)
{
    if (p)
    {
        postorder((*(p)).lchild);
        postorder((*(p)).rchild);
        printf("%d ", (*(p)).data);
    }
}
int main()
{
    struct queue q;
    qcreate(&q);
    struct node *first = NULL;
    first = tcreate(&q);
    inorder(first);
    printf("\n");
    preorder(first);
    printf("\n");
    postorder(first);
}