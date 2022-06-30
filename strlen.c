#include <stdio.h>
#include <string.h>
int main()
{
    char A[] = {'A', 'p', 'u', 'r', 'v', ' ', 'A', 'n', 'a', 'n', 'd', '\0'};
    printf("%d", strlen(A));
    static int count = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        count++;
    }
    printf("\nLength of string is %d.\n", count);
    // char A[40];
    // printf("Enter a string:\n");
    // scanf("%s", A);
    // printf("%s", A);
    //  getchar();
    //  char B[50];
    //  gets(B);
    //  puts(B);
}