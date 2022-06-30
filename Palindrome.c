#include <stdio.h>
#include <string.h>
int isPalindrome(char *A)
{
    int i = 0;
    int j = 0, k = 0;
    for (; (*(A + k)) != '\0'; k++)
    {
    }
    j = k - 1;
    for (; i < j; i++, j--)
    {
        if ((*(A + i)) != (*(A + j)))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char A[100];
    printf("Enter First string:\n");
    gets(A);
    printf("First string is:\n");
    puts(A);
    if (isPalindrome(&A[0]) == 1)
    {
        printf("Is a Paindrome!");
    }
    else
    {
        printf("Not a Palindrome!");
    }
}