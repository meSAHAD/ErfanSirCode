#include <stdio.h>
#include <limits.h>

#define V 5

int graph[V][V] = {{0, 2, 0, 6, 0},
                   {2, 0, 3, 8, 5},
                   {0, 3, 0, 0, 7},
                   {6, 8, 0, 0, 9},
                   {0, 5, 7, 9, 0}};

int primMST(int graph[V][V])
{
    int key[V], parent[V], mstSet[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int mstWeight = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d: %d\n", parent[i], i, graph[i][parent[i]]);
        mstWeight += graph[i][parent[i]];
    }

    return mstWeight;
}

int main()
{
    printf("The weight of the Minimum Spanning Tree is: %d\n", primMST(graph));
    return 0;
}
