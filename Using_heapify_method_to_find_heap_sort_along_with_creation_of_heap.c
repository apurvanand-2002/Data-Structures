#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = (*(a));
    (*(a)) = (*(b));
    (*(b)) = temp;
}
void heapify(int A[], int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1; // as arrays start from 0
    int h = (2 * i) + 2; // as arrays start from 0
    if (l < n && A[l] > A[largest])
    {
        largest = l;
    }
    if (h < n && A[h] > A[largest])
    {
        largest = h;
    }
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}
void buildheap(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }
}
void heap_sort(int A[], int n)
{
    for (int i = (n - 1); i >= 0; i--)
    {
        swap(&A[0], &A[i]);
        heapify(A, i - 1, 0);
    }
}
int main()
{
    int A[] = {100, 30, 50, 200, 35, 15};
    buildheap(A, 6);
    heap_sort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
}