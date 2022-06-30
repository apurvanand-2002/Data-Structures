#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front, rear;
    int *A;
};
void create(struct queue *q)
{
    (*(q)).size = 100;
    (*(q)).front = (*(q)).rear = (-1);
    (*(q)).A = (int *)malloc((*(q)).size * sizeof(int));
}
void enqueue(struct queue *q, int num)
{
    if ((*(q)).rear == (*(q)).size - 1)
    {
        printf("Queue is full!");
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
        (*(q)).front++; // at front no value is stored.
        x = (*(q)).A[(*(q)).front];
        return x;
    }
}
int isempty(struct queue *q)
{
    if ((*(q)).front == (*(q)).rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BFS(struct queue *q, int A[][8], int head, int n)
{
    int visited[8] = {0};
    printf("%d ", head);
    visited[head] = 1;
    enqueue(q, head);
    int u, v;
    while (isempty(q) != 1)
    {
        u = dequeue(q);
        for (v = 1; v < n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                enqueue(q, v);
            }
        }
    }
}
int main()
{
    struct queue q;
    create(&q);
    int M[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    BFS(&q, M, 6, 8);
}