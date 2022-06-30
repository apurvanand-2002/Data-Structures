/*Binary tree is made using queue but traversal of binary tree is done using stack.*/
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
    (*(q)).front = (*(q)).rear = 0; // making circular queue for more efficiency
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
struct node *dequeue(struct queue *p)
{
    struct node *x = NULL;
    if ((*(p)).front == (*(p)).rear)
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
    printf("Enter the data in root node:\n");
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
            (*(p)).lchild = t;
            (*(t)).lchild = (*(t)).rchild = NULL;
            enqueue(q, t);
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
            (*(t)).rchild = (*(t)).lchild = NULL;
            enqueue(q, t);
        }
    }
    return first;
}
void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", (*(p)).data);
        preorder((*(p)).lchild);
        preorder((*(p)).rchild);
    }
}
void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder((*(p)).lchild);
        printf("%d ", (*(p)).data);
        inorder((*(p)).rchild);
    }
}
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder((*(p)).lchild);
        postorder((*(p)).rchild);
        printf("%d ", (*(p)).data);
    }
}
struct stack
{
    int size;
    int top;
    struct node **A;
};
void screate(struct stack *s)
{
    (*(s)).size = 100;
    (*(s)).top = (-1);
    (*(s)).A = (struct node **)malloc((*(s)).size * sizeof(struct node *));
}
void push(struct stack *s, struct node *p)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*(s)).top++;
        (*(s)).A[(*(s)).top] = p;
    }
}
struct node *pop(struct stack *s)
{
    struct node *x = NULL;
    if ((*(s)).top == (-1))
    {
        return x;
    }
    else
    {
        x = (*(s)).A[(*(s)).top];
        (*(s)).top--;
        return x;
    }
}
int sisempty(struct stack *s)
{
    if ((*(s)).top == (-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void iterative_preorder(struct node *p, struct stack *s)
{ // we need to make stack.
    struct node *t = p;
    struct stack *k = s;
    while (t != NULL || sisempty(k) != 1)
    {
        if (t != NULL)
        {
            printf("%d ", (*(t)).data);
            push(k, t);
            t = (*(t)).lchild;
        }
        else
        {
            t = pop(k);
            t = (*(t)).rchild;
        }
    }
}
void iterative_inorder(struct node *p, struct stack *s)
{
    struct node *t = p;
    struct stack *k = s;
    while (t != NULL || sisempty(k) != 1)
    {
        if (t != NULL)
        {
            push(k, t);
            t = (*(t)).lchild;
        }
        else
        {
            t = pop(s);
            printf("%d ", (*(t)).data);
            t = (*(t)).rchild;
        }
    }
}

void iterative_postorder(struct node *p, struct stack *s)
{
    struct node *t = p;
    struct stack *k = s;

    if (t != NULL)
    {
        push(k, t);
        t = (*(t)).lchild;
    }
    else
    {
        t = pop(k);
        if (t > 0)
        {
            push(s, -(int)t);
            t = (*(t)).rchild;
        }
        else
        {
            printf("%x ", pop(&s));
            t = NULL;
        }
    }
}
/*Binary tree is made using queue and its traversal is done using stack.While
making the binary tree, we enter its data level by level ,so, similar queue
method can be used for ontaining the level-order traversal.*/
void level_order_traversal(struct node *p, struct queue *q)
{
    struct node *t;
    t = p;
    printf("%d ", (*(t)).data);
    enqueue(q, t);

    while (isempty(q) != 1)
    {
        t = dequeue(q);
        struct node *a;
        a = (*(t)).lchild;
        if (a != NULL)
        {
            printf("%d ", (*(a)).data);
            enqueue(q, a);
        }
        a = (*(t)).rchild;
        if (a != NULL)
        {
            printf("%d ", (*(a)).data);
            enqueue(q, a);
        }
    }
}
int count_nodes(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count_nodes((*(p)).lchild);
        y = count_nodes((*(p)).rchild);
        return x + y + 1;
    }
    else
    {
        return 0;
    }
}
int nodes_of_degree_2(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = nodes_of_degree_2((*(p)).lchild);
        y = nodes_of_degree_2((*(p)).lchild);
        if ((*(p)).lchild != NULL && (*(p)).rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}
int leaf_nodes(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = leaf_nodes((*(p)).lchild);
        y = leaf_nodes((*(p)).rchild);
        if ((*(p)).lchild == NULL && (*(p)).rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}
int height(struct node *p)
{
    int fh = 0;
    int x = 0, y = 0;
    if (p != NULL)
    {
        x = height((*(p)).lchild);
        y = height((*(p)).rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    else
    {
        return 0;
    }
}
int sum(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = sum((*(p)).lchild);
        y = sum((*(p)).rchild);
        return x + y + (*(p)).data;
    }
    else
    {
        return 0;
    }
}
int nodes_degree_one_or_two(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = nodes_degree_one_or_two((*(p)).lchild);
        y = nodes_degree_one_or_two((*(p)).rchild);
        if ((*(p)).lchild == NULL && (*(p)).rchild != NULL || (*(p)).lchild != NULL && (*(p)).rchild == NULL || (*(p)).lchild != NULL && (*(p)).rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}
int degree_one(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = degree_one((*(p)).lchild);
        y = degree_one((*(p)).rchild);
        if ((*(p)).lchild != NULL && (*(p)).rchild == NULL || (*(p)).lchild == NULL && (*(p)).rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct node *first = NULL;
    struct queue q;
    struct stack s;
    screate(&s);
    qcreate(&q);
    first = tcreate(&q);
    printf("\nPreorder traversal of binary tree is:\n");
    preorder(first);
    printf("\nInorder traversal of binary tree is:\n");
    inorder(first);
    printf("\nPostorder traversal of binary tree is:\n");
    postorder(first);
    printf("\n");
    printf("Pre-order traversal using interation:\n");
    iterative_preorder(first, &s);
    printf("\n");
    printf("In-order traversal using interation:\n");
    iterative_inorder(first, &s);
    printf("\n");
    printf("Post-order traversal using interation:\n");
    iterative_postorder(first, &s);
    printf("Level-order traversal using interation:\n");
    level_order_traversal(first, &q);
    printf("\n");
    printf("Total number of nodes in the binary tree is %d.\n", count_nodes(first));
    printf("\n");
    printf("Total number of 2 degree nodes in the binary tree is %d.\n", nodes_of_degree_2(first));
    printf("\n");
    printf("Total number of leaf nodes in the binary tree is %d.\n", leaf_nodes(first));
    printf("\n");
    printf("Height of the binary tree is %d.\n", height(first));
    printf("\n");
    printf("Sum of the elements of binary tree is %d.\n", sum(first));
    printf("\n");
    printf("Total number of nodes of degree 1 and 2 are %d.\n", nodes_degree_one_or_two(first));
    printf("\n");
    printf("Total number of nodes of degree 1 are %d.\n", degree_one(first));
}
/*pre-order and post-order shows the linking of nodes,where pre-order shows the
linking from left and post order shows the linking from the right.
Whereas inorder shows which nodes are to the left and right w.r.t. to a particular
node.*/