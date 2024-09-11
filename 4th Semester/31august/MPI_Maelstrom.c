#include <stdio.h>
#include <limits.h> 
#define inf 1000000000

int main()
{
    int n;
    int i, j, k, graph[105][105], x;

    while (scanf("%d", &n) == 1)
    {
        for (i = 0; i < n; i++)
            graph[i][i] = inf;

        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (scanf("%d", &x) == 1)
                    graph[i][j] = graph[j][i] = x;
                else
                    graph[i][j] = graph[j][i] = inf, scanf("%*c");
            }
        }

        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (graph[i][k] != inf && graph[k][j] != inf) 
                        graph[i][j] = (graph[i][j] < graph[i][k] + graph[k][j]) ? graph[i][j] : graph[i][k] + graph[k][j];
                }
            }
        }

        int ans = 0;
        for (i = 1; i < n; i++)
            if (graph[0][i] != inf) 
                ans = (ans > graph[0][i]) ? ans : graph[0][i];

        printf("%d\n", ans);
    }

    return 0;
}
