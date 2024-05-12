#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 32
#define MAX_EDGES 100

int adjacency[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void bfs(int start, int ttl, int nodes);

int main()
{
    int edge, a, b, strt, ttl, cse = 1;

    while (scanf("%d", &edge) && edge)
    {
        memset(adjacency, 0, sizeof(adjacency));
        memset(visited, 0, sizeof(visited));
        int c = 0;

        for (int i = 0; i < edge; i++)
        {
            scanf("%d %d", &a, &b);

            if (!visited[a])
            {
                visited[a] = ++c;
            }
            if (!visited[b])
            {
                visited[b] = ++c;
            }

            adjacency[visited[a]][visited[b]] = 1;
            adjacency[visited[b]][visited[a]] = 1;
        }

        while (scanf("%d %d", &strt, &ttl) == 2)
        {
            if (strt == 0 && ttl == 0)
                break;

            printf("Case %d: ", cse++);

            int start = visited[strt];
            int reachable = 0;

            for (int i = 1; i <= c; i++)
            {
                if (i != start && adjacency[start][i])
                {
                    bfs(i, ttl, c);
                    reachable++;
                }
            }

            int unreachable = c - reachable - 1;
            printf("%d nodes not reachable from node %d with TTL = %d.\n", unreachable, strt, ttl);
        }
    }

    return 0;
}

void bfs(int start, int ttl, int nodes)
{
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int visited[MAX_NODES] = {0};
    int level[MAX_NODES] = {0};

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int current = queue[front++];

        for (int i = 1; i <= nodes; i++)
        {
            if (adjacency[current][i] && !visited[i])
            {
                visited[i] = 1;
                level[i] = level[current] + 1;
                queue[rear++] = i;
            }
        }
    }
}
