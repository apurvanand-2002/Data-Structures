#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    printf("Enter elements for p:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (p + i));
    }
    int *q;
    q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*(p + i)));
    }
}