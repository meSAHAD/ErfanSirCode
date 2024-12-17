#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

typedef struct
{
    int src, dest, weight;
} Edge;

Edge edges[E];

void bellmanFord(int graph[V][V], int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dist[edges[j].src] != INT_MAX &&
                dist[edges[j].src] + edges[j].weight < dist[edges[j].dest])
            {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }
}

int main()
{
    edges[0] = (Edge){0, 1, -1};
    edges[1] = (Edge){0, 2, 4};
    edges[2] = (Edge){1, 2, 3};
    edges[3] = (Edge){1, 3, 2};
    edges[4] = (Edge){1, 4, 2};
    edges[5] = (Edge){3, 2, 5};
    edges[6] = (Edge){3, 1, 1};
    edges[7] = (Edge){4, 3, -3};

    bellmanFord(edges, 0);
    return 0;
}
