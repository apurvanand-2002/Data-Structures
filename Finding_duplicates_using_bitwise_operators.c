#include <stdio.h>
#include <string.h>
int main()
{
    char A[15];
    printf("Enter a string:\n");
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    long int h = 0;
    int x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        if ((x & h) > 0)
        {
            printf("%c is a duplicate.\n", A[i]);
        }
        else
        {
            h = h | x;
        }
    }
}