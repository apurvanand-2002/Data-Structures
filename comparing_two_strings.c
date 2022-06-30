#include <stdio.h>
#include <string.h>
void compare(char *A, char *B)
{
    int i = 0, j = 0;
    for (; (*(A + i)) != '\0' || (*(B + j)) != '\0'; i++, j++)
    {
        if ((*(A + i)) != (*(B + j)))
        {
            break;
        }
    }
    if ((*(A + i)) > (*(B + j)))
    {
        printf("First is greater.\n");
    }
    else if ((*(A + i)) < (*(B + j)))
    {
        printf("Second is greater.\n");
    }
    else
    {
        printf("The string are same.\n");
    }
}
int main()
{
    char A[200], B[200];
    printf("Enter first string:\n");
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    printf("Enter second string:\n");
    gets(B);
    printf("Entered string is:\n");
    puts(B);
    compare(&A[0], &B[0]);
}