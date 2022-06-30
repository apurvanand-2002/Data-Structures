#include <stdio.h>
#include <string.h>
int main()
{
    char A[100];
    printf("Enter a string:\n");
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    int h[26];
    for (int i = 0; i < 26; i++)
    {
        h[i] = 0;
    }
    for (int i = 0; A[i] != '\0'; i++)
    {
        int c = A[i] - 97;
        h[c]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (h[i] > 1)
        {
            printf("%c frequency:%d\n", (i + 97), h[i]);
        }
    }
}