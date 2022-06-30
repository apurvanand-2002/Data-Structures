#include <stdio.h>
#include <string.h>
void swap(char *A, char *B)
{
    int temp;
    temp = (*(A));
    (*(A)) = (*(B));
    (*(B)) = temp;
}
void reverse(char *A)
{
    static int i = 0, k = 0;
    static int j = 0;
    for (k = 0; (*(A + k)) != '\0'; k++)
    {
    }
    j = k - 1;
    for (; i < j; i++, j--)
    {
        swap(&(*(A + i)), &(*(A + j)));
    }
}
int main()
{
    char A[200];
    printf("Enter a string:\n");
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    reverse(&A[0]);
    printf("Reversed:\n");
    puts(A);
}