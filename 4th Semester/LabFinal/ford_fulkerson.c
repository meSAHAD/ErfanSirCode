#include <stdio.h>
#include <limits.h>

#define V 6

int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}};

int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                queue[rear++] = v;
                visited[v] = 1;
                parent[v] = u;
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int rGraph[V][V], parent[V];
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = (pathFlow < rGraph[u][v]) ? pathFlow : rGraph[u][v];
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main()
{
    printf("The maximum flow is %d\n", fordFulkerson(graph, 0, 5));
    return 0;
}
