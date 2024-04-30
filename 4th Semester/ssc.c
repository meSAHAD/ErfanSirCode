#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 105

bool dfs(int curr, int des, int adj[MAX_NODES][MAX_NODES], int vis[MAX_NODES])
{
    if (curr == des)
    {
        return true;
    }
    vis[curr] = 1;
    for (int i = 0; i < MAX_NODES; ++i)
    {
        if (!vis[i] && adj[curr][i])
        {
            if (dfs(i, des, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

bool isPath(int src, int des, int adj[MAX_NODES][MAX_NODES])
{
    int vis[MAX_NODES] = {0};
    return dfs(src, des, adj, vis);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void findSCC(int n, int a[][2])
{
    int adj[MAX_NODES][MAX_NODES] = {0};
    int is_scc[MAX_NODES] = {0};
    int ans[MAX_NODES][MAX_NODES];
    int ansCount = 0;

    for (int i = 0; i < n; ++i)
    {
        adj[a[i][0]][a[i][1]] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!is_scc[i])
        {
            int scc[MAX_NODES];
            int sccCount = 0;
            scc[sccCount++] = i;
            for (int j = i + 1; j <= n; ++j)
            {
                if (!is_scc[j] && isPath(i, j, adj) && isPath(j, i, adj))
                {
                    is_scc[j] = 1;
                    scc[sccCount++] = j;
                }
            }
            qsort(scc, sccCount, sizeof(int), compare);
            for (int k = 0; k < sccCount; ++k)
            {
                ans[ansCount][k] = scc[k];
            }
            ansCount++;
        }
    }

    printf("Strongly Connected Components are:\n");
    for (int i = 0; i < ansCount; ++i)
    {
        for (int j = 0; j < MAX_NODES; ++j)
        {
            if (ans[i][j] != 0)
            {
                printf("%d ", ans[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    int edges[][2] = {
        {1, 3}, {1, 4}, {2, 1}, {3, 2}, {4, 5}};
    findSCC(V, edges);
    return 0;
}
