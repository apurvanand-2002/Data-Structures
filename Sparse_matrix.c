#include <stdio.h>
#include <stdlib.h>
struct element
{
    int a; // row number
    int b; // column number
    int c; // element
};
struct sparse
{
    int m;   // Total number of rows
    int n;   // Total number of columns
    int num; // Total number of non-zero elements
    struct element *e;
};
void create(struct sparse *s)
{
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &(*(s)).m, &(*(s)).n);
    printf("Enter total number of non-zero elements:\n");
    scanf("%d", &(*(s)).num);
    (*(s)).e = (struct element *)malloc((*(s)).num * sizeof(struct element));
    printf("Enter the non-zero elements:\n");
    for (int i = 0; i < (*(s)).num; i++)
    {
        scanf("%d %d %d", &(*(s)).e[i].a, &(*(s)).e[i].b, &(*(s)).e[i].c);
    }
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
    struct sparse s;
    create(&s);
    printf("Corresponding sparse matrixx is :\n");
    display(&s);
}