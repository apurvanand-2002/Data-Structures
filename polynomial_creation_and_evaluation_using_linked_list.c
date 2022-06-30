#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
} *first = NULL;
void insert(struct node *p, int pow, int co)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).coeff = co;
    (*(t)).power = pow;
    struct node *q = NULL;
    if (p == NULL)
    {
        first = q = t; /*Though we have defined p but during use in
                        function also ,we must always use first ,it gives the required
                        results.*/
        (*(t)).next = NULL;
    }
    else
    {
        q = first;
        while ((*(q)).next != NULL)
        {
            q = (*(q)).next;
        }
        (*(q)).next = t;
        (*(t)).next = NULL;
    }
    /*struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).coeff = co;
    (*(t)).power = pow;
    struct node *last = NULL;
    if (p == NULL)
    {
        first = last = t;
        (*(t)).next = NULL;
    }
    else
    {
        (*(last)).next = t;
        last = t;
        (*(t)).next = NULL;
    }*/
}
void expression(struct node *p)
{
    while (p != NULL)
    {
        printf("%dx(%d)+", (*(p)).coeff, (*(p)).power);
        p = (*(p)).next;
    }
}
int evaluation(struct node *p, int x)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + ((*(p)).coeff * pow(x, (*(p)).power));
        p = (*(p)).next;
    }
    return sum;
}
int main()
{
    printf("\nHow many terms are there in the expression?\n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter coefficient and power:\n");
        int coeff, pow;
        scanf("%d %d", &coeff, &pow);
        insert(first, pow, coeff);
        expression(first);
        printf("\nEnter value of variable:\n");
        int val;
        scanf("%d", &val);
        printf("Value of expression is:%d\n", evaluation(first, val));
    }
}