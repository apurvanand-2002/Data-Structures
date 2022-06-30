#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
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
    else
    {
        return 0;
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
/*Pointers in any rotation are written based on which-which pointer's realtive
positions and  elements have changeddue to rotations. And height changes are
 visible from the tree diagram ,else, height function can be assigned to all.*/
struct node *LLrotation(struct node *p)
{
    struct node *q = p;
    struct node *ql = (*(q)).lchild;
    struct node *qlr = (*(ql)).rchild;

    (*(ql)).rchild = q;
    (*(q)).lchild = qlr;
    (*(ql)).h = height(ql);
    (*(q)).h = height(q);
    return ql;
}
struct node *RRrotation(struct node *p)
{
}
struct node *RLrotation(struct node *p)
{
}
struct node *LRrotation(struct node *p)
{
    struct node *q = p;
    struct node *ql = (*(q)).lchild;
    struct node *qlr = (*(ql)).rchild;
    (*(q)).lchild = (*(qlr)).rchild;
    (*(ql)).rchild = (*(qlr)).rchild;
    (*(qlr)).lchild = ql;
    (*(qlr)).rchild = q;

    (*(qlr)).h = height(qlr);
    (*(q)).h = height(q);
    //(*(ql)).h = height(ql);
    p = qlr;
    return p;
}
struct node *insert(struct node *p, int num)
{
    struct node *q = NULL;
    q = p;
    struct node *z = NULL;
    z = p;
    if (q == NULL)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = num;
        (*(t)).h = 1;
        (*(t)).lchild = (*(t)).rchild = NULL;
        return t;
    }
    else if ((*(q)).data < num)
    {
        (*(q)).rchild = insert((*(q)).rchild, num);
    }
    else if ((*(q)).data > num)
    {
        (*(q)).lchild = insert((*(q)).lchild, num);
    }
    (*(q)).h = height(q);
    if (balancefactor(p) == (2) && balancefactor((*(p)).lchild) == (1))
    {
        printf("I am LL.\n");
        return LLrotation(p);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (-1))
    {
        // return RRrotation(z);
    }
    else if (balancefactor(p) == (2) && balancefactor((*(p)).lchild) == (-1))
    {
        printf("I am LR.\n");
        return LRrotation(z);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (1))
    {
        // return RLrotation(z);
    }

    return q;
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
    struct node *z = p;
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
            (*(p)).rchild = delete ((*(p)).rchild, num);
        }
        else if (height((*(p)).lchild) > height((*(p)).rchild))
        {
            z = inpre((*(p)).lchild);
            (*(p)).data = (*(z)).data;
            (*(p)).lchild = delete ((*(p)).lchild, num);
        }
    }
    (*(p)).h = height(p);

    if (balancefactor(p) == 2 && balancefactor((*(p)).lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (-1))
    {
        return RRrotation(p);
    }
    else if (balancefactor(p) == (2) && balancefactor((*(p)).lchild) == (-1))
    {
        return LRrotation(p);
    }
    else if (balancefactor(p) == (-2) && balancefactor((*(p)).rchild) == (1))
    {
        return RLrotation(p);
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
int main()
{
    struct node *first = NULL;
    first = insert(first, 20);
    struct node *q = first;
    first = insert(first, 10);
    first = insert(first, 5);
    first = insert(first, 30);
    first = delete (first, 20);
    inorder_traversal(first);
}
/*Deletion and insertion of nodes is done in same way in both BST AND AVL trees.
Only difference in AVL trees is that we need to include conditions for rotations based
on balance factor in AVL's node insertion and deletion.*/