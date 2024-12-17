#include <stdio.h>
#include <limits.h>

#define V 4
#define INF 999999

struct Edge
{
    int u, v, weight;
};

struct Edge edges[] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
int graph[V][V];
int dist[V];

int bellmanFord(int graph[V][V], int s, int dist[])
{
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    return 0;
}

void johnsonAlgorithm(int graph[V][V])
{
    int newGraph[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            newGraph[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < V; i++)
        bellmanFord(newGraph, i, dist);

    printf("Shortest Paths Between All Pairs of Vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("Distance from %d to %d is %d\n", i, j, dist[j]);
        }
    }
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;
        graph[u][v] = w;
    }

    johnsonAlgorithm(graph);

    return 0;
}
