#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999999

typedef struct
{
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    return find(parent[i]);
}

void Union(int x, int y)
{
    parent[x] = y;
}

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int kruskal(int n, int m)
{
    qsort(edges, m, sizeof(Edge), compare);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int mstWeight = 0;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v)
        {
            Union(u, v);
            mstWeight += edges[i].weight;
            count++;
        }

        if (count == n - 1)
            break;
    }

    return mstWeight;
}

int main()
{
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    printf("The weight of the Minimum Spanning Tree is: %d\n", kruskal(n, m));
    return 0;
}
