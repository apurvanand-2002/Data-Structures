#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack // operands are numbers in character data type form.
{
    int size;
    int top;
    int *A;
};
void create(struct stack *s, char A[])
{
    (*(s)).size = strlen(A) + 1;
    (*(s)).top = (-1);
    (*(s)).A = (int *)malloc((*(s)).size * sizeof(int));
}
void push(struct stack *s, int b)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        (*(s)).top++;
        (*(s)).A[(*(s)).top] = b;
    }
}
int pop(struct stack *s)
{
    int c = (-1);
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
int stacktop(struct stack *s)
{
    int c = (-1);
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
int isoperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int postfix_evaluation(struct stack *s, char A[])
{
    int r;
    int x1, x2;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (isoperand(A[i]) == 1)
        {
            push(s, A[i] - '0');
        }
        else
        {
            x2 = pop(s); // integer data type
            x1 = pop(s); // integer data type
            switch (A[i])
            {
            case '+':
                push(s, x1 + x2);
                break;
            case '-':
                push(s, x1 - x2);
                break;
            case '*':
                push(s, x1 * x2);
                break;
            case '/':
                push(s, (x1 / x2));
                break;
            }
        }
    }
    r = stacktop(s);
    return r;
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
    printf("\nValue of postfix expression is %d.\n", postfix_evaluation(&s, A));
}