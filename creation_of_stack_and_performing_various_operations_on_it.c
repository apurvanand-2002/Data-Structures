#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *A;
};
void create(struct stack *s)
{
    printf("\nEnter size of stack:\n");
    scanf("%d", &(*(s)).size);
    (*(s)).A = (int *)malloc((*(s)).size * sizeof(int));
    (*(s)).top = (-1);
}
void push(struct stack *s, int num)
{
    if ((*(s)).top == ((*(s)).size - 1))
    {
        printf("Stack overflowed!\n");
    }
    else
    {
        (*(s)).top++;
        (*(s)).A[(*(s)).top] = num;
    }
}
int pop(struct stack *s)
{
    int x = (-1);
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
/*In peek or peep function, we give the input position of the element as we see the
stack from top. We develop a formula that uses 'top position' and position to convert
into our required index of the required element. So,index is the output.*/
int peek(struct stack *s, int pos)
{
    int x = (-1);
    if (pos < 0)
    {
        return x;
    }
    else
    {
        int index = (*(s)).top - pos + 1;
        x = (*(s)).A[index];
        return x;
    }
}
int stacktop(struct stack *s)
{
    int x = (-1);
    if ((*(s)).top == (-1))
    {
        return x;
    }
    else
    {
        x = (*(s)).A[(*(s)).top];
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
int isfull(struct stack *s)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct stack *s)
{
    int i = 0;
    for (; i <= (*(s)).top; i++)
    {
        printf("%d ", (*(s)).A[i]);
    }
    printf("\n");
}
int main()
{
    struct stack s;
    create(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    display(&s);
    // printf("\n%d is popped out.\n", pop(&s));
    // display(&s);
    printf("\n");
    // printf("%d is popped out.\n", pop(&s));
    // display(&s);
    printf("First element from top is %d.\n", peek(&s, 1));
    printf("Second element from top is %d.\n", peek(&s, 2));
    printf("Third element from top is %d.\n", peek(&s, 3));
    printf("Fourth element from top is %d.\n", peek(&s, 4));
    if (isfull(&s) == 1)
    {
        printf("IS FULL\n");
    }
    else
    {
        printf("IS NOT FULL\n");
    }
    if (isempty(&s) == 1)
    {
        printf("IS EMPTY\n");
    }
    else
    {
        printf("IS NOT EMPTY\n");
    }
    printf("\n%d is present at stack top.", stacktop(&s));
}
/*functions written here are: push,pop,peek,stacktop,isempty,isfull,display,create*/