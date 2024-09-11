#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 105

int graph[MAX][MAX];
int n;

void floyd_warshall()
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][k] != INF && graph[k][j] != INF)
                {
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    int ts, t;
    scanf("%d", &ts);
    for (t = 1; t <= ts; t++)
    {
        scanf("%d", &n);
        int m, i, j;
        scanf("%d", &m);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    graph[i][j] = INF;
                else
                    graph[i][j] = 0;
            }
        }

        int sum = -1, s, d;
        for (i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = 1;
        }
        scanf("%d %d", &s, &d);
        floyd_warshall();

        for (i = 0; i < n; i++)
        {
            if (graph[s][i] != INF && graph[i][d] != INF)
            {
                if (sum < graph[s][i] + graph[i][d])
                {
                    sum = graph[s][i] + graph[i][d];
                }
            }
        }

        printf("Case %d: %d\n", t, sum);
    }

    return 0;
}
