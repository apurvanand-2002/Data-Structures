#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *first = NULL;
void insert(int num)
{
    struct node *q = first;
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
    if (first == NULL) // we are taking first and not 'q' as q is NULL due to previous while loop
    {
        first = t;
    }
    else
    {
        if ((*(r)).data < num)
        {
            (*(r)).rchild = t;
        }
        else if ((*(r)).data > num)
        {
            (*(r)).lchild = t;
        }
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
void main()
{
    insert(20);
    insert(30);
    insert(10);
    insert(15);
    insert(40);
    inorder_traversal(first);
}