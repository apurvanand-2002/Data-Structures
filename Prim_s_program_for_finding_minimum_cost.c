#include <stdio.h>
#include <limits.h>
#define I INT_MAX
int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I},
};
int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6];
int main()
{
    int i, j, u, v;
    int min = I;
    static int k;
    for (i = 1; i < 8; i++)
    {
        for (j = i; j < 8; j++)
        {
            if (min > cost[i][j])
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i < 8; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    for (j = 1; j < 6; j++)
    {
        min = I;
        for (i = 1; i < 8; i++)
        {
            if (near[i] != 0 && cost[i][near[i]] < min)
            {
                min = cost[i][near[i]];
                k = i;
            }
        }
        t[0][j] = k;
        t[1][j] = near[k];
        near[k] = 0;

        for (i = 1; i < 8; i++)
        {
            if (near[i] != 0 && cost[i][near[i]] > cost[i][k])
            {
                near[i] = k;
            }
        }
    }

    for (i = 0; i < 6; i++)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }
}
/*Remembering method:NTPC
N:near
T=t matrix
P:Prim
C:Cost*/