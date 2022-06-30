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
    (*(s)).A = (char *)malloc((*(s)).size * sizeof(char));
}
void push(struct stack *s, char c)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack Overflow!\n");
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
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int parenthesis_matcher(struct stack *s, char A[])
{
    char popped;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            push(s, A[i]);
        }
        if (A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            popped = pop(s);
            if (match(popped, A[i]) == 0)
            {
                return 0;
            }
        }
    }
    if (isempty(s) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    printf("Enter any expression:\n");
    char A[100];
    gets(A);
    printf("\nEntered expression is:\n");
    puts(A);
    struct stack s;
    create(&s, A);
    if (parenthesis_matcher(&s, A) == 1)
    {
        printf("\nBALANCED\n");
    }
    else
    {
        printf("\nNOT BALANCED\n");
    }
}
/*Parenthesis Matching doesn't mean that only frequency of opening bracket (of any type)
must be equal to its closing counterpart but 
lastly opened bracket must be firstly closed by its closing counterpart.*/