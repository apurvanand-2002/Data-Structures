#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Entered elements are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    free(p); // to prevent memory leak.
    p = NULL;
}