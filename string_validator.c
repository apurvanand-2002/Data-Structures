#include <stdio.h>
#include <string.h>
int valid(char *A)
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] < 48 || (A[i] > 57 && A[i] < 65) || (A[i] > 90 && A[i] < 97) || A[i] > 122)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char A[100];
    printf("Enter the string to be validated:\n");
    gets(A);
    printf("Entered string is :\n");
    puts(A);
    if (valid(&A[0]) == 1)
    {
        printf("Is Valid!\n");
    }
    else
    {
        printf("Is Invalid!\n");
    }
}