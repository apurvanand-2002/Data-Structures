#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *A;
};
void push(struct stack *s, int num)
{
    if ((*(s)).top == (*(s)).size - 1)
    {
        printf("Stack is full!\n");
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
int isempty(struct stack *s)
{
    if ((*(s)).top == (-1))
    {
        return (1);
    }
    else
    {
        return 0;
    }
}
void create(struct stack *s)
{
    (*(s)).size = 100;
    (*(s)).top = (-1);
    (*(s)).A = (int *)malloc(100 * sizeof(int));
}
void enqueue(struct stack *s1, int num)
{
    push(s1, num);
}
int dequeue(struct stack *s1, struct stack *s2)
{
    if (isempty(s2) == 1)
    {
        if (isempty(s1) == 0)
        {
            while ((*(s1)).top != (-1))
            {
                push(s2, pop(s1));
            }
            return pop(s2);
        }
        else
        {
            printf("Queue empty:Error ");
            return (-1);
        }
    }
    else
    {
        return pop(s2);
    }
}
int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct stack s1, s2;
    create(&s1);
    create(&s2);
    for (int i = 0; i < 10; i++)
    {
        enqueue(&s1, A[i]);
    }
    for (int i = 1; i <= 12; i++)
    {
        printf("%d number-dequeue:%d\n", i, dequeue(&s1, &s2));
        /*Follows stack i.e. first in first out.*/
    }
}