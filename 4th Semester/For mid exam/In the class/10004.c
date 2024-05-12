#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

static const int BLACK = 0;
static const int WHITE = 1;
static const int UNKNOWN = 2;
int i;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        int G[MAX_NODES][MAX_NODES];
        int color[MAX_NODES];
        bool isBipartite = true;

        for (i = 0; i < n; ++i)
        {
            color[i] = UNKNOWN;
            int j;
            for (j = 0; j < n; ++j)
                G[i][j] = 0;
        }

        int l;
        scanf("%d", &l);
        while (l--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u][v] = 1;
            G[v][u] = 1;
        }

        int queue[MAX_NODES];
        int front = 0, rear = 0;
        color[0] = BLACK;
        queue[rear++] = 0;
        while (front != rear && isBipartite)
        {
            int u = queue[front++];
            for (i = 0; i < n; ++i)
            {
                if (G[u][i] == 1)
                {
                    int v = i;
                    if (color[v] == color[u])
                    {
                        isBipartite = false;
                        break;
                    }
                    else if (color[v] == UNKNOWN)
                    {
                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    }
                }
            }
        }
        if (isBipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
