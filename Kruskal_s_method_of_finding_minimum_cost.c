#include <stdio.h>
#include <limits.h>
#define I INT_MAX
int t[2][6]; // final matrix
int cost[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                  {2, 6, 3, 7, 4, 5, 7, 6, 7},
                  {25, 5, 12, 10, 8, 16, 14, 20, 18}};
int set[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
static int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
// cost,set and included have same no. of columns
void set_union(int u, int v, int s[])
{
    if (s[u] < s[v])
    {
        s[u] = s[u] + s[v];
        s[v] = u;
    }
    else
    {
        s[v] = s[v] + s[u];
        s[u] = v;
    }
}
int set_find(int num, int s[])
{
    int x = num;
    while (s[x] > 0)
    {
        x = s[x];
    }
    return x;
}
int main()
{
    int i = 0, j, n = 7, e = 9, u, v;
    static int k = 0; // n=no. of vertices, e=number of edges
    while (i < (n - 1))
    { //'i' traverses through 't' i.e. final matrix
        int min = I;
        for (j = 1; j < e; j++)
        { //'j' traverse through cost matrix
            if (included[j] == 0 && cost[2][j] < min)
            {
                min = cost[2][j];
                k = j;
                u = cost[0][j];
                v = cost[1][j];
            }
        }
        if (set_find(u, set) != set_find(v, set)) // different parents,no cycling,independent
        {
            t[0][i] = u;
            t[1][i] = v;
            set_union(set_find(u, set), set_find(v, set), set);
            /*union of parents is to be done.*/
            i++;
        }
        included[k] = 1;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }
}
/*Remember: t-sick
t:t matrix
s:set
i:included
c:cost*/