#include <stdio.h>
void DFS(int M[][8], int head, int n)
{
    static int visited[8] = {0}; /*Static keyword is necessary as function is being called
       recursively ,so, visited array must be maintained and not created again and again.*/
    if (visited[head] == 0)
    {
        int u = head;
        printf("%d ", head);
        visited[head] = 1;
        for (int v = 1; v < n; v++)
        {
            if (M[u][v] == 1 && visited[v] != 1)
            {
                DFS(M, v, 8);
            }
        }
    }
}
int main()
{
    int M[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    DFS(M, 2, 8);
}
/*DFS can be calculated manually using stack, we can create a tree like structure of the
graph and its pre-order traversal will give order of DFS.*/