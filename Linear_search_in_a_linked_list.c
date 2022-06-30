#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
    while (p != NULL)
    {
        printf("%d\t", (*(p)).data);
        p = (*(p)).next;
    }
}
int linear_search(struct node *p, int n)
{
    static int count = 1;
    while (p != NULL)
    {
        if ((*(p)).data != n)
        {
            p = (*(p)).next;
            count++;
        }
        else
        {
            return count; /*As soon as function encounters any of the return
                          statements ,it breaks out from the function and function is not
                          executed further .So, though repetitions of any elemental data
                          may occur in the linked list but function will return only
                          the position of the first place at which it finds the required
                          element.*/
        }
    }
    return (-1);
}
struct node *lsearch_address(struct node *p, int n)
{
    while (p != NULL)
    {
        if ((*(p)).data == n)
        {
            return p;
        }
        else
        {
            p = (*(p)).next;
        }
    }
    return NULL;
}
struct node *recursive_lsearch_address(struct node *p, int n)
{
    if (p != NULL)
    {
        if ((*(p)).data != n)
        {
            recursive_lsearch_address((*(p)).next, n);
        }
        else
        {
            return p;
        }
    }
    else
    {
        return NULL;
    }
}
int main()
{
    int A[10] = {10, 20, 40, 40, 40, 60, 970, 80, 90, 100};
    create(A, 10);
    display(first);
    printf("\nEnter the number to be found:\n");
    int num;
    scanf("%d", &num);
    printf("\n%d is found at node:%x.\n", num, recursive_lsearch_address(first, num));
}