#include <stdio.h>
#include <string.h>
int isanagram(int H[])
{
    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char A[20], B[20];
    int H[26];
    printf("Enter first string:\n");
    gets(A);
    printf("First string is:\n");
    puts(A);
    printf("Enter second string:\n");
    gets(B);
    printf("Second string is:\n");
    puts(B);
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--;
    }
    if (isanagram(H) == 1)
    {
        printf("IS ANAGRAM\n");
    }
    else
    {
        printf("NOT AN ANAGRAM\n");
    }
}