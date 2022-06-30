#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;
void enqueue(int num)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Queue is full!\n");
    }
    else
    {
        (*(t)).data = num;
        if (front == NULL)
        {
            front = rear = t;
            (*(t)).next = NULL;
        }
        else
        {
            (*(rear)).next = t;
            rear = t;
            (*(t)).next = NULL;
        }
    }
}
int dequeue()
{
    if (front == rear)
    {
        printf("Queue is empty.\n");
        return (-1);
    }
    else
    {
        struct node *t;
        t = front;
        int x;
        x = (*(t)).data;
        front = (*(front)).next;
        free(t);
        return x;
    }
}
/*In queue, 'deletion' occurs from 'front end' and 'insertion' occurs from 'rear end'.*/
int isempty()
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BFS(int M[][8], int head, int n)
{
    int visited[8] = {0};
    printf("%d ", head);
    visited[head] = 1;
    enqueue(head);
    while (isempty() != 1)
    {
        for (int v = 1; v < n; v++)
        {
            int u = dequeue();
            if (M[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}
int main()
{
    int M[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    BFS(M, 1, 8);
}