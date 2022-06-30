#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
    int h;
};
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
int balancefactor(struct node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height((*(p)).lchild);
        y = height((*(p)).rchild);
        return x - y;
    }
    else
    {
        return 0;
    }
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct node *LLrotation(struct node *p)
{
    struct node *q;
    q = p;
    struct node *z = p;
    struct node *ql;
    ql = (*(q)).lchild;
    struct node *qlr;
    qlr = (*(ql)).rchild;

    (*(ql)).rchild = q;
    (*(q)).lchild = qlr;

    (*(q)).h = height(q);
    (*(ql)).h = height(q);
    return ql;
}
struct node *RRrotation(struct node *p)
{
}
struct node *LRrotation(struct node *p)
{
}
struct node *RLrotation(struct node *p)
{
}
struct node *insert(struct node *q, int num)
{
    struct node *p = q; /*p due to traversing will reach any other position and will not
                          remain at node position.*/
    struct node *z = q;
    if (p == NULL)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = num;
        (*(t)).h = 1;
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

    (*(p)).h = height(p);
    if (balancefactor(p) == 2 && balancefactor((*(p)).lchild) == 1)
    {
        printf("LL\n");
        return LLrotation(p);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (-1))
    {
        return RRrotation(p);
    }
    else if (balancefactor(p) == (2) && balancefactor((*(p)).lchild) == (-1))
    {
        printf("I am LR.\n");
        return LRrotation(p);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (1))
    {
        return RLrotation(p);
    }

    return q;
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
    struct node *first = NULL;
    first = insert(first, 20);
    first = insert(first, 10);
    first = insert(first, 15);
    inorder_traversal(first);
}