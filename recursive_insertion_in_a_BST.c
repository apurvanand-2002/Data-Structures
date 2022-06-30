#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *insert(struct node *p, int num)
{
    struct node *q;
    q = p;
    if (q == NULL)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).lchild = (*(t)).rchild = NULL;
        (*(t)).data = num;
        return t;
    }
    if ((*(q)).data < num)
    {
        (*(q)).rchild = insert((*(q)).rchild, num);
    }
    if ((*(q)).data > num)
    {
        (*(q)).lchild = insert((*(q)).lchild, num);
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
    struct node *z = NULL;
    z = insert(z, 10);
    insert(z, 20);
    insert(z, 5);
    insert(z, 15);
    insert(z, 80);
    insert(z, 50);
    insert(z, 44);
    inorder_traversal(z);
}