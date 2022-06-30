#include <stdio.h>
#include <string.h>
void atoi(char *A, int *B)
{
    for (int i = 0; i < strlen(A); i++)
    {
        (*(B + i)) = (*(A + i)) - '0';
    }
}
int main()
{
    printf("Enter a numerical string:\n");
    char A[50];
    gets(A);
    printf("Numerical string entered is:\n");
    puts(A);
    int B[50];
    atoi(&A[0], &B[0]);
    for (int i = 0; i < strlen(A); i++)
    {
        printf("%d", B[i]);
    }
}