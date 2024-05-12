#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 2005

int canTravelTo[MAX_NODES][MAX_NODES];
int dfs_num[MAX_NODES];
int dfs_low[MAX_NODES];
bool visited[MAX_NODES];
int dfsNumberCounter;

// Need everything to be in one SCC
bool IsInOneSCC(int u, int N)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    visited[u] = true;

    for (int i = 0; i < N; ++i)
    {
        if (canTravelTo[u][i] == 1)
        {
            int adj = i;
            if (dfs_num[adj] == -1)
            {
                if (!IsInOneSCC(adj, N))
                    return false;
            }

            if (visited[adj])
                dfs_low[u] = (dfs_low[u] < dfs_low[adj]) ? dfs_low[u] : dfs_low[adj];
        }
    }

    if (dfs_low[u] == dfs_num[u] && u != 0)
        return false;

    return true;
}

bool AllVisited(int N)
{
    for (int i = 0; i < N; ++i)
        if (!visited[i])
            return false;

    return true;
}

int main()
{
    int N, M;

    while (scanf("%d %d", &N, &M) == 2 && N)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                canTravelTo[i][j] = 0;
            dfs_num[i] = -1;
            visited[i] = false;
        }

        while (M--)
        {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            --V;
            --W;
            canTravelTo[V][W] = 1;
            if (P == 2)
                canTravelTo[W][V] = 1;
        }

        dfsNumberCounter = 0;
        if (IsInOneSCC(0, N) && AllVisited(N))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
