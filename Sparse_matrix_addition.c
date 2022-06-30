#include <stdio.h>
#include <stdlib.h>
struct element
{
    int a; // element's row number
    int b; // element's column number
    int c; // element's numerical value
};
struct sparse
{
    int m;   // total number of rows
    int n;   // total number of columns
    int num; // total number of non-zero elements
    struct element *e;
};
void create(struct sparse *s)
{
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &(*(s)).m, &(*(s)).n);
    printf("Enter the number of non-zero elements:\n");
    scanf("%d", &(*(s)).num);
    (*(s)).e = (struct element *)malloc((*(s)).num * sizeof(int));
    printf("Enter row,column and numerical value of each non-zero element:\n");
    for (int i = 0; i < (*(s)).num; i++)
    {
        scanf("%d %d %d", &(*(s)).e[i].a, &(*(s)).e[i].b, &(*(s)).e[i].c);
    }
}
struct sparse *sum(struct sparse *s1, struct sparse *s2)
{
    struct sparse *sum;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    if ((*(s1)).m != (*(s2)).m && (*(s1)).n != (*(s2)).n)
    {
        return NULL;
    }
    else
    {
        (*(sum)).m = (*(s1)).m;
        (*(sum)).n = (*(s1)).n;
        static int i = 0, j = 0, k = 0;
        (*(sum)).e = (struct element *)malloc(((*(s1)).num + (*(s2)).num) * sizeof(struct element));
        while (i < (*(s1)).num && j < (*(s2)).num)
        {
            if ((*(s1)).e[i].a < (*(s2)).e[j].a)
            {
                (*(sum)).e[k] = (*(s1)).e[i];
                i++;
                k++;
            }
            else if ((*(s1)).e[i].a > (*(s2)).e[j].a)
            {
                (*(sum)).e[k] = (*(s2)).e[j];
                k++;
                j++;
            }
            else
            {
                if ((*(s1)).e[i].b < (*(s1)).e[j].b)
                {
                    (*(sum)).e[k] = (*(s1)).e[i];
                    k++;
                    i++;
                }
                else if ((*(s1)).e[i].b > (*(s2)).e[j].b)
                {
                    (*(sum)).e[k] = (*(s2)).e[j];
                    k++;
                    j++;
                }
                else
                {
                    (*(sum)).e[k] = (*(s1)).e[i];
                    (*(sum)).e[k].c += (*(s2)).e[j].c;
                    k++;
                    i++;
                    j++;
                }
            }
        }
        if (i < (*(s1)).num)
        {
            while (i != (*(s1)).num)
            {
                (*(sum)).e[k] = (*(s1)).e[i];
                k++;
                i++;
            }
        }
        if (j < (*(s2)).num)
        {
            while (j != (*(s2)).num)
            {
                (*(sum)).e[k] = (*(s2)).e[j];
                k++;
                j++;
            }
        }
        (*(sum)).num = k;
    }
    return sum;
}
void display(struct sparse *s)
{
    int k = 0;
    for (int i = 0; i < (*(s)).m; i++)
    {
        for (int j = 0; j < (*(s)).n; j++)
        {
            if (i == (*(s)).e[k].a && j == (*(s)).e[k].b)
            {
                printf("%d\t", (*(s)).e[k].c);
                k++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct sparse s1, s2;
    create(&s1);
    printf("First Sparse Matrix is:\n");
    display(&s1);
    create(&s2);
    printf("Second Sparse Matrix is:\n");
    display(&s2);
    printf("SUM IS:\n");
    display(sum(&s1, &s2));
}