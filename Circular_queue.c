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
    printf("Enter size of queue:\n");
    scanf("%d", &(*(q)).size);
    (*(q)).front = (*(q)).rear = 0;
    (*(q)).A = (int *)malloc((*(q)).size * sizeof(int));
}
void enqueue(struct queue *q, int num)
{
    if ((*(q)).front == ((*(q)).rear + 1) % (*(q)).size)
    {
        printf("Queue is full!\n");
    }
    else
    {
        (*(q)).rear = ((*(q)).rear + 1) % (*(q)).size;
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
        (*(q)).front = ((*(q)).front + 1) % (*(q)).size;
        x = (*(q)).A[(*(q)).front];
        return x;
    }
}
void display(struct queue *q)
{
    if ((*(q)).front == (*(q)).rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int a = (*(q)).front + 1;
        while (a != ((*(q)).rear + 1) % (*(q)).size)
        {
            printf("%d ", (*(q)).A[a]);
            a = (a + 1) % (*(q)).size;
        }
    }
}
int main()
{
    struct queue q;
    create(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);
}