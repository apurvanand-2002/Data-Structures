#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *A;
};
void create(struct stack *s, char A[])
{
    (*(s)).size = strlen(A);
    (*(s)).top = (-1);
    (*(s)).A = (char *)malloc(sizeof(struct stack));
}
void push(struct stack *s, char c)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack overloaded\n");
    }
    else
    {
        (*(s)).top++;
        (*(s)).A[(*(s)).top] = c;
    }
}
char pop(struct stack *s)
{
    char c = '*';
    if ((*(s)).top == (-1))
    {
        return c;
    }
    else
    {
        c = (*(s)).A[(*(s)).top];
        (*(s)).top--;
        return c;
    }
}
int isempty(struct stack *s)
{
    if ((*(s)).top == (-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperand(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 0;
    }
    return 1;
}
int precedence(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
}
char stacktop(struct stack *s)
{
    char c = '\0';
    if ((*(s)).top == (-1))
    {
        return c;
    }
    else
    {
        c = (*(s)).A[(*(s)).top];
        return c;
    }
}
char *in_to_po(struct stack *s, char A[])
{
    char *B;
    B = (char *)malloc((strlen(A) + 1) * sizeof(char));
    static int i = 0, j = 0;
    while (A[i] != '\0')
    {
        if (isoperand(A[i]) == 1)
        {
            B[j] = A[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(A[i]) > precedence(stacktop(s)))
            {
                push(s, A[i]);
                i++;
            }
            if (precedence(A[i]) <= precedence(stacktop(s)))
            {
                B[j] = pop(s);
                j++;
            }
        }
    }
    while ((*(s)).top != (-1))
    {
        B[j] = pop(s);
        j++;
    }
    B[j] = '\0';
    return B;
}
int main()
{
    struct stack s;
    printf("Enter the expression:\n");
    char A[100];
    gets(A);
    printf("\nEntered expression is:\n");
    puts(A);
    create(&s, A);
    printf("\nPostfixed form is:\n");
    char *q = in_to_po(&s, A);
    printf("%s", q);
}