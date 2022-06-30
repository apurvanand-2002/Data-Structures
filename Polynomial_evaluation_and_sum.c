/*Polynomial can be represented using sparse matrix.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct term
{
    int coeff;
    int power;
};
struct polynomial
{
    int num;
    struct term *t;
};
void create(struct polynomial *p)
{
    printf("Enter number of terms:\n");
    scanf("%d", &(*(p)).num);
    (*(p)).t = (struct term *)malloc((*(p)).num * sizeof(struct term));
    printf("Enter co-efficients along with their respective exponents:\n");
    for (int i = 0; i < (*(p)).num; i++)
    {
        scanf("%d %d", &(*(p)).t[i].coeff, &(*(p)).t[i].power);
    }
}
int evaluate(struct polynomial *p, int x)
{
    int sum = 0;
    for (int i = 0; i < (*(p)).num; i++)
    {
        sum = sum + ((*(p)).t[i].coeff * (pow(x, (*(p)).t[i].power)));
    }
    return sum;
}
struct polynomial sum(struct polynomial *p1, struct polynomial *p2)
{
    struct polynomial sum;
    sum.t = (struct term *)malloc(((*(p1)).num + (*(p2)).num) * sizeof(struct term));
    sum.num = (*(p1)).num + (*(p2)).num;
    static int i = 0, j = 0, k = 0;
    while (i < (*(p1)).num && j < (*(p2)).num)
    {
        if ((*(p1)).t[i].power > (*(p2)).t[j].power)
        {
            sum.t[k] = (*(p1)).t[i];
            k++;
            i++;
        }
        else if ((*(p1)).t[i].power < (*(p2)).t[j].power)
        {
            sum.t[k] = (*(p2)).t[j];
            k++;
            j++;
        }
        else
        {
            sum.t[k] = (*(p1)).t[i];
            sum.t[k].coeff += (*(p2)).t[j].coeff;
            k++;
            i++;
            j++;
        }
    }
    if (i < (*(p1)).num)
    {
        while (i != (*(p1)).num)
        {
            sum.t[k] = (*(p1)).t[i];
            i++;
            k++;
        }
    }
    if (j < (*(p2)).num)
    {
        while (j != (*(p2)).num)
        {
            sum.t[k] = (*(p2)).t[j];
            k++;
            j++;
        }
    }
    sum.num = k;
    return sum;
}
int main()
{
    struct polynomial p1, p2;
    create(&p1);
    create(&p2);
    struct polynomial p3 = (sum(&p1, &p2));
    printf("Value of polynomial at x=9 is %d.\n", evaluate(&p3, 1));
}