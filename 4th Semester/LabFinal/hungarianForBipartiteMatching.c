#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX], n, m;
int Lmate[MAX], Rmate[MAX], dist[MAX], pred[MAX];

int dfs(int u)
{
    if (u == -1)
        return 1;
    for (int v = 0; v < m; v++)
    {
        if (graph[u][v] && dist[v] == -1)
        {
            dist[v] = dist[pred[u]] + 1;
            if (Rmate[v] == -1 || dfs(Rmate[v]))
            {
                Lmate[u] = v;
                Rmate[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void hungarianAlgorithm()
{
    int matches = 0;
    for (int i = 0; i < n; i++)
    {
        Lmate[i] = -1;
    }
    for (int j = 0; j < m; j++)
    {
        Rmate[j] = -1;
    }
    while (1)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (Lmate[i] == -1)
            {
                for (int j = 0; j < m; j++)
                {
                    dist[j] = -1;
                    pred[j] = -1;
                }
                if (dfs(i))
                {
                    found = 1;
                    matches++;
                }
            }
        }
        if (matches == n)
            break;
    }
    printf("Maximum matching is: %d\n", matches);
}

int main()
{
    printf("Enter the number of left vertices: ");
    scanf("%d", &n);
    printf("Enter the number of right vertices: ");
    scanf("%d", &m);

    printf("Enter the bipartite graph adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    hungarianAlgorithm();
    return 0;
}
