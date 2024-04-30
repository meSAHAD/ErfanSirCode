#include <stdio.h>
#include <stdlib.h>

#define UNVISITED -1
#define MAX_NODES 2001

int scc;
int counter;
int dfs_low[MAX_NODES];
int dfs_num[MAX_NODES];
int adj[MAX_NODES][MAX_NODES];

void findStronglyConnectedComponents(int u, int n)
{
    dfs_low[u] = counter;
    dfs_num[u] = counter++;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[u][i])
        {
            int v = i;
            if (dfs_num[v] == UNVISITED)
                findStronglyConnectedComponents(v, n);
            if (dfs_num[v] != UNVISITED)
                dfs_low[u] = dfs_low[u] < dfs_low[v] ? dfs_low[u] : dfs_low[v];
        }
    }
    if (dfs_num[u] == dfs_low[u])
        ++scc;
    return;
}

int main(void)
{
    int m;
    int n;
    while (scanf("%d %d", &n, &m) && (n || m))
    {
        for (int i = 1; i <= n; ++i)
        {
            dfs_low[i] = UNVISITED;
            dfs_num[i] = UNVISITED;
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int a, b, ways;
            scanf("%d %d %d", &a, &b, &ways);
            adj[a][b] = 1;
            if (ways == 2)
                adj[b][a] = 1;
        }
        scc = 0;
        counter = 1;
        findStronglyConnectedComponents(1, n);
        for (int i = 2; i <= n; ++i)
        {
            if (dfs_num[i] == UNVISITED)
            {
                scc = 0;
                break;
            }
        }
        if (scc == 1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
