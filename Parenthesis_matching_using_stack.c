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
    (*(s)).A = (char *)malloc((*(s)).size * sizeof(char));
    (*(s)).top = (-1);
}
void push(struct stack *s, char c)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        (*(s)).top++;
        (*(s)).A[(*(s)).top] = c;
    }
}
int pop(struct stack *s)
{
    char x = '*';
    if ((*(s)).top == (-1))
    {
        return x;
    }
    else
    {
        x = (*(s)).A[(*(s)).top];
        (*(s)).top--;
        return x;
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
int parenthesis_matcher(struct stack *s, char A[]) // character array=string
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(')
        {
            push(s, A[i]);
        }
        else if (A[i] == ')')
        {
            if (isempty(s) == 1)
            {
                return 0;
            }
            else
            {
                pop(s);
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
    struct stack o;
    char A[100];
    printf("Enter an expression:\n");
    gets(A);
    printf("\nExpression entered is:\n");
    puts(A);
    create(&o, A);
    if (parenthesis_matcher(&o, A) == 1)
    {
        printf("Parenthesis are balanced!\n");
    }
    else
    {
        printf("Parenthesis are not balanced!\n");
    }
}
/*In parenthesis matching,we assume that ) appears only when atleast one ( must be
present before it. So, if ) appears at first element in a string ,we straight-away
say that it is not matched.*/