#include <stdio.h>
#define size 10
int hash_function_1(int H[], int num)
{
    return num % 10;
}
int hash_function_2(int H[], int num)
{
    return (7 - (num % 7));
}
void insert(int A[], int num)
{
    int index = hash_function_1(A, num);
    static int i = 0;
    if (A[index] == 0)
    {
        A[index] = num;
    }
    else
    {
        while (A[((hash_function_1(A, num)) + i * (hash_function_2(A, num))) % 10] != 0)
        {
            i++;
        }
        A[((hash_function_1(A, num)) + i * (hash_function_2(A, num))) % 10] = num;
    }
}
int search(int A[], int num)
{
    int index = hash_function_1(A, num);
    static int i = 0;
    if (A[index] == num)
    {
        return index;
    }
    else
    {
        while (A[((hash_function_1(A, num)) + i * (hash_function_2(A, num))) % 10] != num)
        {
            if (A[((hash_function_1(A, num)) + i * (hash_function_2(A, num))) % 10] == 0)
            {
                return (-1);
            }
            i++;
        }
        return ((hash_function_1(A, num)) + i * (hash_function_2(A, num))) % 10;
    }
}
int main()
{
    int HT[10] = {0};
    insert(HT, 5);
    insert(HT, 25);
    insert(HT, 15);
    insert(HT, 35);
    insert(HT, 95);
    printf("Key is present at %d.\n", search(HT, 85));
}