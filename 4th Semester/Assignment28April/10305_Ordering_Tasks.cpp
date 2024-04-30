#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

int *discovered;
int **adjList;
int *topoSort;
int topoSortIndex = 0;

void dfs(int u)
{
    discovered[u] = 1;
    for (int i = 0; i < adjList[u][0]; ++i)
    {
        int v = adjList[u][i + 1];
        if (!discovered[v])
        {
            dfs(v);
        }
    }
    topoSort[topoSortIndex++] = u;
}

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0))
    {
        discovered = (int *)calloc(n + 1, sizeof(int));
        adjList = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 1; i <= n; ++i)
        {
            adjList[i] = (int *)malloc(1 * sizeof(int));
            adjList[i][0] = 0;
        }
        topoSort = (int *)malloc(n * sizeof(int));
        topoSortIndex = 0;

        int u, v;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &u, &v);
            adjList[u] = (int *)realloc(adjList[u], (adjList[u][0] + 2) * sizeof(int));
            adjList[u][adjList[u][0] + 1] = v;
            adjList[u][0]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!discovered[i])
            {
                dfs(i);
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            printf("%d", topoSort[i]);
            if (i)
                printf(" ");
        }
        printf("\n");

        free(discovered);
        for (int i = 1; i <= n; ++i)
        {
            free(adjList[i]);
        }
        free(adjList);
        free(topoSort);
    }

    return 0;
}
