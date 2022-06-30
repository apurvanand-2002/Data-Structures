/*For printing all the permutations, we need to do back-tracking using recursion
and this process of getting all the output is called 'Brute Force'.*/
#include <stdio.h>
#include <string.h>
void permutation(char S[], int k)
{
    static int A[15] = {0};
    static char R[15];
    if (S[k] == '\0')
    {
        R[k] = '\0';
        puts(R);
    }
    else
    {
        for (int i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                R[k] = S[i];
                A[i] = 1;
                permutation(S, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    char A[15];
    printf("Enter string:\n");
    gets(A);
    printf("Entered string is:\n");
    puts(A);
    printf("All permutations are:\n");
    permutation(A, 0);
}