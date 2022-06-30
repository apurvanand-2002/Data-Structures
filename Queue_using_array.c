#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *A;
};
void create(struct queue *q)
{
    printf("Enter the size of the queue:\n");
    scanf("%d", &(*(q)).size);
    (*(q)).front = (*(q)).rear = (-1);
    (*(q)).A = (int *)malloc((*(q)).size * sizeof(int));
}
void enqueue(struct queue *q, int num)
{
    if ((*(q)).rear == (*(q)).size - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        (*(q)).rear++;
        (*(q)).A[(*(q)).rear] = num;
    }
}
int dequeue(struct queue *q)
{
    int x = (-1);
    if ((*(q)).front == (*(q)).rear)
    {
        return x;
    }
    else
    {
        (*(q)).front++;
        x = (*(q)).A[(*(q)).front];
        return x;
    }
}
int isempty(struct queue *q)
{
    if ((*(q)).rear == (*(q)).front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct queue *q)
{
    if ((*(q)).rear == (*(q)).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int first(struct queue *q)
{
    int x = (-1);
    if ((*(q)).front == (*(q)).rear)
    {
        return x;
    }
    else
    {
        x = (*(q)).A[(*(q)).front + 1];
        return x;
    }
}
int last(struct queue *q)
{
    int x = (-1);
    if ((*(q)).front == (*(q)).rear)
    {
        return x;
    }
    else
    {
        x = (*(q)).A[(*(q)).rear];
        return x;
    }
}
void display(struct queue *q)
{
    if ((*(q)).front == (*(q)).rear)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for (int i = (*(q)).front + 1; i <= (*(q)).rear; i++)
        {
            printf("%d ", (*(q)).A[i]);
        }
    }
}
int main()
{
    struct queue p;
    create(&p);
    display(&p);
    enqueue(&p, 1);
    enqueue(&p, 2);
    enqueue(&p, 3);
    enqueue(&p, 4);
    enqueue(&p, 5);
    display(&p);
    printf("\n");
    if (isfull(&p) == 1)
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        printf("Queue is not full!\n");
    }
    printf("\n");
    dequeue(&p);
    display(&p);
    printf("\n");
    if (isempty(&p) == 1)
    {
        printf("Empty!\n");
    }
    else
    {
        printf("Not empty!\n");
    }
    if (isfull(&p) == 1)
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        printf("Queue is not full!\n");
    }
    printf("First element is %d.\n", first(&p));
    printf("Last element is %d.\n", last(&p));
}