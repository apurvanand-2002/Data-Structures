#include <stdio.h>
#include <string.h>
int main()
{
    char A[50];
    printf("Enter the string:\n");
    gets(A);
    printf("\nEntered string is:\n");
    puts(A);
    printf("%d", strlen(A));
    for (int i = 0; i < strlen(A); i++)
    {
        if (65 <= A[i] && A[i] <= 90)
        {
            A[i] = A[i] + 32;
        }
        else if (97 <= A[i] && A[i] <= 122)
        {
            A[i] = A[i] - 32;
        }
    }
    printf("\nAfter changing the case:\n");
    for (int i = 0; i < strlen(A); i++)
    {
        printf("%c", A[i]);
    }
}