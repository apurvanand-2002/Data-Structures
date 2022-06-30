/*Radix or base of a decimal number= 10, so, we will make a bin i.e. array of pointers of
size 10.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **p, int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = num;

    if ((*(p)) == NULL)
    {
        (*p) = t;
        (*(t)).next = NULL;
    }
    else
    {
        struct node *t1 = (*p);
        while (t1->next != NULL)
        {
            t1 = (*(t1)).next;
        }
        (*(t1)).next = t;
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
        t = (*(p));
        int x = (*(t)).data;
        (*(p)) = (*p)->next;
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
int count_n_digits(int num)
{
    int x = 0;
    while (num != 0)
    {
        num = num / 10;
        x++;
    }
    return x;
}
int main()
{
    int A[] = {123, 223, 333, 443, 553, 663, 773};
    int n = 7;
    struct node **bin;
    bin = (struct node **)malloc(10 * sizeof(struct node *));
    for (int i = 0; i < 10; i++)
    {
        bin[i] = NULL;
    }
    int j = 0, k = 0;
    int pass = count_n_digits(max(A, n));
    while (k < pass)
    {
        static int b = 1;
        for (int i = 0; i < n; i++)
        {
            int a = (A[i] / b) % 10;
            insert(&bin[a], A[i]);
        }
        int g = 0, h = 0; //'g' for A,'h' for bin
        while (g < n)
        {
            if (bin[h] == NULL)
            {
                h++;
            }
            else
            {
                while (bin[h] != NULL)
                {
                    A[g] = delete (&bin[h]);
                    g++;
                }
                h++;
            }
        }
        b = (b * 10);
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}