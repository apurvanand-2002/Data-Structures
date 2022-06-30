/*Heap is a complete tree but unlike,binary search tree ,a heap is of 2 types:
1.Max Heap 2.Min heap
Max heap has all elements smaller than the root node.And traversal takes place from
one level to another ,hence, for any type of operation time complexity is of order
nlog(n).*/
#include <stdio.h>
void insert(int A[], int n)
{
    int temp;
    int i = n;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = (i / 2);
    }
    A[i] = temp;
}
void create(int A[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        insert(A, i);
    }
}
/*In heap, delete function deletes only the root or top node of the heap. And it is
replaced by the last and rightmost element of the heap as that is usually considered to
be the smallest.*/
int delete (int A[], int n)
{
    int val;
    val = A[1];
    A[1] = A[n]; // entered last element of the heap.
    A[n] = val;
    int i = 1, j = (2 * i);

    while (j < (n - 1))
    {
        if (A[j + 1] > A[j])
        {
            j = (j + 1);
        }
        if (A[j] > A[i])
        {
            int temp;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i = j;
            j = (2 * i);
        }
        else
        {
            break;
        }
    }
    return val;
}
int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    create(H, 7);
    for (int i = 7; i >= 1; i--)
    {
        printf("%d ", delete (H, i));
    }
    printf("\n");
    for (int i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
}
/*Heap is best for implementing priority queues.
If we consider that Maximum has more priority then max heap will help.
And if we consider, minimum has more priority then min heap will help. */