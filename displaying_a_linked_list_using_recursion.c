#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; /*Self-referential pointer*/
} *first = NULL;
void create(int A[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    (*(first)).data = A[0];
    (*(first)).next = NULL;
    struct node *t, *last;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        (*(t)).data = A[i];
        (*(t)).next = NULL;
        (*(last)).next = t;
        last = t;
    }
}
void display(struct node *p)
{
    if (p != NULL) /*Don't use while,as function is called multiple times so, we must
                        use if to check condition in each recursive call.*/
    {
        display((*(p)).next);
        printf("%d\t", (*(p)).data);
    }
}
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
}