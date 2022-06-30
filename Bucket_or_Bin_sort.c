#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
/*Bin or bucket sort uses an array of pointers,so, that name of the array will be
pointer to a pointer.
If 'p' is an array of pointers ,so, p[i] will represent a pointer of the array.*/
void insert(struct node **p, int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = num;
    if ((*p) == NULL)
    {
        *p = t;
        (*(t)).next = NULL;
    }
    else
    {
        (*(*(p))).next = t;
        (*(t)).next = NULL;
    }
}
int delete (struct node **p)
{
    if ((*p) == NULL)
    {
        return (-1);
    }
    else
    {
        struct node *t;
        int x;
        t = (*(p));
        x = (*(p))->data;
        (*(p)) = (*(p))->next;
        free(t);
        return x;
    }
}
int max(int A[], int n)
{
    int maxim = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > maxim)
        {
            maxim = A[i];
        }
    }
    return maxim;
}
int main()
{
    int A[] = {2, 1, 4, 5, 4, 6, 7, 5, 2, 6, 9, 0, 7};
    int m = max(A, 13);
    struct node **bin;
    bin = (struct node **)malloc((m + 1) * sizeof(struct node *));
    for (int i = 0; i < (m + 1); i++)
    {
        bin[i] = NULL;
    }
    for (int i = 0; i < 13; i++)
    {
        insert(&bin[A[i]], A[i]);
    }
    int j = 0, k = 0;
    while (k < (13))
    {
        if (bin[j] == NULL)
        {
            j++;
        }
        else
        {
            while (bin[j] != NULL)
            {
                A[k] = delete (&bin[j]);
                k++;
            }
            j++;
        }
    }
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", A[i]);
    }
}