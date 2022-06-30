#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *insert(struct node *q, int num)
{
    struct node *p = q;
    if (p == NULL)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = num;
        (*(t)).lchild = (*(t)).rchild = NULL;
        return t;
    }
    else if ((*(p)).data < num)
    {
        (*(p)).rchild = insert((*(p)).rchild, num);
    }
    else if ((*(p)).data > num)
    {
        (*(p)).lchild = insert((*(p)).lchild, num);
    }
    return p;
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
int height(struct node *p)
{
    int x, y;
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
}
struct node *inpre(struct node *p)
{
    while (p != NULL && (*(p)).rchild != NULL)
    {
        p = (*(p)).rchild;
    }
    return p;
}
struct node *insucc(struct node *p)
{
    while (p != NULL && (*(p)).lchild != NULL)
    {
        p = (*(p)).lchild;
    }
    return p;
}
struct node *delete (struct node *q, int num)
{
    struct node *p = q;
    struct node *t = q;
    struct node *z = NULL;
    if (p == NULL)
    {
        return NULL;
    }
    if ((*(p)).lchild == NULL && (*(p)).rchild == NULL)
    {
        free(p);
        return NULL;
    }
    if ((*(p)).data < num)
    {
        (*(p)).rchild = delete ((*(p)).rchild, num);
    }
    else if ((*(p)).data > num)
    {
        (*(p)).lchild = delete ((*(p)).lchild, num);
    }
    else
    {
        if (height((*(p)).lchild) < height((*(p)).rchild))
        {
            z = insucc((*(p)).rchild);
            (*(p)).data = (*(z)).data;
            (*(p)).rchild = delete ((*(p)).rchild, (*(z)).data);
        }
        else if (height((*(p)).lchild) > height((*(p)).rchild))
        {
            z = inpre((*(p)).lchild);
            (*(p)).data = (*(z)).data;
            (*(p)).lchild = delete ((*(p)).lchild, (*(z)).data);
        }
    }
    return p;
}
int main()
{
    struct node *first = NULL;
    first = insert(first, 8);
    first = insert(first, 3);
    first = insert(first, 5);
    first = insert(first, 10);
    first = insert(first, 9);
    first = insert(first, 7);
    first = insert(first, 1);
    first = delete (first, 3);
    first = delete (first, 7);
    inorder_traversal(first);
}