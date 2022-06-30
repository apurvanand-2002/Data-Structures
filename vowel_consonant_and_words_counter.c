#include <stdio.h>
#include <string.h>
int vowel(char *P)
{
    static int count = 0;
    static int ccount = 0;
    for (int i = 0; (*(P + i)) != '\0'; i++)
    {
        if ((*(P + i)) == 'a' || (*(P + i)) == 'e' || (*(P + i)) == 'i' || (*(P + i)) == 'o' || (*(P + i)) == 'u' || (*(P + i)) == 'A' || (*(P + i)) == 'E' || (*(P + i)) == 'I' || (*(P + i)) == 'O' || (*(P + i)) == 'U')
        {
            count++;
        }
        else if (65 <= (*(P + i)) && (*(P + i)) <= 90 || 97 <= (*(P + i)) && (*(P + i)) <= 122)
        {
            ccount++;
        }
    }
    printf("Vowels=%d Consonants=%d\n", count, ccount);
}
void word(char *A)
{
    static int count = 0;
    for (int i = 0; (*(A + i)) != '\0'; i++)
    {
        if ((*(A + i)) == ' ' && (*(A + i - 1)) != ' ')
        {
            count++;
        }
    }
    printf("Number of words:%d\n", count + 1);
}
int main()
{
    printf("Enter a string:\n");
    char A[100];
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    vowel(&A[0]);
    word(&A[0]);
}