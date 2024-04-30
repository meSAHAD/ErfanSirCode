#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

void dfs(int v, int V)
{
    visited[v] = 1;
    for (int i = 0; i < V; ++i)
    {
        if (adj[v][i] && !visited[i])
        {
            dfs(i, V);
        }
    }
    stack[++top] = v;
}

void topologicalSort(int V)
{
    // for (int i = 0; i < V; ++i)
    // {
    //     visited[i] = 0;
    // }
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            dfs(i, V);
        }
    }
    printf("Topological sorting of the graph: ");
    for (; top >= 0; top--)
    {
        printf("%d ", stack[top]);
    }
}

int main()
{
    freopen("dfsinput.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}

